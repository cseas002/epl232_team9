/**
 * @file encryption.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implementation of encryption.h file.
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
#include "encryption.h"

/**
 * @brief Get the Bit in the specific index of the word.
 * 
 * @param word A string
 * @param i The index of the bit
 * @return unsigned short (0 or 1)
 */
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

/**
 * @brief Insert bits of the message in the least significant bits of
 * random samples
 * 
 * @param permutation An array containing the index of random samples.
 * @param word The message to be hidden.
 * @param musicFile The encoded audio file.
 * @return An exit code.
 */
int insertBits(int *permutation, char const *word, MUSIC_FILE *musicFile)
{
    if(!permutation || !word || !musicFile)
        return EXIT_FAILURE;
    int i;
    for (i = 0; i < strlen(word) * 8; i++)
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
    {
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *word = (char *)malloc((fileSize + 1) * sizeof(char));
    if(!word)
    {
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    // + 1 for '\0'
    if (fread(word, sizeof(char), fileSize, fp) != fileSize)
    {
        freeMusicFile(musicFile);
        free(word);
        return EXIT_FAILURE;
    }
    if (musicFile->size < strlen(word) * 8)
    {
        printf("Wave file size too low to encrypt the given word\n");
        free(word);
        freeMusicFile(musicFile);
        fclose(fp);
        return EXIT_FAILURE;
    }
    int *permutation = createPermutationFunction(musicFile->size, SYSTEM_KEY_INTEGER);
    if(!permutation){
        free(word);
        freeMusicFile(musicFile);
        fclose(fp);
    }
    insertBits(permutation, word, musicFile);
    free(word);
    free(permutation);
    char *newFileName = (char *)malloc((strlen(fileName) + 9) * sizeof(char));
    // "encoded-\0" is 9 bytes
    if(!newFileName)
    {
        fclose(fp);
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    if(changedName(newFileName, fileName, "encoded-") == EXIT_FAILURE)
    {
        fclose(fp);
        free(newFileName);
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }
    fclose(fp);
    writeFile(musicFile, newFileName);
    free(newFileName);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}
