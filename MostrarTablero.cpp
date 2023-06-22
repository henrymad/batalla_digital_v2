#include "MostrarTablero.h"

MostrarTablero::MostrarTablero( Tablero3D * tablero ) {
	this->tablero = tablero;
	this->jugador = NULL;
}

MostrarTablero::MostrarTablero( Tablero3D* tablero, Jugador * jugador ) {
	this->tablero = tablero;
	this->jugador = jugador;
}

MostrarTablero::~MostrarTablero() {
}

void MostrarTablero::imprimir( string archivo ) {
	if ( this->tablero == NULL ) {
		return;
	}
	if ( archivo != "" ) {
		this->nombreArchivo = archivo;
	}
	if ( this->nombreArchivo != "" ) {
		ofstream salida;
		salida.open( this->nombreArchivo.c_str(), fstream::out);
		string Linea[3];
		// Lista < GraficoCasillero* >* listagraficos;
		// listagraficos = new Lista < GraficoCasillero * >;
		for (int i = 0; i < 3; i++ ) {
			Linea[i] = "|";
		}
		Casillero * casillero;
		GraficoCasillero * graficocasillero;
		graficocasillero = new GraficoCasillero( this->tablero );
		for ( int i = 1; i <= this->tablero->getSize_x(); i++ ) {
			casillero = tablero->getCasillero( i, 1, NIVEL_SUPERFICIE);
			graficocasillero->setCasillero(  casillero );
			//graficocasillero = GraficoCasillero( this->tablero, casillero );
			for (int i = 0; i < 3; i++) {
				Linea[i] += this->emitir( i, graficocasillero ) + "|";
			}
		}
		for ( int i = 0; i < 3; i++ ) {
			salida << Linea[i] << std::endl;
		}
		// Liberar recursos y memoria
		delete graficocasillero;
		salida.close();
	}
}

void MostrarTablero::setNombreArchivo( string archivo ) {
	this->nombreArchivo = archivo;

}

void MostrarTablero::setJugador( Jugador * jugador ) {
	this->jugador = jugador;
}

string MostrarTablero::emitir( int linea, GraficoCasillero * graficocasillero ) {
	string lineatexto = "";
	char ** miniTablero;
	miniTablero = graficocasillero->getMiniTablero();
	switch ( linea ) {
	case 0:
		lineatexto = (miniTablero[linea][0] == (char) tierra) ? "T" : "A";
		if (this->jugador == NULL) {
			// Vista Global Observador
			lineatexto += "-" + std::string(1, miniTablero[linea][1]);	// Están vacíos
			lineatexto += "-" + std::string(1, miniTablero[linea][2]);
		}
		else {
			// Vista Jugador
			if (miniTablero[linea][1] == (char)this->jugador->getIdJugador()) {
				lineatexto += "-" + std::string(1, miniTablero[linea][1]);
				lineatexto += "-" + std::string(1, miniTablero[linea][2]);
			}
			else {
				lineatexto += " -0-0";	// No visible
			}
		}
		break;
	case 1:
		if (this->jugador == NULL) {
			// Vista Global Observador
			lineatexto = std::string(1, miniTablero[linea][0]);
			lineatexto += "-" + std::string(1, miniTablero[linea][1]);
			lineatexto += "-" + std::string(1, miniTablero[linea][2]);
		}
		else {
			// Vista Jugador
			if (miniTablero[linea][0] == (char)this->jugador->getIdJugador()) {
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
		if (this->jugador == NULL) {
			// Vista Global Observador
			lineatexto = std::string(1, miniTablero[linea][0]);
			lineatexto += "-" + std::string(1, miniTablero[linea][1]);
			lineatexto += "-" + std::string(1, miniTablero[linea][2]);
		}
		else {
			// Vista Jugador
			if (miniTablero[linea][1] == (char)this->jugador->getIdJugador()) {
				lineatexto = std::string(1, miniTablero[linea][0]);
				lineatexto += "-" + std::string(1, miniTablero[linea][1]);
				lineatexto += "-" + std::string(1, miniTablero[linea][2]);
			}
			else {
				lineatexto += " -0-0";	// No visible
			}
		}
		break;
	default:
		break;
	}
	return lineatexto;
}