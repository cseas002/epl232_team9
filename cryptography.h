/**
 * @file cryptography.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief This program provides some basic functions needed for the
 * encryption and decryption of data. 
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
#ifndef CRYPTOGRAPHY
#define CRYPTOGRAPHY
#include "header.h"
#include "iolib.h"

/**
 * @brief Creates a Permutation Function array with random indices
 * from 0 to N-1.
 * 
 * @param N The number of audio samples
 * @param systemkey An encryption key.
 * @return An array with random indices.
 */
int* createPermutationFunction(int N, unsigned int systemkey);

/**
 * @brief Swaps two cells in an array
 * 
 * @param num1 The address of the first cell.
 * @param num2 The address of the second cell.
 */
void swap(int* num1, int* num2);
#endif
