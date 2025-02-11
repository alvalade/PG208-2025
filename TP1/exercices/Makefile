CC=g++
CFLAGS=-O0 -g -std=c++17

all: carres array_square display pratique calculatrice 

carres: carres.cpp
	$(CC) $(CFLAGS) carres.cpp -o carres

array_square: array_square.cpp
	$(CC) $(CFLAGS) array_square.cpp -o array_square

display: display.cpp
	$(CC) $(CFLAGS) display.cpp -o display

pratique: pratique.cpp
	$(CC) $(CFLAGS) pratique.cpp -o pratique

calculatrice: calculatrice.cpp
	$(CC) $(CFLAGS) calculatrice.cpp -o calculatrice

clean:
	@rm -f carres
	@rm -f array_square
	@rm -f display
	@rm -f pratique
	@rm -f calculatrice