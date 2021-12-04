#include "wavengine.h"

void printWrongInput() {
    printf("Valid inputs are:\n");
    printf("./wavengine -list <wave file(s)>\n");
    printf("This option prints the details of the given music file(s)\n\n");
    printf("./wavengine -mono <wave file(s)>\n");
    printf("This option change music file(s) from stereo to mono\n\n");
    printf("./wavengine -mix <wave file 1> <wave file 2>\n");
    printf("This option mix the two wave files into one\n\n");
    printf("./wavengine -chop <wave file> <start second> <end second>\n");
    printf("This option cuts the given music file and from the start second to the end second\n\n");
    printf("./wavengine -reverse <wave file(s)>\n");
    printf("This option reverses the given music files\n\n");
    printf("./wavengine -encodeText <wave file> <text to encode>\n");
    printf("This option encodes the given text to the given wave file\n\n");
    printf("./wavengine -decodeText <wave file> <message length> <output file>\n");
    printf("This option decodes the given music file and prints the hidden message with the given length to the output file\n\n");
    printf("./wavenging -changeSpeed <number to be multiplied> <wave file(s)>\n");
    printf("This option multiplies the speed of the given music file(s) with the given number\n\n");
    printf("./wavengine -volChange <number to be multiplied> <wave file(s)>\n");
    printf("This option multiplies the volume of the given music file(s) by the number given\n\n");

    printf("./wavengine -man\nThis options prints this message\n\n");
    printf("NOTE: All options do not change the music files, they create new music files (except -list, -encode, -decode)\n");
}

int main(int argc, char const *argv[])
{
    int i;
    if (argc < 3)
    {
        printWrongInput();
        exit(-1);
    }
    if (strcmp(argv[1], "-list") == 0) // if the argument is "-list"
        for (i = 2; i < argc; i++)
        {
            printList(argv[i]);
            if (i != argc - 1)
                printf("************************************\n");
        }
    else if (strcmp(argv[1], "-mono") == 0)
    { // if the argument is "-mono"
        for (i = 2; i < argc; i++)
            if (stereoToMono(argv[i]) == EXIT_FAILURE)
                exit(-1);
    }

    else if (strcmp(argv[1], "-mix") == 0)
    { // if the argument is "-mix"
        if (argc < 4)
        {
            printf("Too few arguments\n");
            exit(-1);
        }
        else if (argc > 4)
        {
            printf("Too many arguments\n");
            exit(-1);
        }
        else if (mix(argv[2], argv[3]) == EXIT_FAILURE)
            exit(-1);
    }

    else if (strcmp(argv[1], "-chop") == 0) // if the argument is "-chop"
    {
        if (argc < 5)
        {
            printf("Too few arguments\n");
            exit(-1);
        }
        else if (argc > 5)
        {
            printf("Too many arguments\n");
            exit(-1);
        }
        else if (chop(argv[2], atoi(argv[3]), atoi(argv[4])) == EXIT_FAILURE) // atoi method casts to integer
            exit(-1);
    }
    else if (strcmp(argv[1], "-reverse") == 0)
    { // if the argument is "-reverse"
        for (i = 2; i < argc; i++)
            if (reverse(argv[i]) == EXIT_FAILURE)
                exit(-1);
    }
    else if (strcmp(argv[1], "-encodeText") == 0)
    { // if the argument is "-encodeText"
        if (argc < 4)
        {
            printf("Too few arguments\n");
            exit(-1);
        }
        else if (argc > 4)
        {
            printf("Too many arguments\n");
            exit(-1);
        }
        else if (encryption(argv[2], argv[3]) == EXIT_FAILURE)
            exit(-1);
    }
    else if (strcmp(argv[1], "-decodeText") == 0)
    { // if the argument is "-decodeText"
        if (argc < 5)
        {
            printf("Too few arguments\n");
            exit(-1);
        }
        else if (argc > 5)
        {
            printf("Too many arguments\n");
            exit(-1);
        }
        else if (decryption(argv[2], atoi(argv[3]), argv[4]) == EXIT_FAILURE)
            exit(-1);
    }
    else if (strcmp(argv[1], "-changeSpeed") == 0)
    { // if the argument is "-changeSpeed"
        if (argc < 4)
        {
            printf("Give the speed change (value from 0 to 100000, 0 and 100000 not included) and then the wav file(s) to change\n");
            exit(-1);
        }
        char *speedToChange = (char *)argv[2];
        for (i = 3; i < argc; i++)
            if (speedChange(argv[i], speedToChange) == EXIT_FAILURE)
                exit(-1);
    }
    else if (strcmp(argv[1], "-volChange") == 0) 
    { // if the argument is "-volChange"
        if (argc < 4)
        {
            printf("Give the volume change (value greater or equal to 0) and then the wav file(s) to change\n");
            exit(-1);
        }
        char *volToChange = (char *)argv[2];
        for (i = 3; i < argc; i++)
            if (changeVol(argv[i], volToChange) == EXIT_FAILURE)
                exit(-1);
    }
    else  // wrong input or chose -man
        printWrongInput();
    
    return 0;
}
