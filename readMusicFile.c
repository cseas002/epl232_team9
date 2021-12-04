#include "readMusicFile.h"

int copyHeader(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile){
    if (!((newFile -> riff = (RIFF*) malloc(sizeof(RIFF))) &&
     (newFile -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB))) && 
     (newFile -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB))))) {
        printf("Cannot allocate space for reverse file\n");
        return EXIT_FAILURE;
    }
    *newFile->riff = *musicFile->riff;
    *newFile->fmtSub = *musicFile->fmtSub;
    *newFile->dataSub = *musicFile->dataSub;
    newFile->size = musicFile->size;
    return EXIT_SUCCESS;
}

int readHeaderAndData(MUSIC_FILE* musicFile, char const *fileName) {
    FILE* fp = NULL;
    if (!(fp = fopen(fileName, "rb"))) return EXIT_FAILURE;
    if (!(musicFile -> riff = (RIFF*) malloc(sizeof(RIFF)))) return EXIT_FAILURE;
    if(fread(musicFile -> riff, sizeof(RIFF), 1, fp)!=1) return EXIT_FAILURE;
    if (!(musicFile -> fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB)))) return EXIT_FAILURE;
    if(fread(musicFile -> fmtSub, sizeof(FMT_SUB), 1, fp)!=1) return EXIT_FAILURE;
    if (!(musicFile -> dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB)))) return EXIT_FAILURE;
    if(fread(musicFile -> dataSub, sizeof(DATA_SUB), 1, fp)!=1) return EXIT_FAILURE;
    musicFile -> size = musicFile -> dataSub -> subChunk2Size;
    if (!(musicFile -> data = (byte*) malloc(musicFile -> size))) return EXIT_FAILURE;
    if(fread(musicFile -> data, sizeof(byte), musicFile -> size, fp)!=musicFile->size) return EXIT_FAILURE;
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
