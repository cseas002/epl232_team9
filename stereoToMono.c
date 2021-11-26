#include "stereoToMono.h"

int copy(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile){
    *newFile->riff = *musicFile->riff;
    *newFile->fmtSub = *musicFile->fmtSub;
    *newFile->dataSub = *musicFile->dataSub;
    newFile->data = (byte*) malloc(newFile->size);
    if(!newFile->data) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int changeHeader(MUSIC_FILE *newFile){
    newFile->dataSub->subChunk2Size = newFile->dataSub->subChunk2Size/2;
    newFile->size = newFile->size/2;
    newFile->riff->chunkSize = newFile->size+36;
    newFile->fmtSub->numChannels = 1;
    newFile->fmtSub->byteRate = newFile->fmtSub->sampleRate * newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    newFile->fmtSub->blockAlign = newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    newFile->dataSub->subChunk2Size = newFile->size * newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
}

int changeData(MUSIC_FILE *musicFile, MUSIC_FILE *newFile){
    if(musicFile->fmtSub->bitsPerSample == 8)
        for(int i = 0, j=0; i < newFile->size; i++, j+=2)
            newFile->data[i] = musicFile->data[j];
    else
        for(int i = 0, j=0; i < newFile->size; i+=2, j+=4){
            newFile->data[i] = musicFile->data[j];
            newFile->data[i+1] = musicFile->data[j+1];
        }
}

int saveToFile(MUSIC_FILE *newFile, char *filename){
    char *newFilename = (char*) malloc(strlen(filename)+6);
    if(!newFilename) return EXIT_FAILURE;
    if(!strcpy(newFilename, "mono-")) return EXIT_FAILURE;
    if(!strcat(newFilename, filename)) return EXIT_FAILURE;
    FILE *fp = fopen(newFilename, "wb");
    free(newFilename);
    if(!fp) return EXIT_FAILURE;
    fwrite(newFile->riff, sizeof(RIFF), 1, fp);
    fwrite(newFile->fmtSub, sizeof(FMT_SUB), 1, fp);
    fwrite(newFile->dataSub, sizeof(DATA_SUB), 1, fp);
    fwrite(newFile->data, sizeof(byte), newFile->size, fp);
    fclose(fp);
}

int stereoToMono(MUSIC_FILE* musicFile, char* fileName){
    if(!musicFile || !fileName) return EXIT_FAILURE;
    MUSIC_FILE *newFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if (!newFile) return EXIT_FAILURE;
    newFile->riff = (RIFF*) malloc(sizeof(RIFF));
    newFile->fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB));
    newFile->dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB));
    newFile->size = musicFile->size;
    newFile->data = (byte*) malloc(newFile->size);
    if(!newFile->riff || !newFile->fmtSub || !newFile->dataSub || !newFile->data)
        return EXIT_FAILURE;
    copy(musicFile, newFile);
    changeHeader(newFile);
    changeData(musicFile, newFile);
    saveToFile(newFile, fileName);
}

#ifdef DEBUG
    int main(){
        char name[] = "LRMonoPhase4.wav";
        MUSIC_FILE *musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
        readHeaderAndData(musicFile, name);
        stereoToMono(musicFile, name);
    }
#endif