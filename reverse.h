/**
 * @file reverse.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef REVERSE
#define REVERSE
#include "header.h"
#include"iolib.h"

int copyReverseData(MUSIC_FILE* target, byte* data);

int createReverseFile(MUSIC_FILE* musicFile, char const *fileName);

int reverse(char const *fileName);
#endif

