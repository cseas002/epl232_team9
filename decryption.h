#ifndef DECRYPTION
#define DECRYPTION
#include "header.h"
#include "readMusicFile.h"
#include "permutation.h"
#include <string.h>

int decryption(const char *fileName, int msgLength, const char* outputFileName);
#endif