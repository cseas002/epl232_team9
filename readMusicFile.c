#include "header.h"
#include "readMusicFile.h"

int readHeaderAndData(MUSIC_FILE* musicFile, char* fileName) {
    FILE* fp = NULL;
    if (!(fp = fopen(fileName, "rb"))) return EXIT_FAILURE;
    if (!(musicFile -> riff = (RIFF*) malloc(sizeof(RIFF)))) return EXIT_FAILURE;
    fread(musicFile -> riff, sizeof(RIFF), 1, fp);
    if (!(musicFile -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB)))) return EXIT_FAILURE;
    fread(musicFile -> fmtSub, sizeof(FMT_SUB), 1, fp);
    if (!(musicFile -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB)))) return EXIT_FAILURE;
    fread(musicFile -> dataSub, sizeof(DATA_SUB), 1, fp);
    musicFile -> size = musicFile -> dataSub -> subChunk2Size;
    if (!(musicFile -> data = (byte*) malloc(musicFile -> size))) return EXIT_FAILURE;
    fread(musicFile -> data, sizeof(byte), musicFile -> size, fp);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_MUSIC_FILE
int main()
{
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    readHeaderAndData(musicFile, " ");
    printMusicFile(musicFile);
    return 0;
}
#endif
