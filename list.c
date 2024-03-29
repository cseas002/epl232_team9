/**
 * @file list.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief The implementation of list.h file. 
 * @version 0.1
 * @date 2021-11-25
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
#include "list.h"

int printRiff(RIFF* riff) {
    if (!riff) return EXIT_FAILURE; // if riff is NULL return failure
    printf("RIFF_CHUNK_HEADER\n=================\n");
    printf("chunkID: %.*s\n", 4, riff -> chunkID); 
    // Using "%.*s", 4 in printf we can print the first 4 characters of a string
    printf("chunkSize: %d\n", riff -> chunkSize);
    printf("format: %.*s\n\n", 4, riff -> format);
    // Using "%.*s", 4 in printf we can print the first 4 characters of a string
    return EXIT_SUCCESS;
}

int printFmtSub(FMT_SUB* fmtSub) {
    if (!fmtSub) return EXIT_FAILURE; // if fmt sub is NULL return failure
    printf("FMT_SUBCHUNK_HEADER\n===================\n");
    printf("subChunk1ID: %.*s\n", 4, fmtSub -> subChunk1ID);
    // Using "%.*s", 4 in printf we can print the first 4 characters of a string
    printf("subChunk1Size: %d\n", fmtSub -> subChunk1Size);
    printf("audioFormat: %d\n", fmtSub -> audioFormat);
    printf("numChannels: %d\n", fmtSub -> numChannels);
    printf("sampleRate: %d\n", fmtSub -> sampleRate);
    printf("byteRate: %d\n", fmtSub -> byteRate);
    printf("blockAlign: %d\n", fmtSub -> blockAlign);
    printf("bitsPerSample: %d\n\n", fmtSub -> bitsPerSample);
    return EXIT_SUCCESS;
}

int printDataSub(DATA_SUB* dataSub) {
    if (!dataSub) return EXIT_FAILURE; // if data subchunk header is NULL return failure
    printf("DATA_SUBCHUNK_HEADER\n====================\n");
    printf("subChunk2ID: %.*s\n", 4, dataSub -> subChunk2ID);
    // Using "%.*s", 4 in printf we can print the first 4 characters of a string
    printf("subChunk2Size: %d\n\n", dataSub -> subChunk2Size);
    return EXIT_SUCCESS;
}

int printList(char const *fileName) {
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read first music file\n");
        return EXIT_FAILURE;
        }
    if (printRiff(musicFile -> riff) == EXIT_FAILURE) return EXIT_FAILURE;
    if (printFmtSub(musicFile -> fmtSub) == EXIT_FAILURE) {
        free(musicFile -> riff);
        return EXIT_FAILURE;
    }
    if (printDataSub(musicFile -> dataSub) == EXIT_FAILURE) {
        free(musicFile -> riff);
        free(musicFile -> fmtSub);
        return EXIT_FAILURE;
    }
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_LIST
int main(int argc, char const *argv[])
{
    printf("Save the piano.wav file in the as4-supplementary sub folder in order to work!\n");
    printf("Details for piano.wav file:\n");
    printList("./as4-supplementary/piano.wav");
    return 0;
}
#endif
