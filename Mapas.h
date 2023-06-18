#ifndef _MAPAS_H_INCLUDED_
#define _MAPAS_H_INCLUDED_

#include <iostream>
#include <fstream>

#include "Tablero3D.h"
#include "Jugador.h"

using namespace std;

class Mapas
{
public:
	Mapas( Tablero3D * );
	void cargarMapaDefault();
	void cargarMapa2D( string );
	void cargarMapa3D(string);
	void imprimirMapa( string, Jugador * );
	void imprimirGraficoSuperficie( string );
	void verMapa();
	void setJugador( Jugador * );
	void setNombreArchivo( string );
private:
	Tablero3D * tablero;
	Jugador * jugador;
	string nombreArchivo;
	string Celda( Casillero *, Jugador * );
	string hayAvion( Casillero *, Jugador * );
};

#endif