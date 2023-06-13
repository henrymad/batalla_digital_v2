#include "GraficoCasillero.h"

GraficoCasillero::GraficoCasillero() {
	// Constructor básico
	this->sizeFilas = 3;
	this->sizeColumnas = 3;
	this->miniTablero = new (std::nothrow) char * [this->sizeFilas];
	if ( this->miniTablero != NULL ) {
		for ( int i = 0; i < this->sizeFilas; i++ ) {
			this->miniTablero[i] = new (std::nothrow) char[this->sizeColumnas];
			if ( this->miniTablero[i] == NULL ) {
				return;  // Fallo de memoria
			}
		}

		for ( int i = 0; i < this->sizeFilas; i++ ) {
			for ( int j = 0; j < this->sizeColumnas; j++ ) {
				this->miniTablero[i][j] = '0';
			}
		}
		this->miniTablero[0][0] = (char) TipoTerrenoCasillero::tierra;
		this->miniTablero[0][1] = (char) EstadoCasillero::casillerovacio;
	}
}

GraficoCasillero::GraficoCasillero( Casillero * casillero ) {
	// Constructor básico
	this->sizeFilas = 3;
	this->sizeColumnas = 3;
	this->miniTablero = new (std::nothrow) char* [this->sizeFilas];
	if (this->miniTablero != NULL) {
		for (int i = 0; i < this->sizeFilas; i++) {
			this->miniTablero[i] = new (std::nothrow) char[this->sizeColumnas];
			if ( this->miniTablero[i] == NULL ) {
				return;  // Fallo de memoria
			}
		}

		for (int i = 0; i < this->sizeFilas; i++) {
			for (int j = 0; j < this->sizeColumnas; j++) {
				this->miniTablero[i][j] = '0';
			}
		}
		this->miniTablero[0][0] = (char) casillero->getTipoTerreno();
		this->miniTablero[0][1] = (char) EstadoCasillero::casillerovacio;
	}

}


GraficoCasillero::GraficoCasillero( TipoTerrenoCasillero terreno ) {
	// Constructor básico
	this->sizeFilas = 3;
	this->sizeColumnas = 3;
	this->miniTablero = new (std::nothrow) char* [this->sizeFilas];
	if (this->miniTablero != NULL) {
		for (int i = 0; i < this->sizeFilas; i++) {
			this->miniTablero[i] = new (std::nothrow) char[this->sizeColumnas];
			if ( this->miniTablero[i] == NULL ) {
				return;  // Fallo de memoria
			}
		}

		for (int i = 0; i < this->sizeFilas; i++) {
			for (int j = 0; j < this->sizeColumnas; j++) {
				this->miniTablero[i][j] = '0';
			}
		}
		this->miniTablero[0][0] = (char) terreno;
		this->miniTablero[0][1] = (char) EstadoCasillero::casillerovacio;
	}

}

GraficoCasillero::GraficoCasillero( TipoTerrenoCasillero terreno, EstadoCasillero estado ) {
	// Constructor básico
	this->sizeFilas = 3;
	this->sizeColumnas = 3;
	this->miniTablero = new (std::nothrow) char * [this->sizeFilas];
	if (this->miniTablero != NULL) {
		for (int i = 0; i < this->sizeFilas; i++) {
			this->miniTablero[i] = new (std::nothrow) char[this->sizeColumnas];
			if ( this->miniTablero[i] == NULL ) {
				return;  // Fallo de memoria
			}
		}

		for (int i = 0; i < this->sizeFilas; i++) {
			for (int j = 0; j < this->sizeColumnas; j++) {
				this->miniTablero[i][j] = '0';
			}
		}
		this->miniTablero[0][0] = (char) terreno;
		this->miniTablero[0][1] = (char) estado;
	}

}

GraficoCasillero::~GraficoCasillero() {
	// Liberar memoria dinámica
	if ( this->miniTablero != NULL ) {
		for ( int i = 0; i < this->sizeFilas; i++ ) {
			if ( this->miniTablero[i] != NULL ) {
				delete[] this->miniTablero[i];
			}
		}
		delete[] this->miniTablero;
	}
}

// Getters
char ** GraficoCasillero::getMiniTablero() {
	return this->miniTablero;
}

// Setters

void GraficoCasillero::setSoldado( Soldado * soldado ) {
	if ( soldado != NULL ) {
		this->miniTablero[0][1] = (char) soldado->getJugador();
		this->miniTablero[0][1] = (char) soldado->getIDSoldado();
	}
}

void GraficoCasillero::setMina( Mina * mina ) {
	if ( mina != NULL ) {
		this->miniTablero[0][1] = (char) mina->getJugador();
		this->miniTablero[1][1] = 'M';
	}
}

void GraficoCasillero::setBombaQuimica( BombaQuimica * bomba ) {
	if ( bomba != NULL ) {
		this->miniTablero[0][1] = (char) bomba->getJugador();
		this->miniTablero[1][1] = 'B';
	}
}

void GraficoCasillero::setAvion( Avion * avion ) {
	if ( avion != NULL ) {
		this->miniTablero[0][1] = (char) avion->getJugador();
		this->miniTablero[2][0] = 'A';
	}
}

void GraficoCasillero::setBarco( Barco * barco ) {
	if ( barco != NULL ) {
		this->miniTablero[0][1] = (char) barco->getJugador();
		this->miniTablero[1][1] = 'B';
	}
}