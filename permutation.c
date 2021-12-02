#include "permutation.h"
void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int* createPermutationFunction(int N, unsigned int systemkey) {
    int i;
    int* permutation = (int*) malloc((N * sizeof(int)));
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