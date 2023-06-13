#include "Mina.h"

Mina::Mina() {
	this->jugador = 0;
	this->coordenada = NULL;
}

Mina::Mina( Coordenada * coordenada, int jugador ) {
	if ( jugador != 0 ) {
		this->jugador = jugador;
	}
	this->coordenada = NULL;
	if ( coordenada->getCoordenada_z() <= NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

Mina::Mina( Coordenada * coordenada ) {
	this->jugador = 0;
	this->coordenada = coordenada;
}

Mina::~Mina() {
	this->jugador = 0;
	this->coordenada = NULL;
}

// Getters

Coordenada * Mina::getCordenada() {
	return this->coordenada;
}

int Mina::getJugador() {
	return this->jugador;
}

// Setters

void Mina::setCoordenada(Coordenada * coodenada) {
	this->coordenada = NULL;
	if ( coordenada->getCoordenada_z() <= NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

void Mina::setJugador( int jugador ) {
	if ( jugador != 0 ) {
		this->jugador = jugador;
	}
}