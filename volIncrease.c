#include "volIncrease.h"

int changeVol(char const *fileName, char* changeStr) {
    float change = atof(changeStr);
    if (change < 1) {
        printf("The change value must be greater or equal than 1\n");
        return EXIT_FAILURE;
    }
    int i;
    double newValue;
    char* volIncreaseStr = (char*) malloc((strlen(changeStr) + 23) * sizeof(char));
    // <strlen(changeStr)>-times-volIncreased-\0 is 23 bytes + strlen(changeStr)
    strcpy(volIncreaseStr, changeStr);
    strcat(volIncreaseStr, "-times-vol-increased-");
    char* newFileName = (char*) malloc(strlen(fileName) + strlen(volIncreaseStr) + 1); 
    MUSIC_FILE* musicFile = NULL;
    if (!(musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < musicFile -> size; i++)
        {
            newValue = ((double) (*(musicFile -> data + i))) * change;
            if (newValue > 255) 
            // if new value is bigger than FF (highest of a byte) 
                newValue = 255;
            *(musicFile -> data + i) = (byte) newValue;
        }
    if (changedName(newFileName, fileName, volIncreaseStr) == EXIT_FAILURE) return EXIT_FAILURE;
    if (writeFile(musicFile, newFileName) == EXIT_FAILURE) return EXIT_FAILURE;
    free(newFileName);
    free(volIncreaseStr);
    freeMusicFile(musicFile);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_VOL_CHANGE
int main()
{
    printf("Save the piano.wav file in the as4-supplementary sub folder in order to work!\n");
    changeVol("./as4-supplementary/piano.wav", "2");
    printf("Doublying the volume of piano.wav file ...Done!\n");
    return 0;
}
#endif
