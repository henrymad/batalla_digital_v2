#pragma warning(disable : 4996)

#include "Graficas.h"
#include "EasyBMP.h"

Graficas::Graficas() {
    this->iHeight = FILAS_TABLERO * INDICE_PIXELACION;
    this->iWidth = COLUMNAS_TABLERO * INDICE_PIXELACION;
    this->iPixelSize = INDICE_PIXELACION;
    this->tablero = NULL;
}

Graficas::Graficas( Tablero3D* tablero ) {
    if ( tablero != NULL ) {
        this->iHeight = tablero->getSize_x() * INDICE_PIXELACION;
        this->iWidth = tablero->getSize_y() * INDICE_PIXELACION;
    }
    else {
        this->iHeight = FILAS_TABLERO * INDICE_PIXELACION;
        this->iWidth = COLUMNAS_TABLERO * INDICE_PIXELACION;
    }
    this->iPixelSize = INDICE_PIXELACION;
    this->tablero = tablero;
}

Graficas::~Graficas() {
}

void Graficas::graficarSuperficie( string archivo ) {
    if ( this->tablero == NULL ) {
        return;
    }
    Casillero * casillero;
    BMP Output;
    Output.SetSize( this->iHeight, this->iWidth );
    Output.SetBitDepth( PROFUNDIDAD_BIT );
    int size_x = tablero->getSize_x();
    int size_y = tablero->getSize_y();
    for ( int i = 1; i <= size_x; i++ ) {
        for ( int j = 1; j <= size_y; j++ ) {
            casillero = this->tablero->getCasillero( i, j, NIVEL_SUPERFICIE );
            if ( casillero != NULL ) {
                //this->dibujarPixel( i, j, casillero, Output );
                this->dibujarPixel( casillero, Output );
            }
        }
        std::cout << i << endl;
    }
    //int length = archivo.length();
    // char * sarchivo = new char[ length + 1 ];
    // strcpy( sarchivo, archivo.c_str() );

    Output.WriteToFile( archivo.c_str() );
    //delete[] sarchivo;
}

void Graficas::graficarSuperficie( string archivo, Jugador * jugador) {
    if (this->tablero == NULL) {
        return;
    }
    if ( jugador == NULL ) {
        return;
    }
    Casillero* casillero;
    BMP Output;
    Output.SetSize( this->iHeight, this->iWidth );
    Output.SetBitDepth( PROFUNDIDAD_BIT );
    int size_x = tablero->getSize_x();
    int size_y = tablero->getSize_y();
    for (int i = 1; i <= size_x; i++) {
        for (int j = 1; j <= size_y; j++) {
            casillero = this->tablero->getCasillero(i, j, NIVEL_SUPERFICIE);
            if ( casillero != NULL ) {
                this->dibujarPixel( casillero, Output );
                //this->dibujarPixel(i, j, casillero, Output);
            }
        }
        std::cout << i << endl;
    }
    Output.WriteToFile(archivo.c_str());
}

/*
void Graficas::dibujarPixel( int i, int j, Casillero * casillero, BMP & oBMP ) {
	TipoTerrenoCasillero terreno = casillero->getTipoTerreno();
	// EstadoCasillero estado = casillero->getEstadoCasillero();
	for ( int x = 0; x < INDICE_PIXELACION; x++ ) {
		for ( int y = 0; y < INDICE_PIXELACION; y++ ) {
			if (terreno == agua ) {
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 102;		//0
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION  + y )->Green = 255;		//10
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 255;		//80
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
			}
			else if (terreno == tierra ) {
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 153;		//90
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Green = 73;		//50
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 0;			//0
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
			}
			else {
				// Piff ...
			}
		}
	}
}
*/

void Graficas::dibujarPixel( Casillero * casillero, Jugador * jugador, BMP & oBMP ) {
    TipoTerrenoCasillero terreno = casillero->getTipoTerreno();
    int i = casillero->getCoordenada()->getCoordenadaX();
    int j = casillero->getCoordenada()->getCoordenadaY();
    for ( int x = 0; x < INDICE_PIXELACION; x++ ) {
        for ( int y = 0; y < INDICE_PIXELACION; y++ ) {
            if ( terreno == agua ) {
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Red = 102;		//0
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Green = 255;		//10
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Blue = 255;		//80
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Alpha = 0;
            }
            else if (terreno == tierra) {
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Red = 153;		//90
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Green = 73;		//50
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Blue = 0;			//0
                oBMP(i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y)->Alpha = 0;
            }
            else {
                // Piff ...
            }
        }
    }
    ColorJugador * color;
    color = new ColorJugador;
    if ( casillero->getEstadoCasillero() == casillerovacio ) {
        // Ya est� dibujado el terreno.
        // Ver si hay un avi�n encima
        Casillero * aux = detectarAvion(casillero, jugador);
        if ( aux != NULL ) {
            dibujarAvion( aux, jugador, oBMP, color );
        }
    }
    else if ( casillero->getEstadoCasillero() == casilleroinactivo ) {
        // Fila 1
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
        // Fila 2
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
        // Fila 3
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
    }
    else if ( casillero->getSoldado() != NULL ) {
        this->dibujarSoldado( casillero, jugador, oBMP, color );
    }
    else if ( casillero->getMina() != NULL ) {
        this->dibujarMina( casillero, jugador, oBMP, color );
    }
    else if ( casillero->getBarco() != NULL ) {
        this->dibujarBarco( casillero, jugador, oBMP, color );
    }
    else {
        // Revisar Avion
        for ( int k = NIVEL_SUPERFICIE + 1; k < this->tablero->getSize_z(); k++ ) {
            Casillero* aux = this->tablero->getCasillero( i, j, k );
            if ( aux->getAvion() != NULL ) {
                if ( jugador == NULL ) {
                    dibujarAvion( aux, NULL, oBMP, color );
                    break;
                }
                else {
                    if ( aux->getAvion()->getJugador() == jugador->getIdJugador() ) {
                        dibujarAvion( aux, jugador, oBMP, color );
                        break;
                    }
                }
            }
        }
    }
    delete color;
}

void Graficas::dibujarPixel( Casillero * casillero, BMP & oBMP ) {
    TipoTerrenoCasillero terreno = casillero->getTipoTerreno();
    int i = casillero->getCoordenada()->getCoordenadaX();
    int j = casillero->getCoordenada()->getCoordenadaY();
    for (int x = 0; x < INDICE_PIXELACION; x++) {
        for (int y = 0; y < INDICE_PIXELACION; y++) {
            if (terreno == agua) {
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 102;		//0
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Green = 255;		//10
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 255;		//80
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
            }
            else if (terreno == tierra) {
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 153;		//90
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Green = 73;		//50
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 0;			//0
                oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
            }
            else {
                // Piff ...
            }
        }
    }
    ColorJugador * color;
    color = new ColorJugador;
    if ( casillero->getEstadoCasillero() == casillerovacio ) {
        // Ver si hay un avi�n encima
        Casillero * aux = detectarAvion(casillero, NULL );
        if (aux != NULL) {
            dibujarAvion(aux, NULL, oBMP, color);
        }
    }
    else if ( casillero->getEstadoCasillero() == casilleroinactivo ) {
        // Fila 1
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
        // Fila 2
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
        // Fila 3
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
    }
    else if ( casillero->getSoldado() != NULL ) {
        // if ( casillero->getSoldado()->getJugador() == jugador->getIdJugador() ) {
        // Fila 1
        color->setJugador( casillero->getSoldado()->getJugador() );
        oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        // Fila 2
        oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        // Fila 3
        oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    }
    else if (casillero->getMina() != NULL) {
        // if (casillero->getSoldado()->getJugador() == jugador->getIdJugador()) {
        // Fila 1
        color->setJugador( casillero->getMina()->getJugador() );
        oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        // Fila 2
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        // Fila 3
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    }
    else if (casillero->getBarco() != NULL) {
        //if (casillero->getBarco()->getJugador() == jugador->getIdJugador()) {
        color->setJugador( casillero->getBarco()->getJugador() );
        // Fila 1
        oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        // Fila 2
        oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
        oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
        oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
        // Fila 3
    }
    else {
        // Revisar Avion
        for ( int k = NIVEL_SUPERFICIE + 1; k < this->tablero->getSize_z(); k++ ) {
            Casillero * aux = this->tablero->getCasillero (i, j, k );
            if ( aux->getAvion() != NULL ) {
                color->setJugador( casillero->getAvion()->getJugador() );
                // Fila 1
                oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
                oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
                oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
                // Fila 2
                oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
                oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
                oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
                // Fila 3
                oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
                oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
                oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
                oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
                oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
                oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
                oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
                oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
                oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
                break;
            }
        }
    }
    delete color;
}

/*
* void Graficas::dibujarPixel( int i, int j, Casillero * casillero, Jugador * jugador, BMP & oBMP ) {
	if ( casillero == NULL || jugador == NULL ) {
		return;
	}
	TipoTerrenoCasillero terreno = casillero->getTipoTerreno();
	//EstadoCasillero estado = casillero->getEstadoCasillero();
	// Traslaci�n de las coordenadas del usuario
	i--; j--;
	for (int x = 0; x < INDICE_PIXELACION; x++) {
		for (int y = 0; y < INDICE_PIXELACION; y++) {
			if (terreno == agua) {
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 102;		//0
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Green = 255;	//10
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 255;	//80
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
			}
			else if (terreno == tierra) {
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 153;		// 90
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Green = 73;	// 50
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 0;		// 0
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
			}
			else {
				// Piff ...
			}
		}
	}
	if ( casillero->getEstadoCasillero() == casillerovacio ) {
		// Nada haremos, nada haremos
	}
	else if ( casillero->getEstadoCasillero() == casilleroinactivo ) {
		// Fila 1
		oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
		oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
		oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
		// Fila 2
		oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
		oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
		oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
		// Fila 3
		oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
		oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
		oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
	}
	else if ( casillero->getSoldado() != NULL ) {
		if ( casillero->getSoldado()->getJugador() == jugador->getIdJugador() ) {
			// Fila 1
			oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
			// Fila 2
			oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
			// Fila 3
			oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
		}
	}
	else if ( casillero->getMina() != NULL ) {
		if (casillero->getMina()->getJugador() == jugador->getIdJugador()) {
			// Fila 1
			oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
			// Fila 2
			oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
			// Fila 3
			oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
		}
	}
	else if ( casillero->getBarco() != NULL) {
		if ( casillero->getBarco()->getJugador() == jugador->getIdJugador() ) {
			// Fila 1
			oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
			// Fila 2
			oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
			oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
			// Fila 3
		}
	}
	else {
		// Revisar Avion
		for ( int k = NIVEL_SUPERFICIE + 1; k < this->tablero->getSize_z(); k++ ) {
			Casillero * aux = this->tablero->getCasillero( i, j, k );
			if ( aux->getAvion() != NULL ) {
				if ( aux->getAvion()->getJugador() == jugador->getIdJugador() ) {
					// Fila 1
					oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
					oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
					oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
					// Fila 2
					oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
					oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
					oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
					// Fila 3
					oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = 255;
					oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = 255;
					break;
				}
			}
		}
	}
}
*/

void Graficas::dibujarSoldado( Casillero * casillero, Jugador * jugador, BMP & oBMP, ColorJugador * color ) {
    int i = casillero->getCoordenada()->getCoordenadaX();
    int j = casillero->getCoordenada()->getCoordenadaY();
    if ( jugador == NULL ) { // Vista tablero general
        color->setJugador( 0 );
    }
    else {
        if (  casillero->getSoldado() != NULL ) {
            if ( jugador->getIdJugador() != casillero->getSoldado()->getJugador() ) {
                return;
            }
            color->setJugador( jugador->getIdJugador() );
        }
    }
    // Fila 1
    oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    // Fila 2
    oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    // Fila 3
    oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
}

void Graficas::dibujarMina( Casillero * casillero, Jugador * jugador, BMP & oBMP, ColorJugador * color ) {
    int i = casillero->getCoordenada()->getCoordenadaX();
    int j = casillero->getCoordenada()->getCoordenadaY();
    if (jugador == NULL) { // Vista tablero general
        color->setJugador( 0 );
    }
    else {
        if ( casillero->getMina() != NULL ) {
            if ( jugador->getIdJugador() != casillero->getMina()->getJugador() ) {
                return;
            }
            color->setJugador( jugador->getIdJugador() );
        }
    }
    // Fila 1
    oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 0 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 0 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    // Fila 2
    oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    // Fila 3
    oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
}

void Graficas::dibujarAvion( Casillero * casillero, Jugador * jugador, BMP & oBMP, ColorJugador * color ) {
    int i = casillero->getCoordenada()->getCoordenadaX();
    int j = casillero->getCoordenada()->getCoordenadaY();
    if (jugador == NULL) { // Vista tablero general
        color->setJugador( 0 );
    }
    else {
        if ( casillero->getAvion() != NULL ) {
            if ( jugador->getIdJugador() != casillero->getAvion()->getJugador() ) {
                return;
            }
            color->setJugador( jugador->getIdJugador() );
        }
    }
    // Fila 1
    oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    // Fila 2
    oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    // Fila 3
    oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 2 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 2 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
    oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Red = color->getColorRojo();
    oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Green = color->getColorVerde();
    oBMP( 2 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION )->Blue = color->getColorAzul();
}

void Graficas::dibujarBarco( Casillero * casillero, Jugador * jugador, BMP & oBMP, ColorJugador * color ) {
    int i = casillero->getCoordenada()->getCoordenadaX();
    int j = casillero->getCoordenada()->getCoordenadaY();
    if (jugador == NULL) { // Vista tablero general
        color->setJugador( 0 );
    }
    else {
        if ( casillero->getBarco() != NULL ) {
            if ( jugador->getIdJugador() != casillero->getBarco()->getJugador() ) {
                return;
            }
            color->setJugador( jugador->getIdJugador() );
        }
    }
    // Fila 1
    oBMP(0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION)->Red = color->getColorRojo();
    oBMP(0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION)->Green = color->getColorVerde();
    oBMP(0 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION)->Blue = color->getColorAzul();
    // Fila 2
    oBMP(1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION)->Red = color->getColorRojo();
    oBMP(1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION)->Green = color->getColorVerde();
    oBMP(1 + i * INDICE_PIXELACION, 0 + j * INDICE_PIXELACION)->Blue = color->getColorAzul();
    oBMP(1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION)->Red = color->getColorRojo();
    oBMP(1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION)->Green = color->getColorVerde();
    oBMP(1 + i * INDICE_PIXELACION, 1 + j * INDICE_PIXELACION)->Blue = color->getColorAzul();
    oBMP(1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION)->Red = color->getColorRojo();
    oBMP(1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION)->Green = color->getColorVerde();
    oBMP(1 + i * INDICE_PIXELACION, 2 + j * INDICE_PIXELACION)->Blue = color->getColorAzul();
    // Fila 3
}

Casillero * Graficas::detectarAvion( Casillero * casillero, Jugador * jugador ) {
    Casillero * casillerosuperior;
    casillerosuperior = NULL;
    if ( casillero != NULL && this->tablero != NULL ) {
        int x = casillero->getCoordenada()->getCoordenadaX();
        int y = casillero->getCoordenada()->getCoordenadaY();
        for (int z = NIVEL_SUPERFICIE + 1; z <= this->tablero->getSize_z(); z++) {
            Casillero * aux = this->tablero->getCasillero( x + 1, y + 1, z + 1 );
            if ( aux == NULL ) {

            }
            else if ( aux->getAvion() != NULL ) {
                if ( jugador == NULL ) {
                    return aux;
                }
                else if ( aux->getAvion()->getJugador() == jugador->getIdJugador() ) {
                    return aux;
                }
            }
        }
    }
    return casillerosuperior;
}
