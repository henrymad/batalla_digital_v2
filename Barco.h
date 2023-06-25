#ifndef _BARCO_H_INCLUDED_
#define _BARCO_H_INCLUDED_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Barco {
private:
	int jugador;
	Coordenada * coordenada;
public:
	Barco();
	Barco( int );
	Barco( int, Coordenada * );
	void setCoordenada( Coordenada * );
	void setJugador( int );
	int getJugador();
};

#endif