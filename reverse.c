#include "reverse.h"

int copyReverseData(MUSIC_FILE* target, byte* data) {
    int size = target -> size;
    if (!(target -> data = (byte*) malloc(size * sizeof(byte)))) {
        printf("Cannot allocate space \n");
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

int createReverseFile(MUSIC_FILE* musicFile, char const *newFileName) {
    MUSIC_FILE* reverseMusicFile = NULL;
    if (!(reverseMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    if (copyHeader(musicFile, reverseMusicFile) == EXIT_FAILURE) return EXIT_FAILURE;
    if (copyReverseData(reverseMusicFile, musicFile -> data) == EXIT_FAILURE) return EXIT_FAILURE;

    FILE* fp = NULL;
    if (!(fp = fopen(newFileName, "wb"))) {
        printf("Cannot create reverse file\n");
        return EXIT_FAILURE;
    }

    if (writeRiff(reverseMusicFile -> riff, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(reverseMusicFile -> fmtSub, sizeof(FMT_SUB), 1, fp);
    if (writeDataSub(reverseMusicFile -> dataSub, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(reverseMusicFile -> data, sizeof(byte), reverseMusicFile -> size, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int reverse(char const* fileName) {
    char* newFileName = (char*) malloc(strlen(fileName) + 9 * sizeof(char)); 
    //reverse-\0 is 9 characters
    MUSIC_FILE* reverseMusicFile = NULL;
    if (!(reverseMusicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE)))) return EXIT_FAILURE;
    printf("%s\n", fileName);
    if (changedName(newFileName, fileName, "reverse-") == EXIT_FAILURE) return EXIT_FAILURE;
    printf("%s\n", newFileName);
    if (readHeaderAndData(reverseMusicFile, fileName) == EXIT_FAILURE) {
        printf("Failed to read music file\n");
        return EXIT_FAILURE;
    }
    if (createReverseFile(reverseMusicFile, newFileName) == EXIT_FAILURE) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

#ifdef DEBUG_REVERSE
int main()
{
    
}
#endif