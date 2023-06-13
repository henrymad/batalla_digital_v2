#ifndef _SOLDADO_INCLUDED_
#define _SOLDADO_INCLUDED_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Soldado {
private:
	int idSoldado = 0;		// Autonumerico [1-n].
	int jugador = 0;
	Coordenada * coordenada;
	int NuevoID( int );

public:
	Soldado();
	Soldado( int );
	Soldado( int, Coordenada * );
	~Soldado();
	void setJugador( int );
	void setCoordenada( Coordenada * );
	int getJugador();
	int getIDSoldado();
	Coordenada * getCoordenada();
};

#endif	// _SOLDADO_INCLUDED_