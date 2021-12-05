/**
 * @file chop.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief This program is used to chop a music file to a smaller one. The 
 * customer chooses the starting and ending second, and a new file named 
 * chopped-<old music file name> will be created. This new file will be 
 * the music file given chopped from starting second to ending second (which
 * the customer chooses).
 * @version 0.1
 * @date 2021-12-04
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
#ifndef CHOP 
#define CHOP

#include "iolib.h"
#include "header.h" // this is supplementary but I put it so it's more clear what we use
#include <stdbool.h>

/**
 * @brief secondsAreValid is a function which checks whether the input seconds are valid.
 * Valid seconds are those within the boundaries of the music file. 
 * e.g. if a wave file is 10 seconds long, the end second must be an integer from 1 to 10, 
 * and the start second must be an integer from 0 to 9. Note that start second cannot be greater
 * or equal to the end second and it must be a positive number.
 * 
 * @param startSecond the start second
 * @param endSecond the end second
 * @return true if the seconds are valid
 * @return false otherwise
 */
bool secondsAreValid(MUSIC_FILE*, int startSecond, int endSecond);

/**
 * @brief Create a Chopped File object from the given start second to the given end second and then
 * save the output to a new file.
 * 
 * @param choppedMusicFile the chopped music file
 * @param startSecond the start second
 * @param endSecond the end second
 * @param fileName the filename where the music file is. (.wav file)
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int createChoppedFile(MUSIC_FILE* choppedMusicFile, int startSecond, int endSecond, char const *fileName);

/**
 * @brief The main function which reads the input file and chops the file from start second to end
 * second and then saves the output to a new file.
 * 
 * @param fileName the file name
 * @param startSecond the start second
 * @param endSecond the end second
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int chop(char const *fileName, int startSecond, int endSecond);
#endif

