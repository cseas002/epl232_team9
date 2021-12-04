#include"volChange.h"

int changeVol(char const *fileName, char* changeStr) {
    float change = atof(changeStr);
    printf("%f\n", change);
    if (change < 0) {
        printf("The change value must be greater or equal than 0\n");
        return EXIT_FAILURE;
    }
    int i;
    double newValue;
    char* newFileName = (char*) malloc(strlen(fileName) + 12 * sizeof(char)); 
    // volChanged-\0 is 12 characters
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

    if (changedName(newFileName, fileName, "volChanged-") == EXIT_FAILURE) return EXIT_FAILURE;
    if (writeFile(musicFile, newFileName) == EXIT_FAILURE) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

#ifdef DEBUG_VOL_CHANGE
int main()
{
    
}
#endif