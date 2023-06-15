#include "Avion.h"
#include "PropiedadesDelJuego.h"

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
	if (coordenada->getCoordenadaZ() > NIVEL_SUPERFICIE) {
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

int Avion::NuevoID(int numero = 0) {
	// Cada vez que se instancia un nuevo soldado en la partida se crea un ID para el bando del Jugador.
	static int numeroInicial;
	if (numero <= 0) {
		numeroInicial = 1;
	}
	else {
		numeroInicial = numero;
	}
	return numeroInicial++;
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
	if ( coordenada->getCoordenadaZ() > NIVEL_SUPERFICIE ) {
		this->coordenada = coordenada;
	}
}

// Getters

int Avion::getJugador() {
	return this->jugador;
}

int Avion::getIDAvion() {
	return this->idAvion;
}