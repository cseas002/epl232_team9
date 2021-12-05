/**
 * @file cryptography.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implementation of cryptography.h file. 
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
#include "cryptography.h"
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int *createPermutationFunction(int N, unsigned int systemkey)
{
    int i;
    int *permutation = (int *) malloc((N * sizeof(int)));
    srand(systemkey);
    for (i = 0; i < N; i++)
        *(permutation + i) = i;

    for (i = 0; i < N; i++)
    {
        int rand1 = rand() % N;
        int rand2 = rand() % N;
        swap(permutation + rand1, permutation + rand2);
    }
    return permutation;
}
