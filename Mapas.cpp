#include "Mapas.h"

Mapas::Mapas( Tablero3D * tablero ) {
	this->tablero = tablero;
	this->jugador = NULL;
}

//  Setters

void Mapas::cargarMapaDefault() {
	Casillero * casillero;
	if ( this->tablero != NULL ) {
		for ( int i = 1; i <= this->tablero->getSize_x(); i++ ) {
			for ( int j = 1; j <= this->tablero->getSize_y(); j++ ) {
				for (int k = 1; k <= this->tablero->getSize_z(); k++ ) {
					casillero = tablero->getCasillero( i, j, k );
					if ( k > NIVEL_SUPERFICIE ) {
						casillero->setTipoTerreno( TipoTerrenoCasillero::aire );
					}
					else {
						casillero->setTipoTerreno( TipoTerrenoCasillero::tierra );
						if ( i > 160 && j < 150 ) {
							casillero->setTipoTerreno( TipoTerrenoCasillero::agua );
						}
						else if (  ( j > 70 && j < 140 ) && ( i >  110 && i <= 160 ) ) {
							casillero->setTipoTerreno( TipoTerrenoCasillero::agua );
						}
						else if ( ( j > 100 && j < 120 ) && ( i > 80  && i <= 110 ) ) {
							casillero->setTipoTerreno( TipoTerrenoCasillero::agua );
						}
					}
				}
			}
		}
	}
}

void Mapas::cargarMapa2D( string archivo ) {
	if ( archivo == "" ) { 
		return;
	}
	ifstream entrada( archivo.c_str() );
	if ( entrada.is_open() ) {
		string linea;
		for ( int i = 1; i <= this->tablero->getSize_x(); i++ ) {
			if ( std::getline(entrada, linea) ) {
				break;
			}
			if ( linea.length() == this->tablero->getSize_y()) {
				for (int j = 1; j <= this->tablero->getSize_y(); j++) {

					char caracter = linea[j];
					if ( caracter == 'T' ) {
					}
					else if ( caracter == 'A' ) {

					}
				}
			}
		}
	}
}

void Mapas::cargarMapa3D( string archivo ) {
	if (archivo == "") {
		return;
	}
	ifstream entrada(archivo.c_str());
	if ( entrada.is_open() ) {

	}
}

void Mapas::imprimirMapa( string archivo, Jugador * jugador ) {
	if (this->tablero == NULL) {
		return;
	}
	if (archivo != "") {
		this->nombreArchivo = archivo;
	}
	if (this->nombreArchivo != "") {
		ofstream salida;
		salida.open(this->nombreArchivo.c_str(), fstream::out);
		for ( int i = 1; i <= this->tablero->getSize_x(); i++ ) {
			for ( int j = 1; j <= this->tablero->getSize_y(); j++ ) {
				salida << '|' << this->Celda(tablero->getCasillero(i, j, NIVEL_SUPERFICIE), jugador);
			}
			salida << '|' << std::endl;
		}
		// Liberar recursos y memoria
		salida.close();
	}
}

void Mapas::setNombreArchivo(string archivo) {
	this->nombreArchivo = archivo;

}

void Mapas::setJugador( Jugador * jugador ) {
	this->jugador = jugador;
}

string Mapas::Celda( Casillero * casillero, Jugador * jugador ) {
	string celda = " ";
	if ( casillero == NULL ) {
		return celda;
	}
	if ( casillero->getEstadoCasillero() == EstadoCasillero::casilleroinactivo ) {
		/*
		if ( casillero->getBomba() != NULL ) {
			celda = "B";
		}
		else {
			celda = "X";
		}
		*/
	}
	else if ( casillero->getEstadoCasillero() == EstadoCasillero::casillerovacio ) {

	}
	else if ( casillero->getSoldado() != NULL ) {
		if ( jugador == NULL ) {
			celda = "S";
		}
		else if ( casillero->getSoldado()->getJugador() == jugador->getIdJugador()  ) {
			celda = "S";
		}
		else {
			celda = " ";
		}
	}
	else if ( casillero->getMina(0) != NULL ) {
		if ( jugador == NULL ) {
			celda = "M";
		}
		else if ( casillero->getSoldado()->getJugador() == jugador->getIdJugador() ) {
			celda = "M";
		}
		else {
			celda = " ";
		}
	}
	else if ( casillero->getBarco() != NULL ) {
		if (jugador == NULL) {
			celda = "B";
		}
		else if ( casillero->getSoldado()->getJugador() == jugador->getIdJugador() ) {
			celda = "B";
		}
		else {
			celda = "C";
		}
	}
	if ( celda == " " ) {
		celda = this->hayAvion( casillero, jugador );
		if (celda == "") { 
			celda = " ";
		}
	}
	return celda;
}

string Mapas::hayAvion( Casillero * casillero, Jugador * jugador ) {
	string sValor = "";
	if ( this->tablero != NULL ) {
		Casillero * casilleroactual;
		for ( int i = 1; i <= tablero->getSize_z(); i++ ) {
			casilleroactual = this->tablero->getCasillero( casillero->getCoordenada()->getCoordenada_x(), casillero->getCoordenada()->getCoordenada_y(), i);
			if ( casillero->getTipoTerreno() == TipoTerrenoCasillero::aire ) {
				if ( casilleroactual->getAvion() != NULL ) {
					if ( jugador == NULL ) {
						sValor = "A";
						break;
					}
					else if (casilleroactual->getAvion()->getJugador() == jugador->getIdJugador() ) {
						sValor = "A";
						break;
					}
					else {
						sValor = "N";
						break;
					}
				}
			}
		}
	}
	return sValor;
}