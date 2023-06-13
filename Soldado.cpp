#include "Soldado.h"

Soldado::Soldado() {
	this->jugador = 0;
	this->coordenada = nullptr;
	this->idSoldado = this->NuevoID(0);
}

Soldado::Soldado( int jugador ) {
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
	this->coordenada = nullptr;
	this->idSoldado = this->NuevoID( 0 );
}

Soldado::Soldado( int jugador, Coordenada * coordenada ) {
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
	if (coordenada->getCoordenada_z() == NIVEL_SUPERFICIE) {
		this->coordenada = coordenada;
	}
	this->idSoldado = this->NuevoID(0);
}

Soldado::~Soldado() {
	this->jugador = 0;
	this->coordenada = NULL;
	this->idSoldado = 0;
}

int Soldado::NuevoID(int numero = 0) {
	// Cada vez que se instancia un nuevo jugador en la partida se crea un ID de bando del Jugador.
	static int numeroInicial;
	if (numero <= 0) {
		numeroInicial = 1;
	}
	else {
		numeroInicial = numero;
	}
	return numeroInicial++;
}

// Setters
void Soldado::setJugador( int jugador ) {
	// Pre -> Deberia estar el Id en la lista de Jugadores
	// Post -> Queda determinado el bando
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
}

void Soldado::setCoordenada( Coordenada * coordenada ) {
	if ( coordenada->getCoordenada_z() == NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

// Getters

int Soldado::getJugador() {
	return this->jugador;
}

Coordenada * Soldado::getCoordenada() {
	return this->coordenada;
}

int Soldado::getIDSoldado() {
	return this->idSoldado;
}