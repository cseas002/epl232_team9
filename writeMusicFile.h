/**
 * @file writeMusicFile.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-11-25 
 */
#ifndef WRITE_MUSIC_FILE
#define WRITE_MUSIC_FILE

#include "header.h"

// /**
//  * @brief Write RIFF Chunk Descriptor in a binary output file.
//  * 
//  * @param riff RIFF Chunk Descriptor of WAV Header
//  * @param fp Pointer to the binary output file
//  * @return an exit code
//  */
// int writeRiff(RIFF* riff, FILE* fp);

// /**
//  * @brief Write Data Sub-Chunk Header in a binary output file.
//  * 
//  * @param riff Data Sub-Chunk Header of WAV Header
//  * @param fp Pointer to the binary output file
//  * @return an exit code
//  */
// int writeDataSub(DATA_SUB* dataSub, FILE* fp);

int changedName(char* newFileName, char const *fileName, char* addition);

int writeFile(MUSIC_FILE* musicFile, char const *newFileName);
#endif