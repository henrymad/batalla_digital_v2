#ifndef _MINA_H_INCLUDED_
#define _MINA_H_INCLUDED_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Mina {
private:
	int jugador;
	Coordenada * coordenada;
public:
	Mina();
	Mina( Coordenada * );
	Mina( int );
	Mina( int, Coordenada * );
	~Mina();
	Coordenada * getCordenada();
	void setCoordenada( Coordenada * );
	void setJugador( int );
	int getJugador();

};

#endif    // _MINA_H_INCLUDED_