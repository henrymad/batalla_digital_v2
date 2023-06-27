#include "GraficoCasillero.h"

GraficoCasillero::GraficoCasillero() {
    // Constructor b�sico
    this->sizeFilas = 3;
    this->sizeColumnas = 3;
    this->miniTablero = NULL;
    this->tablero = NULL;
}

GraficoCasillero::GraficoCasillero( Tablero3D * tablero ) {
    this->sizeFilas = 3;
    this->tablero = tablero;
    this->sizeColumnas = 3;
    this->miniTablero = new (std::nothrow) char* [this->sizeFilas];
    if ( this->miniTablero != NULL ) {
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
    }
}

GraficoCasillero::~GraficoCasillero() {
    // Liberar memoria din�mica
    if ( this->miniTablero != NULL ) {
        for ( int i = 0; i < this->sizeFilas; i++ ) {
            if ( this->miniTablero[i] != NULL ) {
                delete[] this->miniTablero[i];
            }
        }
        delete[] this->miniTablero;
        this->miniTablero = NULL;
        this->tablero = NULL;
    }
}

// Getters
char ** GraficoCasillero::getMiniTablero() {
    return this->miniTablero;
}

// Setters

void GraficoCasillero::setTablero( Tablero3D * tablero ) {
    this->tablero = tablero;
}

void GraficoCasillero::setCasillero( Casillero * casillero ) {
    if ( this->tablero == NULL || casillero == NULL ) {
        return;
    }
    if ( this->miniTablero == NULL ) {
        // Pido memoria
        for (int i = 0; i < this->sizeFilas; i++) {
            this->miniTablero[i] = new (std::nothrow) char[this->sizeColumnas];
            if (this->miniTablero[i] == NULL) {
                return;  // Fallo de memoria
            }
        }

        for (int i = 0; i < this->sizeFilas; i++) {
            for (int j = 0; j < this->sizeColumnas; j++) {
                this->miniTablero[i][j] = '0';
            }
        }
    }
    // Escribo miniTablero
    this->miniTablero[0][0] = (char)casillero->getTipoTerreno();
    this->miniTablero[1][0] = ' '; // -> vac�o (char)casillero->getEstadoCasillero();
    if (casillero->getEstadoCasillero() == soldado) {
        this->miniTablero[1][0] = 'S';
        this->miniTablero[1][1] = (char)casillero->getSoldado()->getJugador();
        this->miniTablero[1][2] = (char)casillero->getSoldado()->getIDSoldado();
    }
    else if (casillero->getEstadoCasillero() == mina) {
        this->miniTablero[1][0] = 'M';
        this->miniTablero[1][1] = (char)casillero->getMina()->getJugador();		// Asumo una sola mina en la lista.
    }
    else if (casillero->getEstadoCasillero() == casilleroinactivo) {
        this->miniTablero[1][1] = 'X';
        this->miniTablero[1][0] = (char)casillero->getTurnosDeInactividad();
    }
    else if (casillero->getEstadoCasillero() == barco) {
        this->miniTablero[1][0] = 'B';
        this->miniTablero[1][1] = (char)casillero->getBarco()->getJugador();
    }
    else {
        // Vac�o
    }
    /*
    * Ahora en el Casillero debo revisar el espacio a�reo.
    *	Podr�a haber varios aviones a distintas alturas. Marco el de menor altura
    *   Es un poco absurdo que un mismo jugador coloque dos aviones en un mismo casillero.
    * 	Previendo "irregularidades" del terreno busco desde abajo hacia arriba a partir del
    *    primer casillero en el eje z con TipoTerrenoCasillero::aire
    */
    // Necesito tener acceso al Tablero.
    if (this->tablero != NULL) {
        if (casillero != NULL) {
            int x, y;
            x = casillero->getCoordenada()->getCoordenadaX();
            y = casillero->getCoordenada()->getCoordenadaY();
            // z = casillero->getCoordenada()->getCoordenada_z();
            for (int z = 1; z <= tablero->getSize_z(); z++) {
                Casillero* aux = tablero->getCasillero(x, y, z);
                if (aux == NULL) {
                    break;
                }
                else if (aux->getTipoTerreno() != aire)
                {
                    if (aux->getAvion() != NULL) {
                        this->miniTablero[2][0] = 'A';
                        this->miniTablero[2][1] = (char)casillero->getAvion()->getJugador();
                        this->miniTablero[2][2] = (char)casillero->getAvion()->getIDAvion();
                        break;
                    }
                }
            }
        }
    }

}

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