#include "Mina.h"

Mina::Mina() {
	this->jugador = 0;
	this->coordenada = nullptr;
}

Mina::Mina( Coordenada * coordenada, int jugador ) {
	if ( jugador != 0 ) {
		this->jugador = jugador;
	}
	this->coordenada = coordenada;
}

Mina::Mina( Coordenada * coordenada ) {
	this->jugador = 0;
	this->coordenada = coordenada;
}

Mina::~Mina() {
	this->jugador = 0;
	this->coordenada = nullptr;
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
	this->coordenada = coordenada;
}

void Mina::setJugador( int jugador ) {
	if ( jugador != 0 ) {
		this->jugador = jugador;
	}
}