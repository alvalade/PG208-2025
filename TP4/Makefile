CC=g++
CFLAGS=-Wall -g -O0 -std=c++17

all: assert except heritage

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f assert
	@rm -f except
	@rm -f heritage
	
