#ifndef _MOSTRAR_TABLERO_
#define _MOSTRAR_TABLERO_

#include <fstream>
#include "Tablero3D.h"
#include "MostrarCasillero.h"

class MostrarTablero
{
public:
	MostrarTablero( Tablero3D * );
	MostrarTablero( Tablero3D *, Jugador * );
	~MostrarTablero();
	void imprimir( string );
	void setNombreArchivo( string );
	void setJugador( Jugador * );
private:
	Tablero3D * tablero;
	string nombreArchivo;
	Jugador * jugador;
	string emitir( int, GraficoCasillero );
};

#endif