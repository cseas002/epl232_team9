/**
 * @file header.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief Header file that includes the structures necessary for the
 * implementation of the WAV Engine program, some key C libraries and
 * the constants used by the program.
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

/**
 * @typedef byte
 * @brief Byte is 8 bits. Used for simplicity. 
 * 
 */
typedef unsigned char byte;

/**
 * @typedef word
 * @brief Word is 2 bytes (16 bits). Used for simplicity.
 * 
 */
typedef unsigned short int word;

/**
 * @typedef dword
 * @brief Double Word is 4 bytes (32 bits). Used for simplicity.
 * 
 */
typedef unsigned int dword;

/**
 * @struct RIFF
 * @brief Riff Chunk Descriptor. The first part of the audio file's header.
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
 * @struct FMT_SUB
 * @brief FMT Sub-Chunk. The second part of the audio file's header.
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
 * @struct DATA_SUB
 * @brief Data Sub-Chunk Header. The third part of the audio file's header.
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
 * @struct MUSIC_FILE
 * @brief The Audio File containg both header and data.
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

