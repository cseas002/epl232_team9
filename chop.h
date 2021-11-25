#include "readMusicFile.h"
#include "header.h" // this is supplementary but I put it so it's more clear what we use
#include <stdbool.h>
#include <string.h>

bool secondsAreValid(MUSIC_FILE*, short endSecond);

int writeRiff(RIFF* riff, FILE* fp);

int writeDataSub(DATA_SUB* dataSub, FILE* fp);

int createChoppedFile(MUSIC_FILE* choppedMusicFile, short startSecond, short endSecond, char* fileName);