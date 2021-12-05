/**
 * @file encryption.h
 * @author Christoforos Seas (cseas002@ucy.ac.cy)
 * @author Lampros Dionysiou (ldiony01@ucy.ac.cy)
 * @brief This program encrypts a message into the audio file.
 * It reads the audio file provided and stores in random samples
 * a bit of the message. It then saves the output audio file
 * using the name encoded-<input filename>.wav.
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
#ifndef ENCRYPTION
#define ENCRYPTION
#include "cryptography.h"

/**
 * @brief Method that encrypts a message into an audio file. It reads
 * the header and data from an audio file using the filename provided.
 * Using the rand function it chooses the samples to store the message.
 * It takes each bit of the message and stores it in the last significant
 * bit of random samples. It then exports the new audio file with the name
 * encoded-<input filename>.wav. The audio file sounds the same after
 * encryption.
 * 
 * @param fileName The name of the file to be read.
 * @param text The message to be encrypted inside the wav file.
 * @return An exit code.
 */
int encryption(const char *fileName, const char* text);
#endif

