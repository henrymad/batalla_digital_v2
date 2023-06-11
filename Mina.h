#ifndef _MINA_H_
#define _MINA_H_

#include "Coordenada.h"

class Mina {
private:
	int jugador;
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