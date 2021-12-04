#include "writeMusicFile.h"


// int writeRiff(RIFF* riff, FILE* fp) {
//     fwrite(riff -> chunkID, sizeof(char), 4, fp); // write "RIFF"
//     byte bytes[4];
//     int i = 0;
//     unsigned int getByte = (1 << 8) - 1;
//     for (i = 0; i < 4; i++)
//     {
//         // the first getByte will be 11111111, second 1111111100000000, etc.
//         bytes[i] = riff -> chunkSize & getByte;
//         // with this technique, we will save the least significant byte of chunkSize in 
//         // the first position and the most significant in the last position
//         getByte <<= 8;
//     }
//     fwrite((&riff -> chunkSize), sizeof(byte), 4, fp); // write chunkSize
//     fwrite(riff -> format, sizeof(char), 4, fp); // write "WAVE"
//     return EXIT_SUCCESS;
// }

// int writeDataSub(DATA_SUB* dataSub, FILE* fp){
//     fwrite(dataSub -> subChunk2ID, sizeof(char), 4, fp); // write "data"
//     byte bytes[4];
//     int i = 0;
//     unsigned int getByte = (1 << 8) - 1;
//     for (i = 0; i < 4; i++)
//     {
//         // the first getByte will be 11111111, second 1111111100000000, etc.
//         bytes[i] = dataSub -> subChunk2Size & getByte;
//         // with this technique, we will save the least significant byte of chunkSize in 
//         // the first position and the most significant in the last position
//         getByte <<= 8;
//     }
//     fwrite(&(dataSub -> subChunk2Size), sizeof(byte), 4, fp); // write sub chunk size
//     return EXIT_SUCCESS;
// }

int writeFile(MUSIC_FILE* musicFile, char const *newFileName) {
    FILE* fp = NULL;
    if (!(fp = fopen(newFileName, "wb"))) {
        printf("Cannot create new file\n");
        return EXIT_FAILURE;
    }

    // if (writeRiff(musicFile -> riff, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(musicFile -> riff, sizeof(RIFF), 1, fp);
    fwrite(musicFile -> fmtSub, sizeof(FMT_SUB), 1, fp);
    // if (writeDataSub(musicFile -> dataSub, fp) == EXIT_FAILURE) return EXIT_FAILURE;
    fwrite(musicFile -> dataSub, sizeof(DATA_SUB), 1, fp);
    fwrite(musicFile -> data, sizeof(byte), musicFile -> size, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int changedName(char* newFileName, char const *fileName, char* addition) { // addition = "-mono", "-chop", etc.
    char *changedFilename = (char*) malloc(strlen(fileName)+1);
    char *temp = changedFilename;
    if(strrchr(fileName, '/')){
        changedFilename = strrchr(fileName, '/');
        if(changedFilename[0]=='/') changedFilename++;
    } 
    else strcpy(changedFilename, fileName);
    if(!newFileName) return EXIT_FAILURE;
    if(!strcpy(newFileName, addition)) return EXIT_FAILURE;
    if(!strcat(newFileName, changedFilename)) return EXIT_FAILURE;
    free(temp);
    return EXIT_SUCCESS;
}
