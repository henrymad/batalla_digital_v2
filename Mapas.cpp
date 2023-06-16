#include "Mapas.h"

Mapas::Mapas( Tablero3D * tablero ) {
	this->tablero = tablero;
}

//  Setters

void Mapas::cargarMapaDefault() {
	Casillero * casillero;
	if ( this->tablero != NULL ) {
		for ( int i = 1; i <= this->tablero->getSize_x(); i++ ) {
			for ( int j = 1; j <= this->tablero->getSize_y(); j++ ) {
				for (int k = 1; k <= this->tablero->getSize_z(); k++ ) {
					casillero = tablero->getCasillero( i, j, k );
					if ( k > NIVEL_SUPERFICIE ) {
						casillero->setTipoTerreno( TipoTerrenoCasillero::aire );
					}
					else {
						casillero->setTipoTerreno( TipoTerrenoCasillero::tierra );
						if ( i > 160  and j < 150 ) {
							casillero->setTipoTerreno( TipoTerrenoCasillero::agua );
						}
						else if (  ( j > 70 && j < 140 ) && ( i >  110 && i <= 160 ) ) {
							casillero->setTipoTerreno( TipoTerrenoCasillero::agua );
						}
						else if ( ( j > 100 && j < 120 ) && ( i > 80  && i <= 110 ) ) {
							casillero->setTipoTerreno(TipoTerrenoCasillero::agua);
						}
					}
				}
			}
		}
	}
}