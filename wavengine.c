#include "header.h"
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mix.h"
#include "stereoToMono.h"

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
    else if (strcmp(argv[1], "-mono") == 0) // if the argument is "-mono"
        for (i = 2; i < argc; i++) {
            stereoToMono(argv[i]);
        }
    return 0;
}
