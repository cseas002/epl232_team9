#include "header.h"
#include <stdio.h>

int readHeader(MUSIC_FILE* musicFile, char* fileName) {
    FILE* fp = fopen("./as4-supplementary/tada.wav", "rb");
    if (!(musicFile -> riff = (RIFF*) malloc(sizeof(RIFF)))) return EXIT_FAILURE;
    fread(musicFile -> riff, sizeof(RIFF), 1, fp);
    if (!(musicFile -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB)))) return EXIT_FAILURE;
    fread(musicFile -> fmtSub, sizeof(FMT_SUB), 1, fp);
    if (!(musicFile -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB)))) return EXIT_FAILURE;
    fread(musicFile -> dataSub, sizeof(DATA_SUB), 1, fp);
    musicFile -> size = musicFile -> dataSub -> subChumk2Size;
    if (!(musicFile -> data = (word*) malloc(musicFile -> size))) return EXIT_FAILURE;
    fread(musicFile -> data, sizeof(musicFile -> size), 1, fp);
    return EXIT_SUCCESS;
}

int printMusicFile(MUSIC_FILE* musicFile) {
    printf("chunkID: %.*s\n", 4, musicFile -> riff -> chunkID);
    printf("chunkSize: %d\n", musicFile -> riff -> chunkSize);
    printf("format: %.*s\n", 4, musicFile -> riff -> format);
    return EXIT_SUCCESS;
}

int main(int argc, char const *argv[])
{
    MUSIC_FILE* musicFile;
    readHeader(musicFile, " ");
    return 0;
    printMusicFile(musicFile);
    return 0;
}
