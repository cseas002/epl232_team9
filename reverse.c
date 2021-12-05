/**
 * @file reverse.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief The implementation of reverse.h file. 
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas.
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
#include "reverse.h"

int copyReverseData(MUSIC_FILE* target, byte* data) {
    int size = target -> size;
    if (!(target -> data = (byte*) malloc(size * sizeof(byte)))) {
        printf("Cannot allocate space\n");
        return EXIT_FAILURE;
    }
    int i;
    for (i = 0; i < size / 4; i++) {
        *(target -> data + i * 4) = *(data + size - i * 4 - 4);
        *(target -> data + i * 4 + 1) = *(data + size - i * 4 - 3);
        *(target -> data + i * 4 + 2) = *(data + size - i * 4 - 2);
        *(target -> data + i * 4 + 3) = *(data + size - i * 4 - 1);
    }
    return EXIT_SUCCESS;  
}

int reverse(char const* fileName) {
    char* newFileName = (char*) malloc(strlen(fileName) + 9 * sizeof(char)); 
    //reverse-\0 is 9 characters
    MUSIC_FILE* musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }

    MUSIC_FILE* reverseMusicFile = NULL;
    if (!(reverseMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (copyHeader(musicFile, reverseMusicFile) == EXIT_FAILURE) return EXIT_FAILURE;
    if (copyReverseData(reverseMusicFile, musicFile -> data) == EXIT_FAILURE) return EXIT_FAILURE;
    if (changedName(newFileName, fileName, "reverse-") == EXIT_FAILURE) return EXIT_FAILURE;
    if (writeFile(reverseMusicFile, newFileName) == EXIT_FAILURE) return EXIT_FAILURE;
    free(newFileName);
    freeMusicFile(reverseMusicFile);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_REVERSE
int main()
{
    printf("Save the piano.wav file in the as4-supplementary sub folder in order to work!\n");
    reverse("./as4-supplementary/piano.wav");
    printf("Reversing piano.wav ...Done!\n");
    return 0;
}
#endif
