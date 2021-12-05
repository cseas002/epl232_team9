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
