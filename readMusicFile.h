/**
 * @file readMusicFile.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef READ_MUSIC_FILE
#define READ_MUSIC_FILE

#include "header.h"
int readHeaderAndData(MUSIC_FILE*, char const *fileName);
int copyHeader(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile);
#endif

