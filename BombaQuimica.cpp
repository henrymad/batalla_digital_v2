#include "BombaQuimica.h"

BombaQuimica::BombaQuimica( int jugador ) {
	if (jugador > 0) {
		this->jugador = jugador;
	}
	this->coordenada = nullptr;
	this->turnos = 0;
	this->cantidadCasilleros = 0;
}

BombaQuimica::BombaQuimica( int jugador, Coordenada * coordenada ) {
	if (jugador > 0) {
		this->jugador = jugador;
	}
	if (coordenada->getCoordenada_z() == NIVEL_SUPERFICIE) {
		this->coordenada = coordenada;
	}
	this->turnos = 0;
	this->cantidadCasilleros = 0;
}

BombaQuimica::BombaQuimica( int jugador, Coordenada * coordenada, int turnos ) {
	if (jugador > 0) {
		this->jugador = jugador;
	}
	if (coordenada->getCoordenada_z() == NIVEL_SUPERFICIE) {
		this->coordenada = coordenada;
	}
	this->turnos = turnos;
	this->cantidadCasilleros = 0;
}

BombaQuimica::~BombaQuimica() {
	this->jugador = 0;
	this->turnos = 0;
	this->cantidadCasilleros = 0;
	this->coordenada = nullptr;
}

// Getters

Coordenada * BombaQuimica::getCoordenadas() {
	return this->coordenada;
}

// Setters

void BombaQuimica::setCoordenadas( Coordenada * coordenada ) {
	if (coordenada->getCoordenada_z() == NIVEL_SUPERFICIE) {
		this->coordenada = coordenada;
	}
}

void BombaQuimica::setJugador( int jugador ) {
	// Pre -> Deberia estar el Id en la lista de Jugadores
	// Post -> Queda determinado el bando
	if (jugador > 0) {
		this->jugador = jugador;
	}
}

void BombaQuimica::setTurnos( int turnos ) {
	this->turnos = turnos;
}

void BombaQuimica::setCantidadCasilleros( int casilleros ) {
	if ( casilleros > 0) {
		this->cantidadCasilleros = casilleros;
	}
}

int BombaQuimica::getJugador() {
	return this->jugador;
}