/**
 * @file changeSpeed.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief This program is for speed change option. You can choose a number between (0, 100000)
 * (0 and 100000 are not included) and then you choose the wave files you want to change the speed.
 * The speed of the changed music files will be x times faster than the original, where x is the 
 * number you chose. Note that x can be lower than 1, so if you choose a number between 0 and 1 (0,1)
 * the new file(s) will have lower speed. For example if you choose to change speed 0.5, the new file(s)
 * will be 2 times slower.
 * e.g.
 * ./wavengine -changeSpeed 2 piano.wav
 * Results: if piano.wav is in the same folder as wavengine, a new file will be created named "5-times-speed-changed-piano.wav" 
 * which is piano.wav 5 times faster
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
 * 
 */
#ifndef CHANGE_SPEED
#define CHANGE_SPEED
#include "header.h"
#include "iolib.h"

/**
 * @brief speedChange function is a function which creates a new 
 * music file, which is x times faster than the original, where
 * x is a number from 0 to 100000 (0 and 100000 not included).
 * 
 * @param fileName the fileName with the wave file
 * @param speedChange the speed change (how many times faster the new
 * music file will be)
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program succeeds
 * or not
 */
int speedChange(char const *fileName, char *speedChange);
#endif
