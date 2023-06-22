#ifndef _SOLDADO_H_INCLUDED_
#define _SOLDADO_H_INCLUDED_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Soldado {
private:
	int idSoldado;		// Autonumerico [1-n].
	int jugador;
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

#endif	// _SOLDADO_H_INCLUDED_