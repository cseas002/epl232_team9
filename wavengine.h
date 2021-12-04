/**
 * @file wavengine.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
 * COMPILATION COMMAND: gcc -o wavengine wavengine.c epl232_team9.a
 * EXECUTION COMMAND: (see README.md)
 * @version 0.1
 * @date 2021-11-25 
 */
#ifndef WAVENGINE
#define WAVENGINE
#include "list.h"
#include "mix.h"
#include "stereoToMono.h"
#include "chop.h"
#include "reverse.h"
#include "encryption.h"
#include "decryption.h"
#include "changeSpeed.h"
#include "volIncrease.h"
void printWrongInput();
int wavengine(int argc, char const *argv[]);
#endif

