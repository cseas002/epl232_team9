#include "encryption.h"

unsigned short getBit(char const *word, int i)
{
    int bytePos = i / 8;
    int bitPos = i % 8;
    unsigned int wordChar = word[bytePos];
    unsigned short bit = (wordChar >> (7 - bitPos)) & 1;
    // taking from most significant bit to least significant
    // bit will be either 0 or 1
    return bit;
}

int insertBits(int *permutation, char const *word, MUSIC_FILE *musicFile)
{
    int i;
    for (i = 0; i < strlen(word) * 8 + 1; i++)
    {
        unsigned short u = getBit(word, i);
        int x = permutation[i];
        musicFile->data[x] = (musicFile->data[x] & 0xFE) | u; // taking the least significant bit
    }
    return EXIT_SUCCESS;
}

int encryption(const char *fileName, const char *text)
{
    MUSIC_FILE *musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE *)malloc(sizeof(MUSIC_FILE))))
        return EXIT_FAILURE;

    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE)
    {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(text, "r");
    if (!fp)
        return EXIT_FAILURE;
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *word = (char *)malloc(fileSize * sizeof(char));
    if(fread(word, sizeof(char), fileSize, fp)!=fileSize) return EXIT_FAILURE;

    int *permutation = createPermutationFunction(musicFile->size, SYSTEM_KEY_INTEGER);
    insertBits(permutation, word, musicFile);
    free(permutation);
    char *newFileName = (char *)malloc((strlen(fileName) + 9) * sizeof(char));
    // "encoded-\0" is 9 bytes
    changedName(newFileName, fileName, "encoded-");
    writeFile(musicFile, newFileName);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}
