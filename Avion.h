#ifndef _AVION_H_
#define _AVION_H_

#include <iostream>

#include "Coordenada.h"


class Avion {
private:
	int idAvion;		// Autonumerico [1-n].
	int jugador;
	Coordenada * coordenada;
	int NuevoID( int );
public:
	Avion( int );
	Avion( int, Coordenada * );
	~Avion();
	Coordenada * getCoordenadas();
	void setCoordenada( Coordenada * );
	void setJugador( int );
	int getJugador();
	int getIDAvion();
};

#endif