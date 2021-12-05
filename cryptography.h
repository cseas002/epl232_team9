/**
 * @file cryptography.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief Cryptography is a helping program used for encryption and decryption.
 * It has functions which both programs use.
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
 * @brief Create a Permutation Function array with given size and system key.
 * 
 * @param N size of permutation array
 * @param systemkey the system key
 * @return int* pointer to the array which will be created
 */
int *createPermutationFunction(int N, unsigned int systemkey);

/**
 * @brief Function which swaps two numbers in an array.
 * 
 * @param num1 the first number
 * @param num2 the second number
 */
void swap(int *num1, int *num2);
#endif
