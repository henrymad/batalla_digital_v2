#ifndef _BARCO_H_
#define _BARCO_H_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Barco {
private:
	int jugador = 0;
	Coordenada * coordenada;
public:
	Barco();
	Barco( int );
	Barco( int, Coordenada * );
	void setCoordenadas( Coordenada * );
	void setJugador( int );
	int getJugador();
};

#endif