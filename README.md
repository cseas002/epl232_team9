# epl232_team9

To create the library use the command: "make team9"
After this, compile the file using the library (gcc -o wavengine wavengine.c epl232_team9.a)

The valid for the program inputs are:
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

./wavengine -encodeText <wave file> <input file with text to encode>
This option encodes the given text (inside the input file) to the given wave file

./wavengine -decodeText <wave file> <message length> <output file>
This option decodes the given music file and prints the hidden message with the given length to the output file

./wavenging -changeSpeed <number to be multiplied> <wave file(s)>
This option multiplies the speed of the given music file(s) with the given number

./wavengine -volIncrease <number to be multiplied> <wave file(s)>
This option multiplies the volume of the given music file(s) by the number given

./wavengine -man
This options prints this message

NOTE: All options do not change the music files, they create new music files (except -list, -encode, -decode)

To debug the c files, type the command "make debug_<c file>" where <c file> is the c file you want to debug 
WITHOUT THE EXTENTION
e.g. 
make debug_list
This command debugs list.c