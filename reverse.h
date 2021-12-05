/**
 * @file reverse.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief Program which reverses the wave file data. 
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas.
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
#ifndef REVERSE
#define REVERSE
#include "header.h"
#include"iolib.h"

/**
 * @brief Function which copies data in music file in reverse order.
 * 
 * @param target the music file with the reversed data
 * @param data the data array 
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int copyReverseData(MUSIC_FILE* target, byte* data);

/**
 * @brief Create a Reverse File music file function with given wave file.
 * 
 * @param musicFile the music file that we want to save the reverse data
 * @param fileName the wave file
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int createReverseFile(MUSIC_FILE* musicFile, char const *fileName);

/**
 * @brief Reverse function that read a wave file and creates a new wave file with data in 
 * reverse order.
 * 
 * @param fileName the wave file
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int reverse(char const *fileName);
#endif

