#include "writeMusicFile.h"

void freeMusicFile(MUSIC_FILE *musicFile)
{
    free(musicFile->riff);
    free(musicFile->fmtSub);
    free(musicFile->dataSub);
    free(musicFile->data);
    free(musicFile);
}

int writeFile(MUSIC_FILE *musicFile, char const *newFileName)
{
    FILE *fp = NULL;
    if (!(fp = fopen(newFileName, "wb")))
    {
        printf("Cannot create new file\n");
        return EXIT_FAILURE;
    }

    // if (writeRiff(musicFile -> riff, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(musicFile->riff, sizeof(RIFF), 1, fp);
    fwrite(musicFile->fmtSub, sizeof(FMT_SUB), 1, fp);
    // if (writeDataSub(musicFile -> dataSub, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(musicFile->dataSub, sizeof(DATA_SUB), 1, fp);
    fwrite(musicFile->data, sizeof(byte), musicFile->size, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int changedName(char *newFileName, char const *fileName, char *addition)
{ // addition = "-mono", "-chop", etc.
    char *changedFilename = (char *)malloc(strlen(fileName) + 1);
    char *temp = changedFilename;
    if (strrchr(fileName, '/'))
    {
        changedFilename = strrchr(fileName, '/');
        if (changedFilename[0] == '/')
            changedFilename++;
    }
    else
        strcpy(changedFilename, fileName);
    if (!newFileName)
        return EXIT_FAILURE;
    if (!strcpy(newFileName, addition))
        return EXIT_FAILURE;
    if (!strcat(newFileName, changedFilename))
        return EXIT_FAILURE;
    free(temp);
    return EXIT_SUCCESS;
}
