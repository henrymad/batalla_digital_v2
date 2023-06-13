#include "Barco.h"


Barco::Barco() {
	this->jugador = 0;
	this->coordenada = NULL;
}

Barco::Barco( int jugador ) {
	if (jugador > 0) {
		this->jugador = jugador;
	}
	this->coordenada = NULL;
}

Barco::Barco( int jugador , Coordenada * coordenada ) {
	if (jugador > 0) {
		this->jugador = jugador;
	}
	if ( coordenada->getCoordenada_z() == NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

// Setters
void Barco::setJugador( int jugador) {
	// Pre -> Deberia estar el Id en la lista de Jugadores
	// Post -> Queda determinado el bando
	if (jugador > 0) {
		this->jugador = jugador;
	}
}

void Barco::setCoordenadas( Coordenada * coordenada) {
	/* Importante es que el aeroplano este en el aire */
	if ( coordenada->getCoordenada_z() == NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

int Barco::getJugador() {
	return this->jugador;
}