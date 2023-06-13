//
// Created by lenovo on 15/05/23.
//

#ifndef BATALLA_DIGITAL_V2_INTERFACETABLERO_H
#define BATALLA_DIGITAL_V2_INTERFACETABLERO_H

#include "Tablero3D.h"

class InterfazTablero {
private:
	Tablero3D * tablero;
	char getLetraCasilla( Casillero * casillero, Jugador * );
public:
	InterfazTablero();
	InterfazTablero( Tablero3D * );
	void setTablero( Tablero3D * );
	Tablero3D * getTablero();
	void mostrarTablero( int );
	void mostrarTablero();
	void mostrarTablero( Coordenada * );
	char mostrarCasillero( Coordenada *, Jugador * );
};

#endif //BATALLA_DIGITAL_V2_INTERFACETABLERO_H
