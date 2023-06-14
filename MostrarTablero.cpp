#include "MostrarTablero.h"

MostrarTablero::MostrarTablero( Tablero3D * tablero ) {
	this->tablero = tablero;
}

MostrarTablero::~MostrarTablero() {
}

void MostrarTablero::imprimir( string archivo ) {
	this->nombreArchivo = archivo;
}

void MostrarTablero::setNombreArchivo( string archivo ) {
	this->nombreArchivo = archivo;
}

void MostrarTablero::setJugador( Jugador * jugador ) {
	this->jugador = jugador;
}

void MostrarTablero::setJugador( int idJugador ) {

}