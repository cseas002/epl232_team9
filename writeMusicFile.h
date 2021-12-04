/**
 * @file wavengine.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-11-25 
 */
#ifndef WRITE_MUSIC_FILE
#define WRITE_MUSIC_FILE

#include "header.h"

int writeRiff(RIFF* riff, FILE* fp);

int writeDataSub(DATA_SUB* dataSub, FILE* fp);

int changedName(char* newFileName, char const *fileName, char* addition);

int writeFile(MUSIC_FILE* musicFile, char const *newFileName);
#endif