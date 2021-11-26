#ifndef CHOP 
#define CHOP

#include "readMusicFile.h"
#include "writeMusicFile.h"
#include "header.h" // this is supplementary but I put it so it's more clear what we use
#include <stdbool.h>
#include <string.h>

bool secondsAreValid(MUSIC_FILE*, short endSecond);

int createChoppedFile(MUSIC_FILE* choppedMusicFile, short startSecond, short endSecond, char* fileName);
#endif