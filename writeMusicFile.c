#include "writeMusicFile.h"
#include <stdio.h>
#include <stdlib.h>

int writeRiff(RIFF* riff, FILE* fp) {
    fwrite(riff -> chunkID, sizeof(char), 4, fp); // write "RIFF"
    byte bytes[4];
    int i = 0;
    unsigned int getByte = (1 << 8) - 1;
    for (i = 0; i < 4; i++)
    {
        // the first getByte will be 11111111, second 1111111100000000, etc.
        bytes[i] = riff -> chunkSize & getByte;
        // with this technique, we will save the least significant byte of chunkSize in 
        // the first position and the most significant in the last position
        getByte <<= 8;
    }
    fwrite((&riff -> chunkSize), sizeof(byte), 4, fp); // write chunkSize
    fwrite(riff -> format, sizeof(char), 4, fp); // write "WAVE"
    return EXIT_SUCCESS;
}

int writeDataSub(DATA_SUB* dataSub, FILE* fp){
    fwrite(dataSub -> subChunk2ID, sizeof(char), 4, fp); // write "data"
    byte bytes[4];
    int i = 0;
    unsigned int getByte = (1 << 8) - 1;
    for (i = 0; i < 4; i++)
    {
        // the first getByte will be 11111111, second 1111111100000000, etc.
        bytes[i] = dataSub -> subChunk2Size & getByte;
        // with this technique, we will save the least significant byte of chunkSize in 
        // the first position and the most significant in the last position
        getByte <<= 8;
    }
    fwrite(&(dataSub -> subChunk2Size), sizeof(byte), 4, fp); // write sub chunk size
    return EXIT_SUCCESS;
}