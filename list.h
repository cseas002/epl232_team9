/**
 * @file list.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief 
 * @version 0.1
 * @date 2021-11-25
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas
 * 
 */
#include "iolib.h"
#include "header.h" // this is supplementary but I put it so it's more clear what we use

/**
 * @brief 
 * Using "%.*s", 4 in printf we can print the first 4 characters of a string
 * 
 * @param riff 
 * @return int 
 */
int printRiff(RIFF*);

/**
 * @brief 
 * Using "%.*s", 4 in printf we can print the first 4 characters of a string
 * @param fmtSub 
 * @return int 
 */
int printFmtSub(FMT_SUB*);

int printDataSub(DATA_SUB*);

// int printMusicFiles(MUSIC_FILE**, short);

int printList(char const *fileName);