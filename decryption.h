/**
 * @file decryption.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief This program decrypts a message from an audio file.
 * It reads the audio file provided exports the hidden message
 * in an output file.
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
#ifndef DECRYPTION
#define DECRYPTION
#include "cryptography.h"

/**
 * @brief Method that decrypts a message from an audio file. It reads
 * the header and data from an audio file using the filename provided.
 * Using the permutaion function, it gets the least significant bits 
 * of random samples. Using these bits, it constructs a string bit-by-bit.
 * It exports the new string in an output file with the name given.
 * 
 * @param fileName 
 * @param msgLength 
 * @param outputFileName 
 * @return int 
 */
int decryption(const char *fileName, int msgLength, const char* outputFileName);
#endif

