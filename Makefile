CC = g++

CFLAGS = -Wall -g

all:main

main:main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: main.cpp tree.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o main

