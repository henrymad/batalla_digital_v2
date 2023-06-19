#ifndef _MAPAS_H_INCLUDED_
#define _MAPAS_H_INCLUDED_

#include <iostream>
#include <fstream>

#include "Jugador.h"
#include "Graficas.h"

using namespace std;

class Mapas
{
public:
	Mapas( Tablero3D * );
	void cargarMapaDefault();
	void cargarMapa2D( string );
	void cargarMapa3D( string );
	void grabarMapa2D( string );
	void grabarMapa3D( string );
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