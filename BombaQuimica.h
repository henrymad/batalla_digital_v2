#ifndef _BOMBAQUIMICA_H_INCLUDED_
#define _BOMBAQUIMICA_H_INCLUDED_

#include <iostream>

#include "Tablero3D.h"

#include "Coordenada.h"
#include "Definiciones.h"

class BombaQuimica {
private:
	int jugador = 0;
	int cantidadCasilleros = 0;
	int turnos = 0;
	Coordenada * coordenada;
	Tablero3D * tablero;
	// void computoCasillerosAfectados( Coordenada *, int );
public:
	BombaQuimica( int );
	BombaQuimica( int, Coordenada * );
	BombaQuimica( int, Coordenada *, int );
	~BombaQuimica();
	Coordenada * getCoordenadas();
	void setTablero3D( Tablero3D * );		// Para calcular casillas adyascentes necesito acceder al Tablero
	void setCoordenadas( Coordenada * );
	void setJugador( int );
	void setTurnos( int );
	void setCantidadCasilleros( int );
	int getJugador();
};

#endif
