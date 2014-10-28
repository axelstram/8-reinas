#include "tablero.h"

Tablero::Tablero()
{
	for (int i = 0; i < LADO_TABLERO; i++) {

		for (int j = 0; j < LADO_TABLERO; j++) {

			tablero[i][j].estado = NoAmenazada;
			tablero[i][j].hayPieza = false;

		}

	}

	cantReinas = 0;
}


void Tablero::ColocarReinaEn(unsigned int x, unsigned int y)
{
	tablero[x][y].estado = Amenazada;
	tablero[x][y].hayPieza = true;

	MarcarFilaHorizontalComo(Amenazada, x, y);
	MarcarFilaVerticalComo(Amenazada, x, y);
	MarcarDiagonalesComo(Amenazada, x, y);

	cantReinas++;
}


void Tablero::RemoverReinaDe(unsigned int x, unsigned int y)
{
	tablero[x][y].estado = NoAmenazada;
	tablero[x][y].hayPieza = false;

	MarcarFilaHorizontalComo(NoAmenazada, x, y);
	MarcarFilaVerticalComo(NoAmenazada, x, y);
	MarcarDiagonalesComo(NoAmenazada, x, y);

	for (int i = 0; i < LADO_TABLERO; i++) {

		for (int j = 0; j < LADO_TABLERO; j++) {

			if (tablero[i][j].hayPieza) {
				MarcarFilaHorizontalComo(Amenazada, i, j);
				MarcarFilaVerticalComo(Amenazada, i, j);
				MarcarDiagonalesComo(Amenazada, i, j);
			}

		}
	}

	cantReinas--;
}


bool Tablero::SePuedeColocarReinaEn(unsigned int x, unsigned int y)
{
	if (tablero[x][y].estado == NoAmenazada && !tablero[x][y].hayPieza)
		return true;

	return false;
}


void Tablero::MarcarFilaHorizontalComo(Estado estado, unsigned int x, unsigned int y)
{
	for (int i = 0; i < LADO_TABLERO; i++)
		tablero[x][i].estado = estado;
}


void Tablero::MarcarFilaVerticalComo(Estado estado, unsigned int x, unsigned int y)
{
	for (int i = 0; i < LADO_TABLERO; i++)
		tablero[i][y].estado = estado;
}


void Tablero::MarcarDiagonalesComo(Estado estado, unsigned int x, unsigned int y)
{
	//Marco diagonal superior izquierda
	int i = x;
	int j = y;

	while (i >= 0 && j >= 0) {
		tablero[i][j].estado = estado;
		i--;
		j--;
	}

	//Marco diagonal superior derecha
	i = x;
	j = y;

	while (i >= 0 && j <= LADO_TABLERO-1) {
		tablero[i][j].estado = estado;
		i--;
		j++;
	}

	//Marco diagonal inferior izquierda
	i = x;
	j = y;

	while (i <= LADO_TABLERO-1 && j >= 0) {
		tablero[i][j].estado = estado;
		i++;
		j--;
	}


	//Marco diagonal inferior derecha
	i = x;
	j = y;

	while (i <= LADO_TABLERO-1 && j <= LADO_TABLERO-1) {
		tablero[i][j].estado = estado;
		i++;
		j++;
	}
}


unsigned int Tablero::CantidadDeReinas()
{
	return cantReinas;
}


void Tablero::Imprimir()
{
	for (int i = 0; i < LADO_TABLERO; i++) {
		
		for (int j = 0; j < LADO_TABLERO; j++) {

			if (tablero[i][j].hayPieza)
				cout << "1" << " "; 
		    else 
				cout << "0" << " ";

		}

		cout << endl;
	}

	cout << endl;
}



bool Tablero::operator==(Tablero& t)
{
	for (int i = 0; i < LADO_TABLERO; i++) {
		
		for (int j = 0; j < LADO_TABLERO; j++) {

			if (this->tablero[i][j].estado != t.tablero[i][j].estado ||
				this->tablero[i][j].hayPieza != t.tablero[i][j].hayPieza)
				return false;

		}

	}

	return true;
}