/**
 * @file changeSpeed.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief This program is for speed change option. You can choose a number between (0, 100000)
 * (0 and 100000 are not included) and then you choose the wave files you want to change the speed.
 * The speed of the changed music files will be x times faster than the original, where x is the 
 * number you chose. Note that x can be lower than 1, so if you choose a number between 0 and 1 (0,1)
 * the new file(s) will have lower speed. For example if you choose to change speed 0.5, the new file(s)
 * will be 2 times slower.
 * e.g.
 * ./wavengine -changeSpeed 2 piano.wav
 * Results: if piano.wav is in the same folder as wavengine, a new file will be created named "5-times-speed-changed-piano.wav" 
 * which is piano.wav 5 times faster
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas, Lampros Dionysiou
 * 
 */
#include "changeSpeed.h"

int speedChange(char const* fileName, char* speedChange) {
    float speedChangeNum = atof(speedChange);
    if (speedChangeNum <= 0) {
        printf("The speed must be a value greater than 0\n");
        return EXIT_FAILURE;
    }
    if (speedChangeNum >= 100000) {
        printf("The speed must be a value lower than 100000\n");
        return EXIT_FAILURE;
    }
    char* timesChanged = (char*) malloc((strlen(speedChange) + 22) * sizeof(char));
    // <strlen(speedChange)>-times-speed-changed-\0 is 22 characters + strlen(speedChange)
    strcpy(timesChanged, speedChange);
    strcat(timesChanged, "-times-speed-changed-");
    char* newFileName = (char*) malloc(strlen(fileName) + strlen(timesChanged)); 
    MUSIC_FILE* musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    musicFile -> fmtSub -> sampleRate *= speedChangeNum; // changing speed

    if (changedName(newFileName, fileName, timesChanged) == EXIT_FAILURE) return EXIT_FAILURE;
    if (writeFile(musicFile, newFileName) == EXIT_FAILURE) return EXIT_FAILURE;
    free(newFileName);
    free(timesChanged);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

