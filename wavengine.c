#include "header.h"
#include <stdio.h>

int main()
{
    FILE* fp = fopen("./as4-supplementary/tada.wav", "rb");
    RIFF riff;
    fread(&riff, sizeof(RIFF), 1, fp);
    printf("%d\n", riff.chunkSize);
    
}