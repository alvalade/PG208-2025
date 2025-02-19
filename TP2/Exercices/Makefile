CC=g++
CFLAGS=-Wall -g -O0 -std=c++17

all: fibo fichiers operateurs repartition surcharge template

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f fibo
	@rm -f fichiers
	@rm -f operateurs
	@rm -f repartition
	@rm -f surcharge
	@rm -f template