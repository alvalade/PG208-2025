CC=g++
CFLAGS=-Wall -std=c++17

all: ofstream ifstream

ofstream: ofstream.cpp
	$(CC) ofstream.cpp $(CFLAGS) -o ofstream

ifstream: ifstream.cpp
	$(CC) ifstream.cpp $(CFLAGS) -o ifstream

clean:
	@rm -f ofstream
	@rm -f ifstream