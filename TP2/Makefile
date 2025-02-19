CC=g++
CFLAGS=-Wall -g -O0 -std=c++17

all: ofstream ifstream maps surcharges templates

ofstream: ofstream.cpp
	$(CC) ofstream.cpp $(CFLAGS) -o ofstream

ifstream: ifstream.cpp
	$(CC) ifstream.cpp $(CFLAGS) -o ifstream

maps: maps.cpp
	$(CC) maps.cpp $(CFLAGS) -o maps

surcharges: surcharges.cpp
	$(CC) surcharges.cpp $(CFLAGS) -o surcharges

templates: templates.cpp
	$(CC) templates.cpp $(CFLAGS) -o templates

clean:
	@rm -f ofstream
	@rm -f ifstream
	@rm -f maps
	@rm -f surcharges
	@rm -f templates