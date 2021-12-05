/**
 * @file mix.c
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief The implemenation of mix.h file.
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021 Lampros Dionysiou.
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
#include "mix.h"

int changeMixedData(MUSIC_FILE *newFile, MUSIC_FILE *file1, MUSIC_FILE *file2)
{
    if (newFile->fmtSub->bitsPerSample == 8)
        for (int i = 0, j = 0; i < newFile->size; j += 2, i += 2)
        {
            newFile->data[i] = file1->data[j];
            newFile->data[i + 1] = file2->data[j + 1];
        }
    else if (newFile->fmtSub->bitsPerSample == 16)
        for (int i = 0, j = 0; i < newFile->size; j += 4, i += 4)
        {
            newFile->data[i] = file1->data[j];
            newFile->data[i + 1] = file1->data[j + 1];
            newFile->data[i + 2] = file2->data[j + 2];
            newFile->data[i + 3] = file2->data[j + 3];
        }
    else
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int saveMixedFiles(MUSIC_FILE *newFile, char const *filename1, char const *filename2)
{
    if(!newFile || !filename1 || !filename2)
        return EXIT_FAILURE;
    char *newFilename = (char *)malloc(strlen(filename1) + strlen(filename2) + 5);
    // mix-<strlen(filename1)>-<strlen(filename2)>
    if (!newFilename)
        return EXIT_FAILURE;
    if(changedName(newFilename, filename1, "mix-") == EXIT_FAILURE){
        free(newFilename);
        return EXIT_FAILURE;
    }
    newFilename[strlen(newFilename) - 4] = '\0';
    // deleting ".wav" extention
    if(!strcat(newFilename, "-")){ // adds '-'
        free(newFilename);
        return EXIT_FAILURE;
    }
    char *tempFilename2 = (char *)filename2;
    if(changedName(tempFilename2, filename2, "") == EXIT_FAILURE){ // removing slashes
        free(newFilename);
        return EXIT_FAILURE;
    }
    if(!strcat(newFilename, tempFilename2)){
        free(newFilename);
        return EXIT_FAILURE;
    }
    if(writeFile(newFile, newFilename) == EXIT_FAILURE){
        free(newFilename);
        return EXIT_FAILURE;
    }
    free(newFilename);
    return EXIT_SUCCESS;
}

int mix(char const *filename1, char const *filename2)
{
    if (!filename1 || !filename2)
        return EXIT_FAILURE;
    MUSIC_FILE *file1 = (MUSIC_FILE *)malloc(sizeof(MUSIC_FILE));
    MUSIC_FILE *file2 = (MUSIC_FILE *)malloc(sizeof(MUSIC_FILE));
    if(!file1 || !file2 || readHeaderAndData(file1, filename1) == EXIT_FAILURE || readHeaderAndData(file2, filename2) == EXIT_FAILURE){
        printf("Failed to read the audio files.\n");
        freeMusicFile(file1);
        freeMusicFile(file2);
        return EXIT_FAILURE;
    }
    if (file1->fmtSub->numChannels == 1 || file2->fmtSub->numChannels == 1){
        printf("Audio files must be stereo.\n");
        freeMusicFile(file1);
        freeMusicFile(file2);
        return EXIT_FAILURE;
    }
    if (file1->fmtSub->bitsPerSample != file2->fmtSub->bitsPerSample){
        printf("Audio files must have the same Bits Per Sample.\n");
        freeMusicFile(file1);
        freeMusicFile(file2);
        return EXIT_FAILURE;
    }
    //Create new music file
    MUSIC_FILE *newFile = (MUSIC_FILE *)malloc(sizeof(MUSIC_FILE));
    if (!newFile){
        printf("Failed to allocated memory for new music file.\n");
        freeMusicFile(file1);
        freeMusicFile(file2);
        return EXIT_FAILURE;
    }
    //Change Header
    if(file1->size < file2->size){
        if(copyHeader(file1, newFile) == EXIT_FAILURE){
            printf("Failed to create new audio header.\n");
            freeMusicFile(file1);
            freeMusicFile(file2);
            freeMusicFile(newFile);
            return EXIT_FAILURE;
        }
    }
    else{
        if(copyHeader(file2, newFile) == EXIT_FAILURE){
            printf("Failed to create new audio header.\n");
            freeMusicFile(file1);
            freeMusicFile(file2);
            freeMusicFile(newFile);
            return EXIT_FAILURE;
        }
    }
    //Change Data
    newFile->data = (byte *)malloc(newFile->size);
    if (!newFile->data || changeMixedData(newFile, file1, file2) == EXIT_FAILURE){
        printf("Failed to mix the two files.\n");
        freeMusicFile(file1);
        freeMusicFile(file2);
        freeMusicFile(newFile);
        return EXIT_FAILURE;
    }
    //Save to file
    if(saveMixedFiles(newFile, filename1, filename2) == EXIT_FAILURE){
        printf("Failed to create the new output file.\n");
        freeMusicFile(file1);
        freeMusicFile(file2);
        freeMusicFile(newFile);
        return EXIT_FAILURE;
    }
    freeMusicFile(file1);
    freeMusicFile(file2);
    freeMusicFile(newFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_MIX
int main()
{
    char name2[] = "./as4-supplementary/piano.wav";
    char name1[] = "./as4-supplementary/LRMonoPhase4.wav";
    mix(name1, name2);
}
#endif
