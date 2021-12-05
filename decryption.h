/**
 * @file decryption.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief Program used to decrypt the word from an input wave file.
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
 * @brief Main function which decrypts the word from the wave file
 * 
 * @param fileName the file name
 * @param msgLength the message length
 * @param outputFileName the file which the output will be printed
 * @return int EXIT_SUCCESS or EXIT_FAILURE, whether the program ends successfully or not
 */
int decryption(const char *fileName, int msgLength, const char* outputFileName);
#endif

