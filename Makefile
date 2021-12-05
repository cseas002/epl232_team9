###############################################
# Makefile for compiling the program skeleton
# 'make' build executable file 'PROJ'
# 'make doxy' build project manual in doxygen
# 'make all' build project + manual
# 'make clean' removes all .o, executable and doxy log
# 'make cleano' removes all .o files
# 'make team9' makes the library epl232_team9.a containing all .o files
# 'make debug_<c file to debug> debugs the c file (give the c file without .c extention)
###############################################
PROJ = wavengine # the name of the project
CC = gcc # name of compiler
DOXYGEN = doxygen # name of doxygen binary
# define any compile-time flags
CFLAGS = -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic # there is a space at the end of this
LFLAGS = -lm
###############################################
# You don't need to edit anything below this line
###############################################
# list of object files
# The following includes all of them!
C_FILES := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(C_FILES))
# To create the executable file we need the individual
# object files
$(PROJ): $(OBJS)
	$(CC)  -o $(PROJ) $(OBJS) $(LFLAGS)
# To create each individual object file we need to
# compile these files using the following general
# purpose macro
.c.o:
	$(CC) $(CFLAGS) -c $<
# there is a TAB for each identation.
# To make all (program + manual) "make all"
all :
	make
	make doxy
# To make all (program + manual) "make doxy"
doxy:
	$(DOXYGEN) doxygen.conf &> doxygen.log
# To clean .o files amd doxygen: "make clean"
clean:
	rm -rf *.o doxygen.log html
	rm debug_wavengine
	rm wavengine
	rm epl232_team9.a
# To clean .o files: "make cleano"
cleano:
	rm -rf *.o
# To make the library: "make team9"
team9:
	make
	rm wavengine
	rm wavengine.o
	for file in `ls | grep "\.o"`; do ar -cvq epl232_team9.a $$file; done
	make cleano
	make doxy
# DEBUGGING MAKE COMMANDS:
debug_list:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_LIST $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_changeSpeed:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_CHANGESPEED $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_chop:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_CHOP $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_cryptography:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_CRYPTOGRAPHY $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_decryption:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_DECRYPTION $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_encryption:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_ENCRYPTION $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_mix:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_MIX $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_readMusicFile:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_READ_MUSIC_FILE $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_writeMusicFile:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_WRITE_MUSIC_FILE $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_reverse:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_REVERSE $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_stereoToMono:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_MONO $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine
debug_volIncrease:
	for file in `ls | grep "\.c$$"`; do gcc -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic -c -DDEBUG_VOL_CHANGE $$file; done
	$(CC)  -o debug_wavengine $(OBJS) $(LFLAGS)
	./debug_wavengine