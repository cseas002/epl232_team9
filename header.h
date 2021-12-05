/**
 * @file header.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
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

typedef struct {
    char chunkID[4];
    dword chunkSize;
    char format[4];
} __attribute__((packed)) RIFF;

typedef struct {
    char subChunk1ID[4];
    dword subChunk1Size;
    word audioFormat;
    word numChannels;
    dword sampleRate;
    dword byteRate;
    word blockAlign;
    word bitsPerSample;
}__attribute__((packed)) FMT_SUB;

typedef struct{
    char subChunk2ID[4];
    dword subChunk2Size;
}__attribute__((packed)) DATA_SUB;

typedef struct {
    RIFF* riff;
    FMT_SUB* fmtSub;
    DATA_SUB* dataSub;
    byte* data;
    dword size; // subChunk2Size just for simplicity
}__attribute__((packed)) MUSIC_FILE;
#endif

