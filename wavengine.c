/**
 * @file wavengine.c
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
 * This client program utilizes all the capabiltiies of epl232_team9 library.
 * It implements the wavengine.h file.
 * COMPILATION COMMAND: gcc -o wavengine wavengine.c epl232_team9.a
 * EXECUTION COMMAND: (see README.md)
 * @version 0.1
 * @date 2021-11-25 
 * 
 * @copyright Copyright (c) 2021 Christoforos Seas, Lampros Dionysiou.
 * This file is part of WAV Engine.
 * WAV Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * Υou should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 */
#include "wavengine.h"

void printInfo() {
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
    printf("./wavengine -encodeText <wave file> <input file with text to encode>\n");
    printf("This option encodes the given text (inside the input file) to the given wave file\n\n");
    printf("./wavengine -decodeText <wave file> <message length> <output file>\n");
    printf("This option decodes the given music file and prints the hidden message with the given length to the output file\n\n");
    printf("./wavenging -changeSpeed <number to be multiplied> <wave file(s)>\n");
    printf("This option multiplies the speed of the given music file(s) with the given number\n\n");
    printf("./wavengine -volIncrease <number to be multiplied> <wave file(s)>\n");
    printf("This option multiplies the volume of the given music file(s) by the number given\n\n");

    printf("./wavengine -man\nThis options prints this message\n\n");
    printf("NOTE: All options do not change the music files, they create new music files (except -list, -decode)\n");
}

int wavengine(int argc, char const *argv[])
{
    int i;
    if(argc == 2 && strcmp(argv[1], "-man")==0)
    {
        printInfo();
        return EXIT_SUCCESS;
    }
    if (argc < 3)
    {
        printf("Invalid command. Use ./%s -man to see the available options.\n", argv[0]);
        return EXIT_FAILURE;
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
                return EXIT_FAILURE;
    }

    else if (strcmp(argv[1], "-mix") == 0)
    { // if the argument is "-mix"
        if (argc < 4)
        {
            printf("Too few arguments\n");
            return EXIT_FAILURE;
        }
        else if (argc > 4)
        {
            printf("Too many arguments\n");
            return EXIT_FAILURE;
        }
        else if (mix(argv[2], argv[3]) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }

    else if (strcmp(argv[1], "-chop") == 0) // if the argument is "-chop"
    {
        if (argc < 5)
        {
            printf("Too few arguments\n");
            return EXIT_FAILURE;
        }
        else if (argc > 5)
        {
            printf("Too many arguments\n");
            return EXIT_FAILURE;
        }
        else if (chop(argv[2], atoi(argv[3]), atoi(argv[4])) == EXIT_FAILURE) // atoi method casts to integer
            return EXIT_FAILURE;
    }
    else if (strcmp(argv[1], "-reverse") == 0)
    { // if the argument is "-reverse"
        for (i = 2; i < argc; i++)
            if (reverse(argv[i]) == EXIT_FAILURE)
                return EXIT_FAILURE;
    }
    else if (strcmp(argv[1], "-encodeText") == 0)
    { // if the argument is "-encodeText"
        if (argc < 4)
        {
            printf("Too few arguments\n");
            return EXIT_FAILURE;
        }
        else if (argc > 4)
        {
            printf("Too many arguments\n");
            return EXIT_FAILURE;
        }
        else if (encryption(argv[2], argv[3]) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    else if (strcmp(argv[1], "-decodeText") == 0)
    { // if the argument is "-decodeText"
        if (argc < 5)
        {
            printf("Too few arguments\n");
            return EXIT_FAILURE;
        }
        else if (argc > 5)
        {
            printf("Too many arguments\n");
            return EXIT_FAILURE;
        }
        else if (decryption(argv[2], atoi(argv[3]), argv[4]) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    else if (strcmp(argv[1], "-changeSpeed") == 0)
    { // if the argument is "-changeSpeed"
        if (argc < 4)
        {
            printf("Give the speed change (value from 0 to 100000, 0 and 100000 not included) and then the wav file(s) to change\n");
            return EXIT_FAILURE;
        }
        char *speedToChange = (char *)argv[2];
        for (i = 3; i < argc; i++)
            if (speedChange(argv[i], speedToChange) == EXIT_FAILURE)
                return EXIT_FAILURE;
    }
    else if (strcmp(argv[1], "-volIncrease") == 0) 
    { // if the argument is "-volChange"
        if (argc < 4)
        {
            printf("Give the volume increase (value greater or equal to 1) and then the wav file(s) to change\n");
            return EXIT_FAILURE;
        }
        char *volToChange = (char *)argv[2];
        for (i = 3; i < argc; i++)
            if (changeVol(argv[i], volToChange) == EXIT_FAILURE)
                return EXIT_FAILURE;
    }
    else // wrong input or chose -man
    {
        printf("Invalid command. Use ./%s -man to see the available options.\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

#ifndef DEBUG_CHANGESPEED
#ifndef DEBUG_CHOP
#ifndef DEBUG_CRYPTOGRAPHY
#ifndef DEBUG_DECRYPTION
#ifndef DEBUG_ENCRYPTION
#ifndef DEBUG_LIST
#ifndef DEBUG_MIX
#ifndef DEBUG_READ_MUSIC_FILE
#ifndef DEBUG_REVERSE
#ifndef DEBUG_MONO
#ifndef DEBUG_VOL_CHANGE
#ifndef DEBUG_WRITE_MUSIC_FILE
int main(int argc, char const *argv[])
{
    int n = wavengine(argc, argv);
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    return n; // 1 for EXIT_FAILURE 0 for EXIT_SUCCESS
}

#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
