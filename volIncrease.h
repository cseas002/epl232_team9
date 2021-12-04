/**
 * @file volIncrease.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief Volume Increase program. With given number, it creates a new file named 
 * volIncreased-<given file name> (where <given file name> is the given file name)
 * with increased volume of the given number.
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas
 * 
 */
#ifndef VOLINCREASE
#define VOLINCREASE
#include "header.h"
#include "iolib.h"

int changeVol(char const *fileName, char* changeStr);
#endif
