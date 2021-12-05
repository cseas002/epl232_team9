/**
 * @file stereoToMono.c
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implementation of stereoToMono.h file.
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Lampros Dionysiou.
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
#include "stereoToMono.h"

int changeHeader(MUSIC_FILE *newFile){
    newFile->dataSub->subChunk2Size = newFile->dataSub->subChunk2Size/2;
    newFile->size = newFile->size/2;
    newFile->riff->chunkSize = newFile->size+36;
    newFile->fmtSub->numChannels = 1;
    newFile->fmtSub->byteRate = newFile->fmtSub->sampleRate * newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    newFile->fmtSub->blockAlign = newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    newFile->dataSub->subChunk2Size = newFile->size * newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    return EXIT_SUCCESS;
}

int changeData(MUSIC_FILE *musicFile, MUSIC_FILE *newFile){
    if(musicFile->fmtSub->bitsPerSample == 8)
        for(long i = 0, j=0; i < newFile->size; i++, j+=2)
            newFile->data[i] = musicFile->data[j];
    else
        for(long i = 0, j=0; i < newFile->size; i+=2, j+=4){
            newFile->data[i] = musicFile->data[j];
            newFile->data[i+1] = musicFile->data[j+1];
        }
    return EXIT_SUCCESS;
}

int saveToFile(MUSIC_FILE *newFile, char const *filename){
    char *newFileName = (char*) malloc(strlen(filename)+6);
    if(changedName(newFileName, filename, "mono-")==EXIT_FAILURE) {
        free(newFileName);
        return EXIT_FAILURE;
    }
    writeFile(newFile, newFileName);
    free(newFileName);
    return EXIT_SUCCESS;
}

int stereoToMono(char const *fileName){
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if(!musicFile || !fileName) return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) return EXIT_FAILURE;
    if(musicFile->fmtSub->numChannels ==1 ){
        printf("WAV File is already Mono.");
        return EXIT_FAILURE;
    }
    MUSIC_FILE *newFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if (!newFile){
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    //Header
    if(copyHeader(musicFile, newFile) || changeHeader(newFile)) {
        freeMusicFile(musicFile);
        freeMusicFile(newFile);
        return EXIT_FAILURE;
    }
    //Data
    newFile->data = (byte*) malloc(newFile->size);
    if(!newFile->data || changeData(musicFile, newFile)){
        freeMusicFile(musicFile);
        freeMusicFile(newFile);
        return EXIT_FAILURE;
    }
    //Save to file
    if(saveToFile(newFile, fileName)){
        freeMusicFile(musicFile);
        freeMusicFile(newFile);
        return EXIT_FAILURE;
    }
    freeMusicFile(newFile);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_MONO
    int main(){
        
    }
#endif
