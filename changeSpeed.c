/**
 * @file changeSpeed.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @brief The implementation of changeSpeed.h file.
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
 * 
 */
#include "changeSpeed.h"

int speedChange(char const *fileName, char *speedChange)
{
    float speedChangeNum = atof(speedChange);
    if (speedChangeNum <= 0)
    {
        printf("The speed must be a value greater than 0\n");
        return EXIT_FAILURE;
    }
    if (speedChangeNum >= 100000)
    {
        printf("The speed must be a value lower than 100000\n");
        return EXIT_FAILURE;
    }
    char *timesChanged = (char *)malloc((strlen(speedChange) + 22) * sizeof(char));
    // <strlen(speedChange)>-times-speed-changed-\0 is 22 characters + strlen(speedChange)
    strcpy(timesChanged, speedChange);
    strcat(timesChanged, "-times-speed-changed-");
    char *newFileName = NULL;
    newFileName = (char *)malloc(strlen(fileName) + 1 + strlen(timesChanged));
    if (!newFileName)
        return EXIT_FAILURE;
    MUSIC_FILE *musicFile = NULL;
    musicFile = (MUSIC_FILE *)malloc(sizeof(MUSIC_FILE));
    if (!musicFile)
    {
        free(newFileName);
        return EXIT_FAILURE;
    }
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE)
    {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    musicFile->fmtSub->sampleRate *= speedChangeNum; // changing speed

    if (changedName(newFileName, fileName, timesChanged) == EXIT_FAILURE)
    {
        freeMusicFile(musicFile);
        free(timesChanged);
        return EXIT_FAILURE;
    }
    if (writeFile(musicFile, newFileName) == EXIT_FAILURE)
    {
        free(timesChanged);
        freeMusicFile(musicFile);
        return EXIT_FAILURE;
    }

    free(newFileName);
    free(timesChanged);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_CHANGESPEED
int main()
{
    printf("Save the piano.wav file in the as4-supplementary sub folder in order to work!\n");
    speedChange("./as4-supplementary/piano.wav", "2");
    printf("Doublying the speed of piano.wav file ...Done!\n");
    speedChange("./as4-supplementary/piano.wav", "0.5");
    printf("Halvling the speed of piano.wav file (make it 2 times slower) ...Done!\n");
    return 0;
}
#endif
