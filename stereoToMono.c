#include "stereoToMono.h"

int changeHeader(MUSIC_FILE *newFile){
    newFile->dataSub->subChunk2Size = newFile->dataSub->subChunk2Size/2;
    newFile->size = newFile->size/2;
    newFile->riff->chunkSize = newFile->size+36;
    newFile->fmtSub->numChannels = 1;
    newFile->fmtSub->byteRate = newFile->fmtSub->sampleRate * newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    newFile->fmtSub->blockAlign = newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    newFile->dataSub->subChunk2Size = newFile->size * newFile->fmtSub->numChannels * newFile->fmtSub->bitsPerSample/8;
    return EXIT_SUCCESS;
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
    return EXIT_SUCCESS;
}

int saveToFile(MUSIC_FILE *newFile, char const *filename){
    char *newFilename = (char*) malloc(strlen(filename)+6);
    if(!newFilename) return EXIT_FAILURE;
    if(!strcpy(newFilename, "mono-")) return EXIT_FAILURE;
    if(!strcat(newFilename, filename)) return EXIT_FAILURE;
    FILE *fp = fopen(newFilename, "wb");
    free(newFilename);
    if(!fp) return EXIT_FAILURE;
    writeRiff(newFile->riff, fp);
    writeDataSub(newFile->dataSub, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int stereoToMono(char const *fileName){
    MUSIC_FILE* musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if(!musicFile || !fileName) return EXIT_FAILURE;
    if (readHeaderAndData(musicFile, fileName) == EXIT_FAILURE) return EXIT_FAILURE;
    MUSIC_FILE *newFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if (!newFile) return EXIT_FAILURE;
    //Header
    newFile->riff = (RIFF*) malloc(sizeof(RIFF));
    newFile->fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB));
    newFile->dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB));
    if(!newFile->riff || !newFile->fmtSub || !newFile->dataSub || copyHeader(musicFile, newFile) || changeHeader(newFile)) 
        return EXIT_FAILURE;
    //Data
    newFile->data = (byte*) malloc(newFile->size);
    if(!newFile->data || changeData(musicFile, newFile))
        return EXIT_FAILURE;
    //Save to file
    if(saveToFile(newFile, fileName))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

#ifdef DEBUG
    int main(){
        char name[] = "LRMonoPhase4.wav";
        MUSIC_FILE *musicFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
        readHeaderAndData(musicFile, name);
        stereoToMono(musicFile, name);
    }
#endif