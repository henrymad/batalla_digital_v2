#ifndef _BOMBAQUIMICA_H_
#define _BOMBAQUIMICA_H_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class BombaQuimica {
private:
	int jugador = 0;
	int cantidadCasilleros = 0;
	int turnos = 0;
	Coordenada * coordenada;
public:
	BombaQuimica( int );
	BombaQuimica( int, Coordenada * );
	BombaQuimica( int, Coordenada *, int );
	~BombaQuimica();
	Coordenada * getCoordenadas();
	void setCoordenadas( Coordenada * );
	void setJugador( int );
	void setTurnos( int );
	void setCantidadCasilleros( int );
	int getJugador();
};

#endif
