CC=g++
CFLAGS=-Wall -g -O0 -std=c++17

all: Polynomial_struct Polynomial_class

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f Polynomial_struct
	@rm -f Polynomial_class
