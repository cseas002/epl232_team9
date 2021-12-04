#include"mix.h"

int changeMixedData(MUSIC_FILE *newFile, MUSIC_FILE *file1, MUSIC_FILE *file2){
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

int saveMixedFiles(MUSIC_FILE *newFile, char const *filename1, char const *filename2){
    char *changed1 = (char*) malloc(strlen(filename1)+1);
    if(!changed1) return EXIT_FAILURE;
    char *changed2 = (char*) malloc(strlen(filename2)+1);
    if(!changed2) return EXIT_FAILURE;
    changedName(changed1, filename1, "mix-");
    changedName(changed2, filename2, "");
    char *newFilename = (char*) malloc(strlen(changed1)+strlen(changed2)+1);
    if(!newFilename) return EXIT_FAILURE;
    if(!strncpy(newFilename, changed1, strlen(changed1)-4)) return EXIT_FAILURE;
    if(!strcat(newFilename, "-")) return EXIT_FAILURE;
    if(!strcat(newFilename, changed2)) return EXIT_FAILURE;
    writeFile(newFile, newFilename);
    return EXIT_SUCCESS;
}

int mix(char const *filename1, char const *filename2){
     if(!filename1 || !filename2) return EXIT_FAILURE;
    MUSIC_FILE *file1 = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    readHeaderAndData(file1, filename1);
    MUSIC_FILE *file2 = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    readHeaderAndData(file2, filename2);
    if(file1->fmtSub->numChannels == 1 || file2->fmtSub->numChannels == 1) return EXIT_FAILURE;
    if(file1->fmtSub->bitsPerSample != file2->fmtSub->bitsPerSample) return EXIT_FAILURE;
    //Create new music file
    MUSIC_FILE *newFile = (MUSIC_FILE*) malloc(sizeof(MUSIC_FILE));
    if (!newFile) return EXIT_FAILURE;
    //Change Header

    (file1->size < file2->size) ? (copyHeader(file1, newFile)) : (copyHeader(file2, newFile));
    //Change Data
    newFile->data = (byte*) malloc(newFile->size);
    if(!newFile->data)
        return EXIT_FAILURE;
    changeMixedData(newFile, file1, file2);
    //Save to file
    saveMixedFiles(newFile, filename1, filename2);
    return EXIT_SUCCESS;
}

#ifdef DEBUG_MIX
    int main(){
        char name2[] = "./as4-supplementary/piano.wav";
        char name1[] = "./as4-supplementary/LRMonoPhase4.wav";
        mix(name1, name2);
    }
#endif

