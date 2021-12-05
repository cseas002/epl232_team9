/**
 * @file wavengine.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
 * The interface for the client program.
 * COMPILATION COMMAND: gcc -o wavengine wavengine.c epl232_team9.a
 * EXECUTION COMMAND: (see README.md)
 * @version 0.1
 * @date 2021-11-25 
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas, Lampros Dionysiou.
 * This file is part of WAV Engine.
 * WAV Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * Υou should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
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

/**
 * @brief Method that prints the available options of the program.
 * 
 */
void printInfo();

/**
 * @brief Method that utilizes all the capabiltiies of epl232_team9 library.
 * 
 * @param argc Number of arguments.
 * @param argv The arguments.
 * @return An exit code.
 */
int wavengine(int argc, char const *argv[]);
#endif

