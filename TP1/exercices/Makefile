CC=g++
CFLAGS=-O0 -g -std=c++17

all: carres calculatrice 

carres: carres.cpp
	$(CC) $(CFLAGS) carres.cpp -o carres

calculatrice: calculatrice.cpp
	$(CC) $(CFLAGS) calculatrice.cpp -o calculatrice

clean:
	@rm -f carres
	@rm -f calculatrice