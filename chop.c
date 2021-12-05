/**
 * @file chop.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief The implementation of chop.h file.
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
#include "chop.h"

bool secondsAreValid(MUSIC_FILE* musicFile, int startSecond, int endSecond){
    // the total time of a wave music file can be calculated using this formula:
    // time = FileLength / ByteRate
    if (startSecond >= endSecond) {
        printf("The starting second cannot be greater or equal to the end second\n");
        return false;
    }
    if (startSecond < 0) {
        printf("The starting second cannot be a negative number\n");
        return false;
    }
    if (endSecond > musicFile -> size / musicFile -> fmtSub -> byteRate) {
        printf("The file is shorter than %d seconds\n", endSecond);
        return false;
    }
    return true;
}

int createChoppedFile(MUSIC_FILE* choppedMusicFile, int startSecond, int endSecond, char const *newFileName) {
    int byteRate = choppedMusicFile -> fmtSub -> byteRate;
    dword newSize = (endSecond - startSecond) * byteRate;
    choppedMusicFile -> size = newSize;
    choppedMusicFile -> dataSub -> subChunk2Size = newSize;
    choppedMusicFile -> riff -> chunkSize = newSize + 36; 
    // chunk size is the new data size + 36 (header fields - 8) (36 in hex is)
    byte* newData = NULL;
    if (!(newData = (byte*) malloc(newSize))) {
        printf("Cannot allocate memory for new data\n");
        return EXIT_FAILURE;
    }
    int i, startLength = startSecond * byteRate + 44, endLength = endSecond * byteRate + 44;
    // we add 44 because that's the header byte size (all chunks size) 

    for (i = startLength; i < endLength; i++)
        *(newData + i - startLength) = *(choppedMusicFile -> data + i);
    free(choppedMusicFile -> data);
    choppedMusicFile -> data = newData;
    
    writeFile(choppedMusicFile, newFileName);
    
    return EXIT_SUCCESS;
}

int chop(char const *fileName, int startSecond, int endSecond) {
    char* newFileName = (char*) malloc(strlen(fileName) + 9 * sizeof(char)); 
    //chopped-\0 is 8 characters
    MUSIC_FILE* choppedMusicFile = NULL;
    if (!(choppedMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) 
        return EXIT_FAILURE; 
    if (changedName(newFileName, fileName, "chopped-") == EXIT_FAILURE) {
        free(choppedMusicFile);
        return EXIT_FAILURE;
    }
    if (readHeaderAndData(choppedMusicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        free(choppedMusicFile);
        return EXIT_FAILURE;
    }
    if (!secondsAreValid(choppedMusicFile, startSecond, endSecond)) {
        free(choppedMusicFile);
        return EXIT_FAILURE;
    }
    if (createChoppedFile(choppedMusicFile, startSecond, endSecond, newFileName) == EXIT_FAILURE) {
        free(choppedMusicFile);
        return EXIT_FAILURE;
    }
    free(newFileName);
    freeMusicFile(choppedMusicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_CHOP
int main()
{
    printf("Save the piano.wav file in the as4-supplementary sub folder in order to work!\n");
    chop("./as4-supplementary/piano.wav", 2, 4);
    printf("Chopping piano.wav file from second 2 to 4 ...Done!\n");
    return 0;
}
#endif
