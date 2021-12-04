#include"volChange.h"

int changeVol(MUSIC_FILE* musicFile, char* fileName, short percentageChange) {
    float change = percentageChange / 100;
    int i, newValue;
    for (i = 0; i < musicFile -> size; i++)
        {
            newValue = (*(musicFile -> data + i)) * change + *(musicFile -> data + i);
            if (newValue > 255) 
            // if new value is bigger than FF (highest of a byte) 
                newValue = 255;
            *(musicFile -> data + i) = newValue;
        }

    char* newFileName = (char*) malloc((strlen(fileName) + 31) * sizeof(char));
    // we add 29 because that's the size of ./as4-supplementary/volChange-\0
    strcat(newFileName, "./as4-supplementary/volChange-");
    strcat(newFileName, fileName);
    FILE* fp = NULL;
    if (!(fp = fopen(newFileName, "wb"))) {
        printf("Cannot create reverse file\n");
        return EXIT_FAILURE;
    }

    if (writeRiff(musicFile -> riff, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(musicFile -> fmtSub, sizeof(FMT_SUB), 1, fp);
    if (writeDataSub(musicFile -> dataSub, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(musicFile -> data, sizeof(byte), musicFile -> size, fp);
    fclose(fp);

    return EXIT_SUCCESS;
}

#ifdef DEBUG_VOL_CHANGE
int main()
{
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    char* fileName = "piano.wav";
    char* fullFileName = (char*) malloc(((strlen(fileName) + 21) * sizeof(char))); 
    // 20 is for "./as4-supplementary/\0"
    strcat(fullFileName, "./as4-supplementary/");
    strcat(fullFileName, fileName);
    if (readHeaderAndData(musicFile, fullFileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return -1;
    }
    free(fullFileName);
    if (changeVol(musicFile, fileName, 200) == EXIT_FAILURE) return -1;
}
#endif