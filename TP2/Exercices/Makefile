CC=g++
CFLAGS=-Wall -g -O0 -std=c++17

all: fibo fichiers operateurs repartition surcharge template

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f ofstream
	@rm -f ifstream
	@rm -f maps
	@rm -f repartition
	@rm -f surcharges
	@rm -f templates