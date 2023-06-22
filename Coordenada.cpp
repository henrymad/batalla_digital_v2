#include "Coordenada.h"

Coordenada::Coordenada() {
}

Coordenada::Coordenada( int Coordenada_x, int Coordenada_y, int Coordenada_z ) 
	: coordenada_x( Coordenada_x ), coordenada_y(Coordenada_y), coordenada_z(Coordenada_z)
{
}

Coordenada::Coordenada( const Coordenada & coordenada ) {
	if ( this != &coordenada ) {
		this->coordenada_x = coordenada.coordenada_x;
		this->coordenada_y = coordenada.coordenada_y;
		this->coordenada_z = coordenada.coordenada_y;
	}
}

Coordenada::~Coordenada() {
	/* No hay memoria dinámica para liberar, sólo limpiar la RAM */
	this->coordenada_x = 0;
	this->coordenada_y = 0;
	this->coordenada_z = 0;
}

Coordenada const & Coordenada::operator=( Coordenada const & coordenada ) {
	Coordenada valor;
	if ( this != &coordenada ) {
		this->coordenada_x = coordenada.coordenada_x;
		this->coordenada_y = coordenada.coordenada_y;
		this->coordenada_z = coordenada.coordenada_y;
	}
	return *this;
}

void Coordenada::setCoordenada_x( int coordenada_x) {
	this->coordenada_x = this->coordenada_x;
}

void Coordenada::setCoordenada_y(int Coordenada_y ) {
	this->coordenada_y = this->coordenada_y;
}

void Coordenada::setCoordenada_z(int Coordenada_z ) {
	this->coordenada_z = this->coordenada_z;
}

int Coordenada::getCoordenada_x() {
	return this->coordenada_x;
}

int Coordenada::getCoordenada_y() {
	return this->coordenada_y;
}

int Coordenada::getCoordenada_z() {
	return this->coordenada_z;
}