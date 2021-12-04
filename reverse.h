#ifndef REVERSE
#define REVERSE
#include "header.h"
#include"iolib.h"

int copyReverseData(MUSIC_FILE* target, byte* data);

int createReverseFile(MUSIC_FILE* musicFile, char const *fileName);

int reverse(char const *fileName);
#endif

