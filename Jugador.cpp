#include "Jugador.h"

Jugador::Jugador() {
	// Emulación de un autonumérico.
	this->idJugador = this->NuevoID( 0 );
	this->nombre = "";
	this->soldados = NULL;
	// this->minasActivas = nullptr;
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

// Acciones

/*
void Jugador::moverSoldado( Tablero3D * tablero, Coordenada * coordenadaDestino, Soldado * Soldado ) {
	// 	Nota La validación del movimiento, Coordenadas Origen y Destino
	//   deben ser realizadas por el módulo de lógica del juego.
	//
	
}

void Jugador::moverSoldado(Tablero3D* tablero, Coordenada coordenadaDestino, int idSoldado) {
	// 	Nota La validación del movimiento, Coordenadas Origen y Destino
	//   deben ser realizadas por el módulo de lógica del juego.

}
*/