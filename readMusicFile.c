/**
 * @file readMusicFile.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implementation of readMusicFile.h file.
 * @version 0.1
 * @date 2021-12-04
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
#include "readMusicFile.h"

int copyHeader(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile){
    if (!((newFile -> riff = (RIFF*) malloc(sizeof(RIFF))) &&
     (newFile -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB))) && 
     (newFile -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB))))) {
        printf("Cannot allocate space for reverse file\n");
        return EXIT_FAILURE;
    }
    *newFile->riff = *musicFile->riff;
    *newFile->fmtSub = *musicFile->fmtSub;
    *newFile->dataSub = *musicFile->dataSub;
    newFile->size = musicFile->size;
    return EXIT_SUCCESS;
}

int readHeaderAndData(MUSIC_FILE* musicFile, char const *fileName) {
    FILE* fp = NULL;
    if (!(fp = fopen(fileName, "rb"))) return EXIT_FAILURE;
    if (!(musicFile -> riff = (RIFF*) malloc(sizeof(RIFF)))) {
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fread(musicFile -> riff, sizeof(RIFF), 1, fp)!=1){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if (!(musicFile -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB)))){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fread(musicFile -> fmtSub, sizeof(FMT_SUB), 1, fp)!=1){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if (!(musicFile -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB)))){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fread(musicFile -> dataSub, sizeof(DATA_SUB), 1, fp)!=1){
        fclose(fp);
        return EXIT_FAILURE;
    }
    musicFile -> size = musicFile -> dataSub -> subChunk2Size;
    if (!(musicFile -> data = (byte*) malloc(musicFile -> size))){
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(fread(musicFile -> data, sizeof(byte), musicFile -> size, fp)!=musicFile->size){
        fclose(fp);
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_READ_MUSIC_FILE
int main()
{
    printf("Save the piano.wav file in the as4-supplementary sub folder in order to work!\n");
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    readHeaderAndData(musicFile, "./as4-supplementary/piano.wav");
    printf("Reading data from piano.wav file ...Done!\n");
    printf("The size of the wave file is %d bytes!\n", musicFile->size);
    return 0;
}
#endif
