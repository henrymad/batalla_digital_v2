#include "Avion.h"

Avion::Avion( int jugador ) {
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
	this->coordenada = NULL;
}

Avion::Avion( int jugador, Coordenada * coordenada) {
	if (jugador > 0) {
		this->jugador = jugador;
	}
	if (coordenada->getCoordenada_z() > NIVEL_SUPERFICIE) {
		this->coordenada = coordenada;
	}
	else {
		this->coordenada = NULL;
	}
}

Avion::~Avion() {
	this->jugador = 0;
	this->coordenada = NULL;
}

Coordenada * Avion::getCoordenadas() {
	return this->coordenada;
}

// Setters
void Avion::setJugador( int jugador ) {
	// Pre -> Deberia estar el Id en la lista de Jugadores
	// Post -> Queda determinado el bando
	if (jugador > 0) {
		this->jugador = jugador;
	}
}

void Avion::setCoordenadas( Coordenada * coordenada ) {
	/* Importante es que el aeroplano este en el aire */
	if ( coordenada->getCoordenada_z() > NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

int Avion::getJugador() {
	return this->jugador;
}