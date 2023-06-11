#include <new>

#include "Tablero3D.h"

/**Tablero3D::Tablero3D() {
	this->tablero = NULL;
	this->size_x = CANTIDAD_DE_CASILLERO_EJE_X;
	this->size_y = CANTIDAD_DE_CASILLERO_EJE_Y;
	this->size_z = CANTIDAD_DE_CASILLERO_EJE_Z;
	this->tablero = new Lista < Lista < Lista < Casillero * >* >* >;

	for (int x = 0; x < this->size_x; x++) {
		Lista < Lista < Casillero * > * > * elemento;
		elemento = new Lista < Lista < Casillero * > * >;
		for (int y = 0; y < this->size_y; y++) {
			Lista < Casillero * > * subelemento;
			subelemento = new Lista < Casillero * >;
			for (int z = 0; z < this->size_z; z++) {
				Casillero * casillero;
				casillero = new Casillero();
				subelemento->agregar( casillero);
			}
			elemento->agregar(subelemento);
		}
		this->tablero->agregar(elemento);
	}
}**/

/**Tablero3D::Tablero3D( int x, int y, int z) {
    //Utilizar notacion camel-case
	this->tablero = NULL;
	this->size_x = x;
	this->size_y = y;
	this->size_z = z;
	this->tablero = new Lista < Lista < Lista < Casillero* > * > * >;

	for ( int x = 0; x < this->size_x; x++ ) {
		Lista < Lista < Casillero * > * > * elemento;
		elemento = new Lista < Lista < Casillero * > * >;
		for ( int y = 0; y < this->size_y; y++ ) {
			Lista < Casillero * > * subelemento;
			subelemento = new Lista < Casillero * >;
			for ( int z = 0; z < this->size_z; z++ ) {
				Casillero * casillero;
				casillero = new Casillero();
				subelemento->agregar( casillero );
			}
			elemento->agregar( subelemento );
		}
		this->tablero->agregar( elemento );
	}
}++/

/**Tablero3D::~Tablero3D() {
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
	this->tablero = nullptr;
}**/

/**void Tablero3D::setCasillero( Casillero * casillero, int x, int y, int z ) {
	if (this->checkCoordenadas(x, y, z)) {
		return;
	}
	Lista < Lista < Casillero * > * > * elemento;
	Lista < Casillero * > * subelemento;
	// Traslaci�n de coordenadas
	x--; y--; z--;
	elemento = this->tablero->obtenerDato( x );
	subelemento = elemento->obtenerDato( y );
	subelemento->asignar( casillero, z );
}**/

/**Casillero * Tablero3D::getCasillero( int x, int y, int z ) {
	if ( this->checkCoordenadas( x, y, z ) ) {
		return nullptr;
	}
	Lista < Lista < Casillero * > * > * elemento;
	Lista < Casillero * > * subelemento;
	// Traslaci�n de coordenadas
	x--; y--; z--;
	elemento = this->tablero->obtenerDato( x );
	subelemento = elemento->obtenerDato( y );
	Casillero * Casillero;
	Casillero = subelemento->obtenerDato( z );
	return Casillero;
}**/

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
	if ( x < 0 || x > this->size_x - 1 ) {
		return false;
	}
	if ( y < 0 || y > this->size_y - 1) {
		return false;
	}
	if ( z < 0 || z > this->size_z - 1) {
		return false;
	}
	return true;
}