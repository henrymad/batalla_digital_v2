#include "Mapas.h"

Mapas::Mapas( Tablero3D * tablero ) {
	this->tablero = tablero;
	this->jugador = NULL;
	this->nombreArchivo = "";
}

//  Setters

void Mapas::cargarMapaDefault() {
	Casillero * casillero;
	if ( this->tablero != NULL ) {
		int size_x = this->tablero->getSize_x();
		int size_y = this->tablero->getSize_y();
		int size_z = this->tablero->getSize_z();
		for ( int i = 1; i <= size_x; i++ ) {
			for ( int j = 1; j <= size_y; j++ ) {
				for (int k = 1; k <= size_z; k++ ) {
					casillero = tablero->getCasillero( i, j, k );
					if ( k > NIVEL_SUPERFICIE ) {
						casillero->setTipoTerreno( aire );
					}
					else {
						casillero->setTipoTerreno( tierra );
						if ( i > 160 && j < 150 ) {
							casillero->setTipoTerreno( agua );
						}
						else if (  ( j > 70 && j < 140 ) && ( i >  110 && i <= 160 ) ) {
							casillero->setTipoTerreno( agua );
						}
						else if ( ( j > 100 && j < 120 ) && ( i > 80  && i <= 110 ) ) {
							casillero->setTipoTerreno( agua );
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
	if ( this->tablero == NULL ) {
		return;
	}
	ifstream entrada( archivo.c_str() );
	if ( entrada.is_open() ) {
		string linea;
		int size_x = this->tablero->getSize_x();
		int size_y = this->tablero->getSize_y();
		for ( int j = 1; j <= size_y; j++ ) {
			if ( ! std::getline(entrada, linea) ) {
				break;
			}
			if ( linea.length() == ( long unsigned int) size_y ) {
				for ( int i = 1; i <= size_x; i++ ) {
					Casillero * casillero = this->tablero->getCasillero(i, j, NIVEL_SUPERFICIE);
					char caracter = linea[ i - 1 ];
					if ( caracter == '0' ) {
						casillero->setTipoTerreno( tierra );
					}
					else if ( caracter == '1' ) {
						casillero->setTipoTerreno( agua );
					}
				}
			}
		}
	}
}

void Mapas::cargarMapa3D( string archivo, bool superficie = true ) {
	if (archivo == "") {
		return;
	}
	if (this->tablero == NULL) {
		return;
	}
	ifstream entrada(archivo.c_str());
	if ( entrada.is_open() ) {
		string linea;
		int size_x = this->tablero->getSize_x();
		int size_y = this->tablero->getSize_y();
		int size_z = this->tablero->getSize_z();
		for ( int i = 1; i <= size_x; i++ ) {
			if ( ! std::getline( entrada, linea ) ) {
				break;
			}
			if ( linea.length() == (long unsigned int) size_y ) {
				for ( int j = 1; j <= size_y; j++ ) {
					char caracter = linea[ j - 1 ];
					for ( int k = 1; k <= size_z; k++ ) {
						Casillero * casillero = this->tablero->getCasillero( i, j, k );
						if ( k <= NIVEL_SUPERFICIE ) {
							if ( caracter == '0' ) {
								casillero->setTipoTerreno( tierra );
							}
							else if ( caracter == '1' ) {
								casillero->setTipoTerreno( agua );
							}
						}
						else {
							casillero->setTipoTerreno( aire );
						}
						casillero->setEstadoCasillero( casillerovacio );
					}
				}
			}
		}
		/*
		for ( int j = 1; j <= size_y; j++ ) {
			if ( !std::getline( entrada, linea ) ) {
				break;
			}
			if ( linea.length() == (long unsigned int) size_y ) {
				for ( int i = 1; i <= size_x; i++ ) {
					char caracter = linea[ i - 1 ];
					for ( int k = 1; k <= size_z; k++ ) {
						Casillero * casillero = this->tablero->getCasillero( i, j, k );
						if (  i == 85 && j == 180 ) {
							Casillero* casillero = this->tablero->getCasillero( i, j, k );
						}
						else if ( i == 180 && j == 85 ) {
							Casillero * casillero = this->tablero->getCasillero( i, j, k );
						}
						if ( k <= NIVEL_SUPERFICIE ) {
							if ( caracter == '0' ) {
								casillero->setTipoTerreno( tierra );
							}
							else if ( caracter == '1' ) {
								casillero->setTipoTerreno( agua );
							}
						}
						else {
							casillero->setTipoTerreno( aire );
						}
					}
				}
			}
		}
		*/
	}
}

void Mapas::grabarMapa2D( string archivo ) {
	if (archivo == "") {
		return;
	}
	ofstream salida;
	salida.open( archivo.c_str(), fstream::out );
	for (int i = 1; i <= this->tablero->getSize_x(); i++) {
		for (int j = 1; j <= this->tablero->getSize_y(); j++) {
			TipoTerrenoCasillero terreno = tablero->getCasillero( i, j, NIVEL_SUPERFICIE )->getTipoTerreno();
			salida << terreno;
		}
		salida << std::endl;
	}
	// Liberar recursos y memoria
	salida.close();
}

void Mapas::grabarMapa3D( string archivo ) {
	if (archivo == "") {
		return;
	}
	ofstream salida;
	salida.open(archivo.c_str(), fstream::out);
	for ( int z = 1; z < this->tablero->getSize_z(); z++ ) {
		for (int i = 1; i <= this->tablero->getSize_x(); i++) {
			for (int j = 1; j <= this->tablero->getSize_y(); j++) {
				TipoTerrenoCasillero terreno = tablero->getCasillero( i, j, z )->getTipoTerreno();
				salida << terreno;
			}
			salida << std::endl;
		}
		salida << std::endl;
	}
	// Liberar recursos y memoria
	salida.close();
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

void Mapas::imprimirGraficoSuperficie( string archivo ) {
	if (archivo == "") {
		archivo = "GraficoSuperfice.bmp";
	}
	Graficas * grafico;
	grafico = new Graficas( this->tablero );
	grafico->graficarSuperficie( archivo );
	// Liberar recursos
	delete grafico;
}


void Mapas::imprimirGraficoSuperficie( string archivo, Jugador * jugador ) {
	if ( archivo == "" ) {
		archivo = "GraficoSuperfice.bmp";
	}
	if ( jugador == NULL ) {
		return;
	}
	Graficas * grafico;
	grafico = new Graficas(this->tablero);
	grafico->graficarSuperficie( archivo, jugador );
	// Liberar recursos
	delete grafico;
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
	if ( casillero->getEstadoCasillero() == casilleroinactivo ) {
		/*
		if ( casillero->getBomba() != NULL ) {
			celda = "B";
		}
		else {
			celda = "X";
		}
		*/
	}
	else if ( casillero->getEstadoCasillero() == casillerovacio ) {

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
	else if ( casillero->getMina() != NULL ) {
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
			if ( casillero->getTipoTerreno() == aire ) {
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

void Mapas::verMapa() {
	// ToDo
}