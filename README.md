# epl232_team9

The valid inputs for the program are:
./wavengine -list <wave file(s)>
This option prints the details of the given music file(s)

./wavengine -mono <wave file(s)>
This option change music file(s) from stereo to mono

./wavengine -mix <wave file 1> <wave file 2>
This option mix the two wave files into one

./wavengine -chop <wave file> <start second> <end second>
This option cuts the given music file and from the start second to the end second

./wavengine -reverse <wave file(s)>
This option reverses the given music files

./wavengine -encodeText <wave file> <text to encode>
This option encodes the given text to the given wave file

./wavengine -decodeText <wave file> <message length> <output file>
This option decodes the given music file and prints the hidden message with the given length to the output file

./wavenging -changeSpeed <number to be multiplied> <wave file(s)>
This option multiplies the speed of the given music file(s) with the given number

./wavengine -volIncrease <number to be multiplied> <wave file(s)>
This option multiplies the volume of the given music file(s) by the number given

./wavengine -man
This options prints this message

NOTE: All options do not change the music files, they create new music files (except -list, -encode, -decode)