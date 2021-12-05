/**
 * @file list.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief 
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
#endif

