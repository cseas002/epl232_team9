#include "changeSpeed.h"

int speedChange(char const *fileName, char *speedChange)
{
    float speedChangeNum = atof(speedChange);
    if (speedChangeNum <= 0)
    {
        printf("The speed must be a value greater than 0\n");
        return EXIT_FAILURE;
    }
    if (speedChangeNum >= 100000)
    {
        printf("The speed must be a value lower than 100000\n");
        return EXIT_FAILURE;
    }
    char *timesChanged = (char *)malloc((strlen(speedChange) + 22) * sizeof(char));
    // <strlen(speedChange)>-times-speed-changed-\0 is 22 characters + strlen(speedChange)
    strcpy(timesChanged, speedChange);
    strcat(timesChanged, "-times-speed-changed-");
    char *newFileName = (char *)malloc(strlen(fileName) + 1 + strlen(timesChanged));
    MUSIC_FILE *musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE *)malloc(sizeof(MUSIC_FILE))))
        return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE)
    {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    musicFile->fmtSub->sampleRate *= speedChangeNum; // changing speed

    if (changedName(newFileName, fileName, timesChanged) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (writeFile(musicFile, newFileName) == EXIT_FAILURE)
        return EXIT_FAILURE;
    free(newFileName);
    free(timesChanged);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}
