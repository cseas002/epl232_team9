/**
 * @file stereoToMono.h
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief Stereo To Mono Converter. This program reads a binary wav 
 * music file and converts its audio to mono. The output music file 
 * is named mono-<input file name>.wav.
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
#ifndef STEREOTOMONO
#define STEREOTOMONO
#include "header.h"
#include "iolib.h"

/**
 * @brief Method that converts an audio file from stero to mono. 
 * It reads an audio file using the given filename and creates
 * a new output wav file using the left audio channel.
 * The name of the output file is mono-<input filename>.wav.
 * 
 * @param fileName The filename of the input file
 * @return An exit code
 */
int stereoToMono(char const *fileName);
#endif

