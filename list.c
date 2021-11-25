/**
 * @file list.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-11-25
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas
 * 
 */
#include "list.h"

int printRiff(RIFF* riff) {
    if (!riff) return EXIT_FAILURE; // if riff is NULL return failure
    printf("RIFF_CHUNK_HEADER\n=================\n");
    printf("chunkID: %.*s\n", 4, riff -> chunkID); 
    printf("chunkSize: %d\n", riff -> chunkSize);
    printf("format: %.*s\n\n", 4, riff -> format);
    return EXIT_SUCCESS;
}

int printFmtSub(FMT_SUB* fmtSub) {
    if (!fmtSub) return EXIT_FAILURE; // if fmt sub is NULL return failure
    printf("FMT_SUBCHUNK_HEADER\n===================\n");
    printf("subChunk1ID: %.*s\n", 4, fmtSub -> subChunk1ID);
    printf("subChunk1Size: %d\n", fmtSub -> subChunk1Size);
    printf("audioFormat: %d\n", fmtSub -> audioFormat);
    printf("numChannels: %d\n", fmtSub -> numChannels);
    printf("sampleRate: %d\n", fmtSub -> sampleRate);
    printf("byteRate: %d\n", fmtSub -> byteRate);
    printf("blockAlign: %d\n", fmtSub -> blockAlign);
    printf("bitsPerSample: %d\n\n", fmtSub -> bitsPerSample);
    return EXIT_SUCCESS;
}

int printDataSub(DATA_SUB* dataSub) {
    if (!dataSub) return EXIT_FAILURE; // if data subchunk header is NULL return failure
    printf("DATA_SUBCHUNK_HEADER\n====================\n");
    printf("subChunk2ID: %.*s\n", 4, dataSub -> subChunk2ID);
    printf("subChunk2Size: %d\n\n", dataSub -> subChunk2Size);
    return EXIT_SUCCESS;
}

int printMusicFiles(MUSIC_FILE* musicFile, MUSIC_FILE* musicFile1) {
    if (printRiff(musicFile -> riff) == EXIT_FAILURE) return EXIT_FAILURE;
    if (printFmtSub(musicFile -> fmtSub) == EXIT_FAILURE) return EXIT_FAILURE;
    if (printDataSub(musicFile -> dataSub) == EXIT_FAILURE) return EXIT_FAILURE;
    printf("************************************\n");
    if (printRiff(musicFile1 -> riff) == EXIT_FAILURE) return EXIT_FAILURE;
    if (printFmtSub(musicFile1 -> fmtSub) == EXIT_FAILURE) return EXIT_FAILURE;
    if (printDataSub(musicFile1 -> dataSub) == EXIT_FAILURE) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

#ifdef DEBUGLIST
int main()
{
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    MUSIC_FILE* musicFile1 = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    readHeader(musicFile, "./as4-supplementary/tada.wav");
    readHeader(musicFile1, "./as4-supplementary/chord.wav");
    printMusicFiles(musicFile, musicFile1);
    return 0;
}
#endif