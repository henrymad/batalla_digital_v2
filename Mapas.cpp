#include "Mapas.h"

Mapas::Mapas( Tablero3D * tablero ) {
	this->tablero = tablero;
	this->jugador = NULL;
}

//  Setters

void Mapas::cargarMapaDefault() {
	Casillero * casillero;
	if ( this->tablero != NULL ) {
		for ( int i = 0; i < this->tablero->getSize_x(); i++ ) {
			for ( int j = 0; j < this->tablero->getSize_y(); j++ ) {
				for (int k = 0; k < this->tablero->getSize_z(); k++ ) {
					if ( k > NIVEL_SUPERFICIE ) {
						
					}
					else {
					}
				}
			}
		}
	}
}

void Mapas::setJugador( Jugador * jugador ) {
	this->jugador = jugador;
}