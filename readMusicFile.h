#ifndef READ_MUSIC_FILE
#define READ_MUSIC_FILE

#include "header.h"
#include <stdio.h>
int readHeaderAndData(MUSIC_FILE*, char* fileName);
int copyHeader(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile);
#endif