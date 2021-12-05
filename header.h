/**
 * @file header.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief This header file contains the structures and types of data which
 * are used from other programs. It also contains the system key number
 * which is used for encryption and decryption purposes.
 * @version 0.1
 * @date 2021-12-04
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
#ifndef HEADER
#define HEADER
#define SYSTEM_KEY_INTEGER 42069
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

/**
 * @brief RIFF structure
 * 
 */
typedef struct {
    char chunkID[4];
    dword chunkSize;
    char format[4];
} 
#ifndef DOXYGEN 
__attribute__((packed)) 
#endif
RIFF;

/**
 * @brief FMT_SUB structure
 * 
 */
typedef struct {
    char subChunk1ID[4];
    dword subChunk1Size;
    word audioFormat;
    word numChannels;
    dword sampleRate;
    dword byteRate;
    word blockAlign;
    word bitsPerSample;
}
#ifndef DOXYGEN 
__attribute__((packed)) 
#endif
FMT_SUB;

/**
 * @brief DATA_SUB structure
 * 
 */
typedef struct{
    char subChunk2ID[4];
    dword subChunk2Size;
}
#ifndef DOXYGEN 
__attribute__((packed)) 
#endif
DATA_SUB;

/**
 * @brief Complete music file structure.
 * This structure contains all other header structures and an 
 * array of bytes which is the data of the music file. It also
 * contains a dword named size, which is the amount of bytes 
 * in the data array.
 * 
 */
typedef struct {
    RIFF* riff;
    FMT_SUB* fmtSub;
    DATA_SUB* dataSub;
    byte* data;
    dword size; // subChunk2Size just for simplicity
}
#ifndef DOXYGEN 
__attribute__((packed)) 
#endif
MUSIC_FILE;
#endif

