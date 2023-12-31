#include "Casillero.h"

Casillero::Casillero() {
	this->terreno = TipoTerrenoCasillero::tierra;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	this->soldado = nullptr;
	this->minas = nullptr;
}

Casillero::Casillero( Coordenada coordenada ) {
	this->terreno = TipoTerrenoCasillero::tierra;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	// Lo puedo hacer porque sobrecargue el '='
	this->coordenada = coordenada;
	this->soldado = nullptr;
	this->minas = nullptr;
}

Casillero::Casillero( Coordenada coordenada, TipoTerrenoCasillero terreno ) {
	this->coordenada = coordenada;
	this->terreno = terreno;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	this->soldado = nullptr;
	this->minas = nullptr;
}

Casillero::~Casillero() {
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
}

// Getters

Coordenada Casillero::getCoordenada() {
	return this->coordenada;
}

TipoTerrenoCasillero Casillero::getTipoTerreno() {
	return this->terreno;
}

// Setters

void Casillero::setCoordenada( Coordenada coordenada ) {
	// Lo puedo hacer porque sobrecargue el '='
	this->coordenada = coordenada;
}

void Casillero::setTipoTerreno( TipoTerrenoCasillero terreno ) {
	this->terreno = terreno;
}

void Casillero::setSoldado( Soldado * soldado) {
	this->soldado = soldado;
}

void Casillero::agregarMina( Mina * mina ) {
	if ( mina != nullptr ) {
		if ( mina->getJugador() > 0 ) {
			bool encontrado = false;
			Lista< Mina * > * listaminas = this->minas;
			listaminas->iniciarCursor();
			while ( listaminas->avanzarCursor() ) {
				Mina * aux = listaminas->obtenerCursor();
				if ( mina->getJugador() == aux->getJugador() ) {
					encontrado = true;
					break;
				}
			}
			if ( encontrado ) {
				listaminas->agregar( mina );
			}
		}
	}
}

Soldado * Casillero::getSoldado() {
	return this->soldado;
}

Lista< Mina * > * Casillero::getListaMinas() {
	return this->minas;
}

Mina * Casillero::getMina( int jugador ) {
	Mina * mina = nullptr;
	bool encontrado = false;
	Lista< Mina * > * listaminas = this->minas;
	listaminas->iniciarCursor();
	while (listaminas->avanzarCursor()) {
		Mina* aux = listaminas->obtenerCursor();
		if ( aux->getJugador() == jugador ) {
			mina = aux;
			break;
		}
	}
	return mina;
}