#ifndef _MINA_H_
#define _MINA_H_

#include <iostream>

#include "Coordenada.h"
#include "Definiciones.h"

class Mina {
private:
	int jugador = 0;
	Coordenada * coordenada;
public:
	Mina();
	Mina( Coordenada *);
	Mina( Coordenada *, int );
	~Mina();
	Coordenada * getCordenada();
	void setCoordenada( Coordenada * );
	void setJugador( int );
	int getJugador();

};

#endif    // _MINA_H_