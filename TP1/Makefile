CC=g++
CFLAGS=-Wall -std=c++17

all: hello carres


string: string.cpp
	$(CC) string.cpp $(CFLAGS) -o string

input: input.cpp
	$(CC) input.cpp $(CFLAGS) -o input

carres: carres.cpp
	$(CC) carres.cpp $(CFLAGS) -o carres

hello: hello.cpp
	$(CC) hello.cpp $(CFLAGS) -o hello

clean:
	@rm -f carres
	@rm -f hello
	@rm -f input
	@rm -f string