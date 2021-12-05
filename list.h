/**
 * @file list.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief This is a program which prints the details of given wave
 * files. 
 * @version 0.1
 * @date 2021-11-25
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
#ifndef LIST
#define LIST
#include "iolib.h"
#include "header.h" // this is supplementary but I put it so it's more clear what we use

/**
 * @brief Function which prints the RIFF chunk details of a wave file.
 * Using "%.*s", 4 in printf we can print the first 4 characters of a string
 * 
 * @param riff the RIFF structure of a given music file
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int printRiff(RIFF*);

/**
 * @brief Function which prints the fmt subchunk details of a wave file.
 * @param fmtSub the FMT_SUB structure of a given music file
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int printFmtSub(FMT_SUB*);

/**
 * @brief Function which prints the data subchunk details of a wave file.
 * @param fmtSub the FMT_SUB structure of a given music file
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int printDataSub(DATA_SUB*);

/**
 * @brief Function which prints the details of a wave file.
 * 
 * @param fileName the file name
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int printList(char const *fileName);
#endif

