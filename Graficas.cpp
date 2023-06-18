#pragma warning(disable : 4996)

#include "Graficas.h"
#include "EasyBMP.h"

Graficas::Graficas() {
	this->iHeight = FILAS_TABLERO * INDICE_PIXELACION;
	this->iWidth = COLUMNAS_TABLERO * INDICE_PIXELACION;
	this->iPixelSize = INDICE_PIXELACION;
	this->tablero = nullptr;
};

Graficas::Graficas( Tablero3D* tablero) {
	this->iHeight = FILAS_TABLERO * INDICE_PIXELACION;
	this->iWidth = COLUMNAS_TABLERO * INDICE_PIXELACION;
	this->iPixelSize = INDICE_PIXELACION;
	this->tablero = tablero;
};

Graficas::~Graficas() {
};

void Graficas::graficarSuperficie( string archivo ) {
	if ( this->tablero == NULL ) {
		return;
	}
	Casillero * casillero;
	BMP Output;
	Output.SetSize( FILAS_TABLERO * INDICE_PIXELACION , COLUMNAS_TABLERO * INDICE_PIXELACION );
	Output.SetBitDepth( PROFUNDIDAD_BIT );
	for ( int i = 1; i <= FILAS_TABLERO; i++ ) {
		for ( int j = 1; j <= COLUMNAS_TABLERO; j++ ) {
			casillero = this->tablero->getCasillero( i, j, NIVEL_SUPERFICIE );
			if ( casillero != NULL ) {
				this->dibujarPixel( i, j, casillero, Output);
			}
		}
		std::cout << i << endl;
	}
	int length = archivo.length();
	char * sarchivo = new char[ length + 1 ];
	strcpy( sarchivo, archivo.c_str() );

	Output.WriteToFile( sarchivo );
	delete[] sarchivo;
};

void Graficas::dibujarPixel( int i, int j, Casillero * casillero, BMP & oBMP ) {
	TipoTerrenoCasillero terreno = casillero->getTipoTerreno();
	EstadoCasillero estado = casillero->getEstadoCasillero();
	// Traslación de las coordenadas del usuario
	i--; j--;
	for ( int x = 0; x < INDICE_PIXELACION; x++ ) {
		for ( int y = 0; y < INDICE_PIXELACION; y++ ) {
			if (terreno == TipoTerrenoCasillero::agua ) {
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 0;
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION  + y )->Green = 10;
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 80;
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
			}
			else if (terreno == TipoTerrenoCasillero::tierra ) {
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Red = 90;
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Green = 50;
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Blue = 0;
				oBMP( i * INDICE_PIXELACION + x, j * INDICE_PIXELACION + y )->Alpha = 0;
			}
			else {
				// Piff ...
			}
		}
	}
};
