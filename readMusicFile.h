/**
 * @file readMusicFile.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief This interface provides the necessary functions to read
 * the header and data from an input file
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
#ifndef READ_MUSIC_FILE
#define READ_MUSIC_FILE
#include "header.h"

/**
 * @brief Method that reads the header and data of a binary wav file and
 * saves them in a MUSIC_FILE struct. It allocates the necessary space
 * for the struct.
 * 
 * @param fileName The name of the file to be read.
 * @return An exit code.
 */
int readHeaderAndData(MUSIC_FILE*, char const *fileName);

/**
 * @brief Function which copies the header from a music file to another.
 * 
 * @param musicFile the music file which contains the header that will be copied
 * @param newFile the new music file which needs the copied header
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int copyHeader(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile);
#endif

