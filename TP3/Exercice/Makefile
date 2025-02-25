all: main run

run:
	@./main

main : polynomial.o main.o
	g++ -std=c++17 -o main polynomial.o main.o
	

polynomial.o : polynomial.cpp polynomial.hpp
	g++ -std=c++17 -c polynomial.cpp

main.o : main.cpp polynomial.hpp
	g++ -std=c++17 -c main.cpp

clean :
	@rm -f *.o
	@rm -f main