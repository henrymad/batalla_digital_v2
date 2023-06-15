#include "Mina.h"

Mina::Mina() {
    this->jugador = 0;
    this->idMina =  this->NuevoID(0);
    this->coordenada = new Coordenada();

}


Mina::Mina(int jugador) {
    if ( jugador > 0 ) {
        this->jugador = jugador;
    }
    this->idMina =  this->NuevoID(0);
    this->coordenada = new Coordenada();

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
	this->coordenada = new Coordenada();
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

int Mina::NuevoID(int numero) {
    static int numeroInicial;
    if (numero <= 0) {
        numeroInicial = 1;
    }
    else {
        numeroInicial = numero;
    }
    return numeroInicial++;
}

int Mina::getIdMina() {
    return this->idMina;
}
