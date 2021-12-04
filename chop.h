/**
 * @file chop.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas
 * 
 */
#ifndef CHOP 
#define CHOP

#include "iolib.h"
#include "header.h" // this is supplementary but I put it so it's more clear what we use
#include <stdbool.h>

bool secondsAreValid(MUSIC_FILE*, int endSecond);

int createChoppedFile(MUSIC_FILE* choppedMusicFile, int startSecond, int endSecond, char const *fileName);

int chop(char const *fileName, int startSecond, int endSecond);
#endif

