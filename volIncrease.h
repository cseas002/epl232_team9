/**
 * @file volIncrease.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief Volume Increase program. With given number, it creates a new file named 
 * volIncreased-<given file name> (where <given file name> is the given file name)
 * with increased volume of the given number.
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
#ifndef VOLINCREASE
#define VOLINCREASE
#include "header.h"
#include "iolib.h"

/**
 * @brief Function which increases the volume of a given wave file x times, where
 * x is a number the client chooses.
 * 
 * @param fileName the wave file
 * @param changeStr how much will the volume increase (times the volume will be multiplied)
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int changeVol(char const *fileName, char* changeStr);
#endif
