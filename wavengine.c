#include "header.h"
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mix.h"
#include "stereoToMono.h"
#include "chop.h"
#include "reverse.h"
#include "encryption.h"
#include "decryption.h"
#include "changeSpeed.h"

int main(int argc, char const *argv[])
{
    int i;
    if (argc < 3)
        {
            printf("Too few arguments\n");
            exit(-1);
        }
    if (strcmp(argv[1], "-list") == 0) // if the argument is "-list"
        for (i = 2; i < argc; i++) {
            printList(argv[i]);
            if (i != argc - 1)
                printf("************************************\n");
        }
    else if (strcmp(argv[1], "-mono") == 0) { // if the argument is "-mono"
        for (i = 2; i < argc; i++) 
            if (stereoToMono(argv[i]) == EXIT_FAILURE) exit(-1);}
    
    else if (strcmp(argv[1], "-mix") == 0) { // if the argument is "-mix"
        if (argc < 4){
                printf("Too few arguments\n");
                exit(-1);
            }    
            else if (argc > 4){
                printf("Too many arguments\n");
                exit(-1);
            } 
            else
                if (mix(argv[2], argv[3]) == EXIT_FAILURE) exit(-1);
    }
        
    else if (strcmp(argv[1], "-chop") == 0) // if the argument is "-chop"
        {
            if (argc < 5){
                printf("Too few arguments\n");
                exit(-1);
            }    
            else if (argc > 5){
                printf("Too many arguments\n");
                exit(-1);
            } 
            else
                if (chop(argv[2], atoi(argv[3]), atoi(argv[4])) == EXIT_FAILURE) // atoi method casts to integer
                    exit(-1);
            
        }
    else if (strcmp(argv[1], "-reverse") == 0) { // if the argument is "-reverse"
        for (i = 2; i < argc; i++) 
            if (reverse(argv[i]) == EXIT_FAILURE) exit(-1);
    }
    else if (strcmp(argv[1], "-encodeText") == 0) { // if the argument is "-encodeText"
    if (argc < 4){
                printf("Too few arguments\n");
                exit(-1);
            }    
            else if (argc > 4){
                printf("Too many arguments\n");
                exit(-1);
            } 
            else if (encryption(argv[2], argv[3]) == EXIT_FAILURE) exit(-1);
    }
    else if (strcmp(argv[1], "-decodeText") == 0) { // if the argument is "-decodeText"
    if (argc < 5){
                printf("Too few arguments\n");
                exit(-1);
            }    
            else if (argc > 5){
                printf("Too many arguments\n");
                exit(-1);
            } 
            else if (decryption(argv[2], atoi(argv[3]), argv[4]) == EXIT_FAILURE) exit(-1);
    }
    else if (strcmp(argv[1], "-changeSpeed") == 0) { // if the argument is "-changeSpeed"
        if (argc < 4) {
            printf("Give the speed change (value from 0 - 100000) and then the wav files to change\n");
            exit(-1);
        }
        char* speedToChange = (char*) argv[2];
        for (i = 3; i < argc; i++) 
            if (speedChange(argv[i], speedToChange) == EXIT_FAILURE) exit(-1);

    }
    return 0;
}
