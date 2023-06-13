#include <iostream>

#include "GraficoCasillero.h"

class MostrarCasillero
{
public:
	MostrarCasillero();
	MostrarCasillero( GraficoCasillero * );
	MostrarCasillero( GraficoCasillero *, Jugador * );
	~MostrarCasillero();
	void setCasillero( GraficoCasillero * );
	void setJugador( Jugador * );
	string emitir( int );
private:
	GraficoCasillero * graficoCasillero;
	Jugador * jugador;
};