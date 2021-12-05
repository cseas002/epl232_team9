/**
 * @file writeMusicFile.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief 
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
#ifndef WRITE_MUSIC_FILE
#define WRITE_MUSIC_FILE

#include "header.h"

/**
 * @brief Method that removes any prefixes from the given filename
 * and adds the given prefix (indicating the WAVEngineLib function).
 * For example if the given filename is ./folder1/folder2/audio.wav
 * and the prefix is 'mono', the new filename will be mono-audio.wav.
 * This method DOES NOT allocate memory for the new filename. The caller
 * of this method should allocate enough memory.
 * 
 * @param newFileName The new filename after change.
 * @param fileName The filename to by changed.
 * @param addition The new prefix
 * @return An exit code.
 */
int changedName(char* newFileName, char const *fileName, char* addition);

/**
 * @brief Method that creates a new file using the given filename and
 * exports the audio file in binary form. If the file already exists,
 * it will be overwritten.
 * 
 * @param musicFile The header and data of the audio file to be written.
 * @param newFileName The filename of the output file to be created.
 * @return An exit code.
 */
int writeFile(MUSIC_FILE* musicFile, char const *newFileName);

/**
 * @brief Method that frees the memory allocated for the music file's
 * header and data.
 * 
 * @param musicFile The header and data of the audio file.
 */
void freeMusicFile(MUSIC_FILE* musicFile);
#endif

