#ifndef _SOLDADO_INCLUDED_
#define _SOLDADO_INCLUDED_

#include "Coordenada.h"

class Soldado {
private:
	int idSoldado;
	int jugador;
	Coordenada * coordenada;

public:
	Soldado();
	Soldado( int );
	Soldado( int, Coordenada * );
	~Soldado();
	int NuevoID(int);
	void setJugador( int );
	void setCoordenada( Coordenada * );
	int getJugador();
	int getIDSoldado();
	Coordenada * getCoordenada();
};

#endif	// _SOLDADO_INCLUDED_