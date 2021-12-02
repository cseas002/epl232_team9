#include"mix.h"

int copyHeader(MUSIC_FILE  *musicFile, MUSIC_FILE *newFile){
    *newFile->riff = *musicFile->riff;
    *newFile->fmtSub = *musicFile->fmtSub;
    *newFile->dataSub = *musicFile->dataSub;
    newFile->size = musicFile->size;
    return EXIT_SUCCESS;
}

int changeData(MUSIC_FILE *newFile, MUSIC_FILE *file1, MUSIC_FILE *file2){
    if(newFile->fmtSub->bitsPerSample == 8)
        for(int i = 0, j=0; i < newFile->size; j+=2, i+=2){
            newFile->data[i] = file1->data[j];
            newFile->data[i+1] = file2->data[j+1];
        }
    else
        for(int i = 0, j=0; i < newFile->size; j+=4, i+=4){
            newFile->data[i] = file1->data[j];
            newFile->data[i+1] = file1->data[j+1];
            newFile->data[i+2] = file2->data[j+2];
            newFile->data[i+3] = file2->data[j+3];
        }
    return EXIT_SUCCESS;
}

int saveToFile(MUSIC_FILE *newFile, char *filename1, char *filename2){
    char *newFilename = (char*) malloc(strlen(filename1)+strlen(filename2)+1);
    if(!newFilename) return EXIT_FAILURE;
    if(!strcpy(newFilename, "mix-")) return EXIT_FAILURE;
    if(!strncat(newFilename, filename1, strlen(filename1)-4)) return EXIT_FAILURE;
    if(!strcat(newFilename, "-")) return EXIT_FAILURE;
    if(!strcat(newFilename, filename2)) return EXIT_FAILURE;
    FILE *fp = fopen(newFilename, "wb");
    free(newFilename);
    if(!fp) return EXIT_FAILURE;
    writeRiff(newFile->riff, fp);
    writeDataSub(newFile->dataSub, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int mix(MUSIC_FILE* file1, MUSIC_FILE *file2, char* filename1, char *filename2){
    if(!file1 || !file2 || !filename1 || !filename2) return EXIT_FAILURE;
    if(file1->fmtSub->numChannels == 1 || file2->fmtSub->numChannels == 1) return EXIT_FAILURE;
    if(file1->fmtSub->bitsPerSample != file2->fmtSub->bitsPerSample) return EXIT_FAILURE;
    //Create new music file
    MUSIC_FILE *newFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if (!newFile) return EXIT_FAILURE;
    //Change Header
    newFile->riff = (RIFF*) malloc(sizeof(RIFF));
    newFile->fmtSub = (FMT_SUB*) malloc(sizeof(FMT_SUB));
    newFile->dataSub = (DATA_SUB*) malloc(sizeof(DATA_SUB));
    if(!newFile->riff || !newFile->fmtSub || !newFile->dataSub)
        return EXIT_FAILURE;
    (file1->size < file2->size) ? (copyHeader(file1, newFile)) : (copyHeader(file2, newFile));
    //Change Data
    newFile->data = (byte*) malloc(newFile->size);
    if(!newFile->data)
        return EXIT_FAILURE;
    changeData(newFile, file1, file2);
    //Save to file
    saveToFile(newFile, filename1, filename2);
}

#ifdef DEBUG
    int main(){
        char name1[] = "LRMonoPhase4.wav";
        char name2[] = "piano.wav";
        MUSIC_FILE *musicFile1 = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
        readHeaderAndData(musicFile1, name1);
        MUSIC_FILE *musicFile2 = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
        readHeaderAndData(musicFile2, name2);
        mix(musicFile1, musicFile2, name1, name2);
    }
#endif

