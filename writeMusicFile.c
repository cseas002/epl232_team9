#include "writeMusicFile.h"

void freeMusicFile(MUSIC_FILE *musicFile)
{
    if(!musicFile) return;
    if(!musicFile->riff) free(musicFile->riff);
    if(!musicFile->fmtSub) free(musicFile->fmtSub);
    if(!musicFile->dataSub)free(musicFile->dataSub);
    if(!musicFile->data)free(musicFile->data);
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
    if(fwrite(musicFile->riff, sizeof(RIFF), 1, fp)!=1){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fwrite(musicFile->fmtSub, sizeof(FMT_SUB), 1, fp)!=1){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fwrite(musicFile->dataSub, sizeof(DATA_SUB), 1, fp)!=1){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fwrite(musicFile->data, sizeof(byte), musicFile->size, fp)!=musicFile->size){
        fclose(fp);
        return EXIT_FAILURE;
    }
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
    if (!newFileName){
        free(temp);
        return EXIT_FAILURE;
    }
    if (!strcpy(newFileName, addition)){
        free(temp);
        return EXIT_FAILURE;
    }
    if (!strcat(newFileName, changedFilename)){
        free(temp);
        return EXIT_FAILURE;
    }
    free(temp);
    return EXIT_SUCCESS;
}
