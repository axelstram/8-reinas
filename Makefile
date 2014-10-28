reinas: tablero.o
	g++ -Wall -std=c++0x tablero.o reinas.cpp -o reinas

tablero.o: 
	g++ -c -Wall -std=c++0x tablero.cpp


clean:
	rm tablero.o reinas