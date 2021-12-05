/**
 * @file decryption.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implementation of decryption.h file.
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
#include "decryption.h"

int decryption(const char *fileName, int msgLength, const char *outputFileName)
{
    MUSIC_FILE *musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE *) malloc(sizeof(MUSIC_FILE))))
    {
        printf("Failed to read music file.\n");
        return EXIT_FAILURE;
    }
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE)
    {
        printf("Failed to read music file.\n");
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    int *permutation = createPermutationFunction(musicFile->size, SYSTEM_KEY_INTEGER);
    if(!permutation){
        printf("Failed to create the permutation array.\n");
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    char *msg = (char *) malloc((msgLength + 1) * sizeof(char));
    if(!msg){
        printf("Failed to allocate memory for the message.\n");
        freeMusicFile(musicFile);
        free(permutation);
        return EXIT_FAILURE;
    }
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
    {
        printf("Failed to create the output file.\n");
        freeMusicFile(musicFile);
        free(permutation);
        free(msg);
        return EXIT_FAILURE;
    }
    fprintf(fp, "%s\n", msg);
    fclose(fp);
    free(permutation);
    free(msg);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_DECRYPTION
int main()
{
    printf("Save the encoded-piano.wav file in this folder in order to work!\n");
    if (decryption("encoded-piano.wav", 9, "DEBUG_DECRYPTION.txt") == EXIT_FAILURE) {
        printf("Cannot create DEBUG_DECRYPTION.txt\n");
        exit(-1);
    }
    printf("Decoding word with 3 characters ...Done!\nCheck the DEBUG_DECRYPTION.txt file!\n");
}
#endif
