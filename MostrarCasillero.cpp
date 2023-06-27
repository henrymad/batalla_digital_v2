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
    // No hay pedidos de Memoria Din�mica
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
    char ** miniTablero;
    if ( this->graficoCasillero == NULL ) {
        return lineatexto;
    }
    miniTablero = this->graficoCasillero->getMiniTablero();
    switch ( linea ) {
        case 0:
            lineatexto = (miniTablero[ linea ][ 0 ] == (char) tierra) ? "T" : "A";
            if ( this->jugador == NULL ) {
                // Vista Global Observador
                lineatexto += "-" + std::string( 1, miniTablero[linea][1] );	// Est�n vac�os
                lineatexto += "-" + std::string( 1, miniTablero[linea][2] );
            }
            else {
                // Vista Jugador
                if ( miniTablero[ linea ][ 1 ] == (char) this->jugador->getIdJugador() ) {
                    lineatexto += "-" + std::string(1, miniTablero[linea][1]);
                    lineatexto += "-" + std::string(1, miniTablero[linea][2]);
                }
                else {
                    lineatexto += "-0-0";	// No visible
                }
            }
            break;
        case 1:
            if ( this->jugador == NULL ) {
                // Vista Global Observador
                lineatexto = std::string(1, miniTablero[linea][0]);
                lineatexto += "-" + std::string(1, miniTablero[linea][1]);
                lineatexto += "-" + std::string(1, miniTablero[linea][2]);
            }
            else {
                // Vista Jugador
                if ( miniTablero[linea][0] == (char) this->jugador->getIdJugador() ) {
                    lineatexto = std::string(1, miniTablero[linea][0]);
                    lineatexto += "-" + std::string(1, miniTablero[linea][1]);
                    lineatexto += "-" + std::string(1, miniTablero[linea][2]);
                }
                else {
                    lineatexto = " -0-0";	// No visible
                }
            }
            break;
        case 2:
            if ( this->jugador == NULL ) {
                // Vista Global Observador
                lineatexto = std::string(1, miniTablero[linea][0]);
                lineatexto += "-" + std::string(1, miniTablero[linea][1]);
                lineatexto += "-" + std::string(1, miniTablero[linea][2]);
            }
            else {
                // Vista Jugador
                if ( miniTablero[linea][1] == (char)this->jugador->getIdJugador() ) {
                    lineatexto = std::string(1, miniTablero[linea][0]);
                    lineatexto += "-" + std::string(1, miniTablero[linea][1]);
                    lineatexto += "-" + std::string(1, miniTablero[linea][2]);
                }
                else {
                    lineatexto += "-0-0";	// No visible
                }
            }
            break;
        default:
            break;
    }
    return lineatexto;
}