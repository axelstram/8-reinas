#include <list>
#include <iostream>

using namespace std;

enum Estado {Amenazada = 1, NoAmenazada = 0};

#define LADO_TABLERO 8

typedef struct {

	Estado estado;
	bool hayPieza;

} Posiciones;

class Tablero {

	private:

		Posiciones tablero[LADO_TABLERO][LADO_TABLERO];
		unsigned int cantReinas;

		void MarcarFilaHorizontalComo(Estado estado, unsigned int x, unsigned int y);
		void MarcarFilaVerticalComo(Estado estado, unsigned int x, unsigned int y);
		void MarcarDiagonalesComo(Estado estado, unsigned int x, unsigned int y);

	public:

		Tablero();
		~Tablero() {};
		void ColocarReinaEn(unsigned int x, unsigned int y);
		void RemoverReinaDe(unsigned int x, unsigned int y);
		bool SePuedeColocarReinaEn(unsigned int x, unsigned int y);
		unsigned int CantidadDeReinas();
		void Imprimir();
		bool operator==(Tablero& t);
};	