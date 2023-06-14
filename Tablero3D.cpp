#include <new>

#include "Tablero3D.h"

Tablero3D::Tablero3D() {
	this->tablero = NULL;
	this->size_x = FILAS_TABLERO;
	this->size_y = COLUMNAS_TABLERO;
	this->size_z = ALTURA_TABLERO;
	this->tablero = new Lista < Lista < Lista < Casillero * > * > * >;

	for (int x = 0; x < this->size_x; x++) {
		Lista < Lista < Casillero * > * > * elemento;
		elemento = new Lista < Lista < Casillero * > * >;
		for (int y = 0; y < this->size_y; y++) {
			Lista < Casillero * > * subelemento;
			subelemento = new Lista < Casillero * >;
			for (int z = 0; z < this->size_z; z++) {
				Casillero * casillero;
				casillero = new Casillero(x, y, z);
				// casillero = new Casillero();
				subelemento->agregarFinal( casillero);
			}
			elemento->agregarFinal(subelemento);
		}
		this->tablero->agregarFinal(elemento);
	}
}

Tablero3D::Tablero3D( int size_x, int size_y, int size_z) {
	this->tablero = NULL;
	this->size_x = size_x;
	this->size_y = size_y;
	this->size_z = size_z;
	this->tablero = new Lista < Lista < Lista < Casillero* > * > * >;

	for ( int x = 0; x < this->size_x; x++ ) {
		Lista < Lista < Casillero * > * > * elemento;
		elemento = new Lista < Lista < Casillero * > * >;
		for ( int y = 0; y < this->size_y; y++ ) {
			Lista < Casillero * > * subelemento;
			subelemento = new Lista < Casillero * >;
			for ( int z = 0; z < this->size_z; z++ ) {
				Casillero * casillero;
				casillero = new Casillero( x, y, z);
				subelemento->agregarFinal( casillero );
			}
			elemento->agregarFinal( subelemento );
		}
		this->tablero->agregarFinal( elemento );
	}
}

Tablero3D::~Tablero3D() {
	for ( int x = 0; x < this->size_x; x++ ) {
		Lista < Lista < Casillero * > * > * elemento;
		elemento = this->tablero->obtenerDato( x );
		for ( int y = 0; y < this->size_y; y++ ) {
			Lista < Casillero* > * subelemento;
			subelemento = elemento->obtenerDato(y);
			subelemento->borrarLista();
		}
		elemento->borrarLista();
	}
	this->size_x = 0;
	this->size_y = 0;
	this->size_z = 0;
	this->tablero = NULL;
}

void Tablero3D::setCasillero( Casillero * casillero, int x, int y, int z ) {
	if ( ! this->checkCoordenadas(x, y, z)) {
		return;
	}
	Lista < Lista < Casillero * > * > * elemento;
	Lista < Casillero * > * subelemento;

	// Traslación de coordenadas
	x--; y--; z--;
	casillero->getCoordenada()->setCoordenada_x( x );
	casillero->getCoordenada()->setCoordenada_y( y );
	casillero->getCoordenada()->setCoordenada_z( z );
	elemento = this->tablero->obtenerDato( x );
	subelemento = elemento->obtenerDato( y );
	subelemento->asignar( casillero, z );
}

Casillero * Tablero3D::getCasillero( int x, int y, int z ) {
	if ( ! this->checkCoordenadas( x, y, z ) ) {
		return NULL;
	}
	Lista < Lista < Casillero * > * > * elemento;
	Lista < Casillero * > * subelemento;

	// Traslación de coordenadas
	x--; y--; z--;
	elemento = this->tablero->obtenerDato( x );
	subelemento = elemento->obtenerDato( y );
	Casillero * Casillero;
	Casillero = subelemento->obtenerDato( z );
	return Casillero;
}

int Tablero3D::getSize_x() {
	return this->size_x;
}

int Tablero3D::getSize_y() {
	return this->size_y;
}

int Tablero3D::getSize_z() {
	return this->size_z;
}

bool Tablero3D::checkCoordenadas( int x, int y, int z ) {
	if ( x < 1 || x > this->size_x ) {
		return false;
	}
	if ( y < 1 || y > this->size_y ) {
		return false;
	}
	if ( z < 1 || z > this->size_z ) {
		return false;
	}
	return true;
}