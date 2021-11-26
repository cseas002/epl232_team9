#include "readMusicFile.h"
#include <string.h>
#include "writeMusicFile.h"

int copyHeader(MUSIC_FILE* target, MUSIC_FILE* source)
{
    if (!((target -> riff = (RIFF*) malloc(sizeof(RIFF))) &&
     (target -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB))) && 
     (target -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB))))) {
        printf("Cannot allocate space for reverse file\n");
        return EXIT_FAILURE;
    }
    strncpy(target -> riff -> chunkID , source -> riff -> chunkID, 4);
    target -> riff -> chunkSize = source -> riff -> chunkSize;
    strncpy(target -> riff -> format, source -> riff -> format, 4);

    strncpy(target -> fmtSub -> subChunk1ID, source -> fmtSub -> subChunk1ID, 4);
    target -> fmtSub -> subChunk1Size = source -> fmtSub -> subChunk1Size;
    target -> fmtSub -> audioFormat = source -> fmtSub -> audioFormat;
    target -> fmtSub -> numChannels = source -> fmtSub -> numChannels;
    target -> fmtSub -> sampleRate = source -> fmtSub -> sampleRate;
    target -> fmtSub -> byteRate = source -> fmtSub -> byteRate;
    target -> fmtSub -> blockAlign = source -> fmtSub -> blockAlign;
    target -> fmtSub -> bitsPerSample = source -> fmtSub -> bitsPerSample;

    strncpy(target -> dataSub -> subChunk2ID, source -> dataSub -> subChunk2ID, 4);
    target -> dataSub -> subChunk2Size = source -> dataSub -> subChunk2Size;
    target -> size = target -> dataSub -> subChunk2Size;

    return EXIT_SUCCESS;
}

int copyReverseData(MUSIC_FILE* target, byte* data) {
    int size = target -> size;
    if (!(target -> data = (byte*) malloc(size * sizeof(byte)))) {
        printf("Cannot allocate space \n");
        return EXIT_FAILURE;
    }
    int i;
    for (i = 0; i < size / 4; i++) {
        *(target -> data + i * 4) = *(data + size - i * 4 - 4);
        *(target -> data + i * 4 + 1) = *(data + size - i * 4 - 3);
        *(target -> data + i * 4 + 2) = *(data + size - i * 4 - 2);
        *(target -> data + i * 4 + 3) = *(data + size - i * 4 - 1);
    }
    return EXIT_SUCCESS;  
}

int reverse(MUSIC_FILE* musicFile, char* fileName) {
    MUSIC_FILE* reverseMusicFile = NULL;
    if (!(reverseMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (copyHeader(reverseMusicFile, musicFile) == EXIT_FAILURE) return EXIT_FAILURE;
    if (copyReverseData(reverseMusicFile, musicFile -> data) == EXIT_FAILURE) return EXIT_FAILURE;
    char* newFileName = (char*) malloc((strlen(fileName) + 29) * sizeof(char));
    // we add 29 because that's the size of ./as4-supplementary/reverse-\0
    strcat(newFileName, "./as4-supplementary/reverse-");
    strcat(newFileName, fileName);
    FILE* fp = NULL;
    if (!(fp = fopen(newFileName, "wb"))) {
        printf("Cannot create reverse file\n");
        return EXIT_FAILURE;
    }

    if (writeRiff(reverseMusicFile -> riff, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(reverseMusicFile -> fmtSub, sizeof(FMT_SUB), 1, fp);
    if (writeDataSub(reverseMusicFile -> dataSub, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(reverseMusicFile -> data, sizeof(byte), reverseMusicFile -> size, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_REVERSE
int main()
{
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    char* fileName = "piano.wav";
    char* fullFileName = (char*) malloc(((strlen(fileName) + 21) * sizeof(char))); 
    // 20 is for "./as4-supplementary/\0"
    strcat(fullFileName, "./as4-supplementary/");
    strcat(fullFileName, fileName);
    if (readHeaderAndData(musicFile, fullFileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return -1;
    }
    free(fullFileName);
    if (reverse(musicFile, fileName) == EXIT_FAILURE) return -1;
}
#endif