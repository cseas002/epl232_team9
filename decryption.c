#include "decryption.h"

int decryption(const char *fileName, int msgLength, const char *outputFileName)
{
    MUSIC_FILE *musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE *) malloc(sizeof(MUSIC_FILE))))
        return EXIT_FAILURE;

    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE)
    {
        printf("Failed to read music file\n");
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    int *permutation = createPermutationFunction(musicFile->size, SYSTEM_KEY_INTEGER);
    char *msg = (char *) malloc((msgLength + 1) * sizeof(char));
    int i;
    for (i = 0; i < msgLength + 1; i++)
        msg[i] = 0;
    for (i = 0; i < msgLength * 8; i++)
    {
        int charPos = i / 8;
        int bitPos = i % 8;
        msg[charPos] = msg[charPos] | ((musicFile->data[permutation[i]] & 1) << (7 - bitPos));
    }
    msg[msgLength] = '\0';
    FILE *fp = fopen(outputFileName, "w");
    if (!fp)
        return EXIT_FAILURE;
    fprintf(fp, "%s\n", msg);
    fclose(fp);
    free(permutation);
    free(msg);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}
