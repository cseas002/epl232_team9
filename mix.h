/**
 * @file mix.h
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief Audio files mixing software. This program reads two binary wav 
 * music files and merges them into one. The new music file has the left
 * audio channel of the first file and the right channel of the second one.
 * The output music file is named mix-<first file name>-<second file name>.wav.
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Lampros Dionysiou.
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
#ifndef MIX
#define MIX
#include "header.h"
#include "iolib.h"

/**
 * @brief This method merges two audio files into one. It reads the header
 * and data from both files. It creates a new audio file using the left
 * channel of the first file and the right channel of the second one. The 
 * size of the new audio file is the size of the smaller file.
 * If the two files do not have the same number of bits per sample or either
 * of those is mono, then the function terminates.
 * 
 * @param filename1 The name of the first file (left channel).
 * @param filename2 The name of the second file (right channel).
 * @return An exit code.
 */
int mix(char const *filename1, char const *filename2);
#endif

