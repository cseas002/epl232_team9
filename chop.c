#include "chop.h"
#include "writeMusicFile"
bool secondsAreValid(MUSIC_FILE* musicFile, short endSecond){
    // the total time of a wave music file can be calculated using this formula:
    // time = FileLength / ByteRate
    if (endSecond > musicFile -> size / musicFile -> fmtSub -> byteRate) {
        printf("The file is shorter than %d seconds\n", endSecond);
        return false;
    }
    return true;
}

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


int createChoppedFile(MUSIC_FILE* choppedMusicFile, short startSecond, short endSecond, char* fileName) {
    int byteRate = choppedMusicFile -> fmtSub -> byteRate;
    int newSize = (endSecond - startSecond) * byteRate;
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
    char* newFileName = (char*) malloc((strlen(fileName) + 29) * sizeof(char));
    // we add 29 because that's the size of ./as4-supplementary/chopped-\0
    strcat(newFileName, "./as4-supplementary/chopped-");
    strcat(newFileName, fileName);
    FILE* fp = NULL;
    if (!(fp = fopen(newFileName, "wb"))) {
        printf("Cannot create chopped file\n");
        return EXIT_FAILURE;
    }
    if (writeRiff(choppedMusicFile -> riff, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(choppedMusicFile -> fmtSub, sizeof(FMT_SUB), 1, fp); // everything is the same in fmt sub
    if (writeDataSub(choppedMusicFile -> dataSub, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(choppedMusicFile -> data, sizeof(byte), newSize, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_CHOP
int main()
{
    MUSIC_FILE* choppedMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    char* fileName = "piano.wav";
    char* fullFileName = (char*) malloc(((strlen(fileName) + 21) * sizeof(char))); 
    // 20 is for "./as4-supplementary/\0"
    strcat(fullFileName, "./as4-supplementary/");
    strcat(fullFileName, fileName);
    if (readHeader(choppedMusicFile, fullFileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return -1;
    }
    free(fullFileName);
    short startSecond = 2, endSecond = 6;
    if (!secondsAreValid(choppedMusicFile, endSecond)) return -1;
    if (createChoppedFile(choppedMusicFile, startSecond, endSecond, fileName) == EXIT_FAILURE) return -1;
    return 0;
}
#endif
