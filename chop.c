#include "chop.h"
#include "writeMusicFile.h"

bool secondsAreValid(MUSIC_FILE* musicFile, short endSecond){
    // the total time of a wave music file can be calculated using this formula:
    // time = FileLength / ByteRate
    if (endSecond > musicFile -> size / musicFile -> fmtSub -> byteRate) {
        printf("The file is shorter than %d seconds\n", endSecond);
        return false;
    }
    return true;
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

int chop(char const *fileName, short startSecond, short endSecond) {
    char* newFileName = (char*) malloc(strlen(fileName) + 8 * sizeof(char)); 
    //chopped-\0 is 8 characters
    MUSIC_FILE* choppedMusicFile = NULL;
    if (!(choppedMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE; 
    if (changedName(newFileName, fileName, "-chopped") == EXIT_FAILURE) return EXIT_FAILURE;
    if (readHeaderAndData(choppedMusicFile, newFileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    if (!secondsAreValid(choppedMusicFile, endSecond)) return EXIT_FAILURE;
    if (createChoppedFile(choppedMusicFile, startSecond, endSecond, fileName) == EXIT_FAILURE) 
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

#ifdef DEBUG_CHOP
int main()
{
    // TODO driver 
    chop();
}
#endif
