#ifndef HEADER
#define HEADER
#include <stdlib.h>
typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

typedef struct {
    char chunkID[4];
    dword chunkSize;
    char format[4];
} __attribute__((packed)) RIFF;

typedef struct {
    char subChunk1ID[4];
    dword subChunk1Size;
    word audioFormat;
    word numChannels;
    dword sampleRate;
    dword byteRate;
    word blockAlign;
    word bitsPerSample;
}__attribute__((packed)) FMT_SUB;

typedef struct{
    char subChunk2ID[4];
    dword subChunk2Size;
}__attribute__((packed)) DATA_SUB;

typedef struct {
    RIFF* riff;
    FMT_SUB* fmtSub;
    DATA_SUB* dataSub;
    byte* data;
    dword size; // subChumk2Size just for simplicity
}__attribute__((packed)) MUSIC_FILE;
#endif
