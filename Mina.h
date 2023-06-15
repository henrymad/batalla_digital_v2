#ifndef _MINA_H_
#define _MINA_H_

#include "Coordenada.h"

class Mina {
private:
	int jugador;
    int idMina;
	Coordenada * coordenada;
public:
	Mina();
    Mina(int jugador);
    Mina( Coordenada *);
	Mina( Coordenada *, int );
    int NuevoID(int);
	~Mina();
	Coordenada * getCordenada();
	void setCoordenada( Coordenada * );
	void setJugador( int );
	int getJugador();
    int getIdMina();

};

#endif    // _MINA_H_