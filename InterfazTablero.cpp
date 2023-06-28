#include "InterfazTablero.h"

InterfazTablero::InterfazTablero() {
	this->tablero = NULL;
}

InterfazTablero::InterfazTablero( Tablero3D * tablero ) {
	this->tablero = tablero;
}


void InterfazTablero::setTablero( Tablero3D * tablero ) {
	this->tablero = tablero;
}

Tablero3D * InterfazTablero::getTablero() {
	return this->tablero;
}

// M�todos

// Rutinas complementarias

void InterfazTablero::mostrarTablero(int nivel) {
	if (this->tablero == NULL) {
		return;
	}
	if (nivel <= 0 || nivel > ALTURA_TABLERO) {
		nivel = NIVEL_SUPERFICIE;
	}

	// Lista < Casillero * > * subelemento;
	for ( int x = 1; x < this->tablero->getSize_x(); x++ ) {
		for ( int y = 1; y < this->tablero->getSize_y(); y++) {
			for ( int z = 1; x < this->tablero->getSize_z(); z++) {
				Casillero * elemento = this->tablero->getCasillero( x, y, z);
				if ( elemento->getAvion() != NULL ) {
					// Mostrar Avion
				}
			}
		}
	}
	/*
	subelemento = elemento->obtenerDato(y);
	Casillero * Casillero;
	Casillero = subelemento->obtenerDato(z);
	*/
	return;

}

void InterfazTablero::mostrarTablero() {
	this->mostrarTablero(NIVEL_SUPERFICIE);
}

void InterfazTablero::mostrarTablero( Coordenada * cordenada ) {
}

char InterfazTablero::mostrarCasillero( Coordenada * coordenada, Jugador * jugador ) {
	char valor = 0;
	if ( this->tablero != NULL || coordenada != NULL) {
		Casillero * casillero;
		casillero = this->tablero->getCasillero( coordenada->getCoordenadaX(), coordenada->getCoordenadaY(), coordenada->getCoordenadaZ() );
		valor = this->getLetraCasilla(casillero, jugador);
	}
	return valor;
}

char InterfazTablero::getLetraCasilla( Casillero * casillero, Jugador * jugador) {
	char valor = 0;
	if ( casillero != NULL ) {
		if ( jugador == NULL) {
			if ( casillero->getTipoTerreno() == tierra ) {
			}
			else {
				// A nivel del mar s�lo es tierra o agua
			}
			// Igual hay que verificar lo que hay casillas arriba volando.
		}
		else {
		}
	}
	return valor;
}