#ifndef _JUGADOR_H_INCLUDED_
#define _JUGADOR_H_INCLUDED_

#include <string>
#include "lista.h"

#include "Casillero.h"

using namespace std;

class Jugador {
private:
	int idJugador;
	string nombre;
	Lista< Soldado * > * soldados;
	Lista< Mina * > * minasActivas;
	int NuevoID( int );
public:
	Jugador();
	Jugador( string );
	~Jugador();
	int getCantidadSoldados();
	int getIdJugador();
	Jugador* getJugador();
	void setNombreJugador( string );
	string getNombreJugador();
	void reiniciarID();
	// Acciones
	// void moverSoldado( Tablero3D *, Coordenada *, Soldado * ); 
	// void moverSoldado( Tablero3D *, Coordenada *, int );
};

#endif  // _JUGADOR_H_INCLUDED_

