# Define the compiler and flags
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

exe: main.o hash.o
	$(CC) $(LFLAGS) main.o hash.o -o exe

main.o: hash.h linked_list.hpp hash.cpp main.cpp
	$(CC) $(CFLAGS) hash.cpp main.cpp

hash.o:	hash.h linked_list.hpp hash.cpp
	$(CC) $(CFLAGS) hash.cpp

clean:
	\rm *.o *~ main