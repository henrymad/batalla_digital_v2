#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include <string>
#include "Lista.h"

// #include "Tablero3D.h"
#include "Soldado.h"
#include "Mina.h"

using namespace std;

class Jugador {
private:
	int idJugador;
	string nombre;
	Lista<Soldado *> * soldados;
	Lista<Mina *> * minasActivas;
public:
	Jugador();
	Jugador( string );
	~Jugador();
	int NuevoID( int );
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

#endif  // _JUGADOR_H_

