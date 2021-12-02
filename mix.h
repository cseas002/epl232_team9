#ifndef MIX
#define MIX
#include "header.h"
#include "readMusicFile.h"
#include "writeMusicFile.h"
#include <string.h>
#include <stdio.h>

int mix(MUSIC_FILE* file1, MUSIC_FILE *file2, char const *filename1, char const *filename2);
#endif