#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include <string>
#include "Lista.h"

#include "Soldado.h"
#include "Mina.h"
#include "Tablero3D.h"

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
    void setMinasActivas(Lista<Mina *> * minasActivas);
    Lista<Mina *> * getMinasActivas();
    void setSoldados(Lista<Soldado *> * soldados);
    Lista<Soldado *> * getSoldados();

    void actualizarPosicionSoldado(Coordenada *coordenada, int idSoldado, Jugador *jugador);
    void eliminarSoldado(int idSoldado);
    void eliminarMina(Mina *mina);
    Soldado * obtenerSoldadoPorId(int idSolado);
	// Acciones
	// void moverSoldado( Tablero3D *, Coordenada *, Soldado * ); 
	void moverSoldado(Tablero3D *tablero1, Coordenada *coordenadaDestino, int idSoldado, Lista<Jugador*> *jugadores);
    void minarCasillero(Tablero3D *tablero, Coordenada *coordenadaDestino,Lista<Jugador*> *jugadores);
};

#endif  // _JUGADOR_H_

