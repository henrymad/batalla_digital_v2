#ifndef _AVION_H_
#define _AVION_H_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Avion {
private:
	int jugador = 0;
	Coordenada * coordenada;
public:
	Avion( int );
	Avion( int, Coordenada * );
	~Avion();
	Coordenada * getCoordenadas();
	void setCoordenadas( Coordenada * );
	void setJugador( int );
	int getJugador();
};

#endif