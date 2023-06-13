#include "MostrarCasillero.h"

MostrarCasillero::MostrarCasillero() {
	this->graficoCasillero = NULL;
	this->jugador = NULL;
}

MostrarCasillero::MostrarCasillero( GraficoCasillero * graficoCasillero ) {
	this->graficoCasillero = graficoCasillero;
	this->jugador = NULL;
}

MostrarCasillero::MostrarCasillero( GraficoCasillero * graficoCasillero, Jugador * jugador ) {
	this->graficoCasillero = graficoCasillero;
	this->jugador = jugador;
}

MostrarCasillero::~MostrarCasillero() {
	// No hay pedidos de Memoria Dinámica
	this->graficoCasillero = NULL;
	this->jugador = NULL;
}

void MostrarCasillero::setCasillero( GraficoCasillero * graficoCasillero ) {
	this->graficoCasillero = graficoCasillero;
}

void MostrarCasillero::setJugador( Jugador * jugador ) {
	this->jugador = jugador;
}

string MostrarCasillero::emitir( int linea ) {
	string lineatexto = "";
	char** miniTablero;
	if ( this->graficoCasillero == NULL ) {
		return lineatexto;
	}
	miniTablero = this->graficoCasillero->getMiniTablero();
	if (linea >= 1 && linea <= 3) {
		switch (linea) {
			case 1:
				lineatexto = (miniTablero[linea][0] == (char)TipoTerrenoCasillero::tierra) ? "T" : "A";
				if (this->jugador = NULL) {
					// Vista Global Observador
					lineatexto += " " + miniTablero[linea][1];
					lineatexto += " " + miniTablero[linea][2];
				}
				else {
					// Vista Jugador
					if (miniTablero[linea][1] == (char)this->jugador->getIdJugador()) {
						lineatexto += " " + miniTablero[linea][1];
						lineatexto += " " + miniTablero[linea][2];
					}
					else {
						lineatexto += " 0 0";	// No visible
					}
				}
				break;
			case 2:
				if (this->jugador = NULL) {
					// Vista Global Observador
					lineatexto += " " + miniTablero[linea][0];
					lineatexto += " " + miniTablero[linea][1];
					lineatexto += " " + miniTablero[linea][2];
				}
				else {
					// Vista Jugador
					if (miniTablero[linea][1] == (char)this->jugador->getIdJugador()) {
						lineatexto += " " + miniTablero[linea][1];
						lineatexto += " " + miniTablero[linea][2];
					}
					else {
						lineatexto += " 0 0";	// No visible
					}
				}
				break;
			case 3:
				if (this->jugador = NULL) {
					// Vista Global Observador
					lineatexto += " " + miniTablero[linea][0];
					lineatexto += " " + miniTablero[linea][1];
					lineatexto += " " + miniTablero[linea][2];
				}
				else {
					// Vista Jugador
					if (miniTablero[linea][1] == (char)this->jugador->getIdJugador()) {
						lineatexto += " " + miniTablero[linea][1];
						lineatexto += " " + miniTablero[linea][2];
					}
					else {
						lineatexto += " 0 0";	// No visible
					}
				}
				break;
			default:
				break;
				/*
			*/
		}
	}
	return lineatexto;
}