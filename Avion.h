#ifndef _AVION_H_INCLUDED_
#define _AVION_H_INCLUDED_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

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
	void setCoordenadas( Coordenada * );
	void setJugador( int );
	int getJugador();
	int getIDAvion();
};

#endif