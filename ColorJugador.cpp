#include "ColorJugador.h"

ColorJugador::ColorJugador() {
	this->jugador = 0;
	this->setColores();
}

ColorJugador::ColorJugador( int jugador ) {
	this->jugador = jugador;
	this->setColores();
}

ColorJugador::~ColorJugador() {
	this->colorVerde = 0;
	this->colorRojo = 0;
	this->colorAzul = 0;
}

int ColorJugador::getColorVerde() {
	return this->colorVerde;
}

int ColorJugador::getColorRojo() {
	return this->colorRojo;
}

int ColorJugador::getColorAzul() {
	return this->colorAzul;
}

int ColorJugador::getColorVerde( int jugador ) {
	this->jugador = jugador;
	this->setColores();
	return this->colorVerde;
}

int ColorJugador::getColorRojo( int  jugador ) {
	this->jugador = jugador;
	this->setColores();
	return this->colorRojo;
}

int ColorJugador::getColorAzul( int  jugador ) {
	this->jugador = jugador;
	this->setColores();
	return this->colorAzul;
}

void ColorJugador::setJugador( int jugador ) {
	this->jugador = jugador;
}

void ColorJugador::setColores() {
	switch ( this->jugador )
	{
	case 0:
		this->colorVerde = 255;
		this->colorRojo = 255;
		this->colorAzul = 255;
	case 1:
		this->colorVerde = 255;
		this->colorRojo = 0;
		this->colorAzul = 0;
		break;
	case 2:
		this->colorVerde = 0;
		this->colorRojo = 255;
		this->colorAzul = 0;
		break;
	case 3:
		this->colorVerde = 0;
		this->colorRojo = 0;
		this->colorAzul = 255;
		break;
	case 4:
		this->colorVerde = 100;
		this->colorRojo = 100;
		this->colorAzul = 100;
		break;
	default:
		this->colorVerde = 0;
		this->colorRojo = 0;
		this->colorAzul = 0;
		break;
	}

}