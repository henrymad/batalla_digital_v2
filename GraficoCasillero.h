#ifndef _GRAFICO_H_CASILLERO_
#define _GRAFICO_H_CASILLERO_

#include <new>
#include <iostream>

#include "Tablero3D.h"

class GraficoCasillero {
public:
	GraficoCasillero();
	GraficoCasillero( Tablero3D * );
	~GraficoCasillero( );
	// Setters
	void setTablero( Tablero3D * );
	void setCasillero( Casillero * );
	void setSoldado( Soldado * );
	void setMina( Mina * );
	void setBombaQuimica( BombaQuimica * );
	void setAvion( Avion * );
	void setBarco( Barco * );
	char ** getMiniTablero();
private:
	Tablero3D * tablero;
	char ** miniTablero = NULL;
	int sizeFilas, sizeColumnas;
};

#endif