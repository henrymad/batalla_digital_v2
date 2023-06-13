#ifndef _AVION_H_
#define _AVION_H_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Avion {
private:
	int idAvion = 0;		// Autonumerico [1-n].
	int jugador = 0;
	Coordenada * coordenada;
	int NuevoID( int );
public:
	Avion( int );
	Avion( int, Coordenada * );
	~Avion();
	Coordenada * getCoordenadas();
	void setCoordenadas( Coordenada * );
	void setJugador( int );
	int getJugador();
	int getIDAvion();
};

#endif