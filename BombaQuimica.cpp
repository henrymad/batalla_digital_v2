#include "BombaQuimica.h"

BombaQuimica::BombaQuimica( int jugador ) 
: coordenada(NULL), turnos(TIEMPO_INHABILITADA_BOMBA)
{
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
	this->turnos = TIEMPO_INHABILITADA_BOMBA;
	this->cantidadCasilleros = 0;
}

BombaQuimica::BombaQuimica( int jugador, Coordenada * coordenada )
: coordenada(NULL), turnos(TIEMPO_INHABILITADA_BOMBA)
{
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
	if ( coordenada != NULL ) {
		if ( coordenada->getCoordenada_z() == NIVEL_SUPERFICIE) {
			this->coordenada = coordenada;
		}
	}
	this->cantidadCasilleros = 0;
}

BombaQuimica::BombaQuimica( int jugador, Coordenada * coordenada, int turnos )
: coordenada(NULL), turnos(TIEMPO_INHABILITADA_BOMBA)
{
	if ( jugador > 0 ) {
		this->jugador = jugador;
	}
	this->coordenada = NULL;
	if ( coordenada != NULL ) {
		if ( coordenada->getCoordenada_z() == NIVEL_SUPERFICIE ) {
			this->coordenada = coordenada;
		}
	}
	this->turnos = turnos;
	this->cantidadCasilleros = 0;
}

BombaQuimica::~BombaQuimica() {
	this->jugador = 0;
	this->turnos = 0;
	this->cantidadCasilleros = 0;
	this->coordenada = NULL;
}

// Getters

Coordenada * BombaQuimica::getCoordenadas() {
	return this->coordenada;
}

// Setters

void BombaQuimica::setCoordenadas( Coordenada * coordenada ) {
	if ( coordenada != NULL ) {
		if ( coordenada->getCoordenada_z() == NIVEL_SUPERFICIE ) {
			this->coordenada = coordenada;
		}
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
	if ( casilleros > 0 ) {
		this->cantidadCasilleros = casilleros;
	}
}

int BombaQuimica::getJugador() {
	return this->jugador;
}

/*
void BombaQuimica::computoCasillerosAfectados( Coordenada * coordenada, int cantidadCasilleros ) {
	if ( this->tablero == NULL ) {
		return;
	}
	if ( cantidadCasilleros < 0 ) {
		cantidadCasilleros = 0;
	}
	if ( coordenada != NULL ) {
		Casillero * casillero = NULL;
		casillero = this->tablero->getCasillero( coordenada );
		// Cálculo del rango de la onda expansiva y el tiempo residual.
		if ( cantidadCasilleros == 0 ) {
			// Sólo el casillero.
			casillero->setBomba( this );
			casillero->setEstadoCasillero(EstadoCasillero::casilleroinactivo);
			casillero->setTurnosDeInactividad( this->turnos );
		}
		else if ( cantidadCasilleros == 1 ) {
			for ( int i = coordenada->getCoordenada_x(); i <= coordenada->getCoordenada_x() + 3; i++ ) {
			}
		}
		else {
		}
	}
}
*/
