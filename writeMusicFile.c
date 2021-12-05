/**
 * @file writeMusicFile.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implementation of writeMusicFile.h file.
 * @version 0.1
 * @date 2021-11-25 
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas, Lampros Dionysiou.
 * This file is part of WAV Engine.
 * WAV Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * Υou should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 */
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
