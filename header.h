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
    dword subChumk1Size;
    word audioFormat;
    word numChannels;
    dword sampleRate;
    dword byteRate;
    word blockAlign;
    word bitsPerSample;
}FMT_SUB;

typedef struct{
    char subChunk2ID[4];
    dword subChumk2Size;
    byte* data;
}DATA_SUB;