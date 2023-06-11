#include "Jugador.h"

Jugador::Jugador() {
	this->idJugador = this->NuevoID( 0 );
	this->nombre = "";
	this->soldados = NULL;
	this->minasActivas = NULL;
}

int Jugador::NuevoID( int numero = 0 ) {
	// Cada vez que se instancia un nuevo jugador en la partida se crea un ID de bando del Jugador.
	static int numeroInicial;
	if ( numero <= 0) {
		numeroInicial = 1;
	}
	else {
		numeroInicial = numero;
	}
	return numeroInicial++;
}

Jugador::Jugador( string nombre ) {
	this->idJugador = this->NuevoID();
	this->nombre = nombre;
	this->soldados = NULL;
	// this->minasActivas = nullptr;
}

Jugador::~Jugador() {
	// Liberar listas?
	this->nombre = "";
}

// Setters

void Jugador::setNombreJugador(string nombre) {
	this->nombre = nombre;
}

void Jugador::reiniciarID() {
	this->NuevoID( 0 );
}

// Getters

int Jugador::getCantidadSoldados() {
	return this->soldados->contarElementos();
}

string Jugador::getNombreJugador() {
	return this->nombre;
}

int Jugador::getIdJugador() {
	return this->idJugador;
}

Jugador * Jugador::getJugador() {
	return this;
}

void Jugador::setMinasActivas(Lista<Mina *> *minasActivas) {
    this->minasActivas = minasActivas;
}

void Jugador::setSoldados(Lista<Soldado *> *soldados) {
    this->soldados = soldados;
}

// Acciones

/*
void Jugador::moverSoldado( Tablero3D * tablero, Coordenada * coordenadaDestino, Soldado * Soldado ) {
	// 	Nota La validaci�n del movimiento, Coordenadas Origen y Destino
	//   deben ser realizadas por el m�dulo de l�gica del juego.
	//
	
}

void Jugador::moverSoldado(Tablero3D* tablero, Coordenada coordenadaDestino, int idSoldado) {
	// 	Nota La validaci�n del movimiento, Coordenadas Origen y Destino
	//   deben ser realizadas por el m�dulo de l�gica del juego.

}
*/