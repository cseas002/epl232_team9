#ifndef WRITE_MUSIC_FILE
#define WRITE_MUSIC_FILE

#include "header.h"
#include "readMusicFile.h"

int writeRiff(RIFF* riff, FILE* fp);

int writeDataSub(DATA_SUB* dataSub, FILE* fp);

int changedName(char* newFileName, char const *fileName, char* addition);
#endif