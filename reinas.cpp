#include <iostream>
#include "tablero.h"

unsigned int cantReinas = 0;

void InicializarTablero(Tablero& tablero);
void GenerarSoluciones(Tablero& tablero, list<Tablero>& soluciones);
void ImprimirSoluciones(list<Tablero>& soluciones);
bool Pertenece(Tablero& tablero, list<Tablero>& soluciones);

int main()
{
	Tablero tablero;
	list<Tablero> soluciones;

	GenerarSoluciones(tablero, soluciones);
	ImprimirSoluciones(soluciones);
}


void GenerarSoluciones(Tablero& tablero, list<Tablero>& soluciones)
{
	for (int i = 0; i < LADO_TABLERO; i++) {

		for (int j = 0; j < LADO_TABLERO; j++) {

			if (tablero.SePuedeColocarReinaEn(i,j)) {
				tablero.ColocarReinaEn(i,j);

				if (tablero.CantidadDeReinas() == 8) {

					if(!Pertenece(tablero, soluciones))
						soluciones.push_back(tablero);

				} else {
					GenerarSoluciones(tablero, soluciones);
				}
				
				tablero.RemoverReinaDe(i,j);
			}

		}
	}

}


void ImprimirSoluciones(list<Tablero>& soluciones)
{
	for (auto& tablero : soluciones)
		tablero.Imprimir();
}


bool Pertenece(Tablero& tablero, list<Tablero>& soluciones)
{
	for (auto& t : soluciones) {

		if (tablero == t)
			return true;

	}

	return false;
}