#include "changeSpeed.h"

int speedChange(char const* fileName, char* speedChange) {
    float speedChangeNum = atof(speedChange);
    if (speedChangeNum < 0) {
        printf("The speed must be a value greater than 0\n");
        return EXIT_FAILURE;
    }
    if (speedChangeNum >= 100000) {
        printf("The speed must be a value lower than 100000\n");
        return EXIT_FAILURE;
    }
    char* newFileName = (char*) malloc(strlen(fileName) + 27 * sizeof(char)); 
    // 99999-times-speed-changed-\0 is 27 characters
    MUSIC_FILE* musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    musicFile -> fmtSub -> sampleRate *= speedChangeNum; // changing speed
    // char* timesChanged = ;
    // speedChange = strcat(speedChange, "-times-speed-changed-");
    // printf("%s\n\n", fileName);

    if (changedName(newFileName, fileName, speedChange) == EXIT_FAILURE) return EXIT_FAILURE;
    if (writeFile(musicFile, newFileName) == EXIT_FAILURE) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}