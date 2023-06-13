#include "Casillero.h"

Casillero::Casillero() {
	this->terreno = TipoTerrenoCasillero::tierra;
	this->estado = EstadoCasillero::casillerovacio;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	this->coordenada = NULL;
	this->soldado = NULL;
	this->minas = NULL;
}

Casillero::Casillero( int x, int y, int z ) {
	this->terreno = TipoTerrenoCasillero::tierra;
	this->estado = EstadoCasillero::casillerovacio;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	this->coordenada = new Coordenada( x, y, z );
}

Casillero::Casillero( Coordenada * coordenada ) {
	this->terreno = TipoTerrenoCasillero::tierra;
	this->estado = EstadoCasillero::casillerovacio;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	// Lo puedo hacer porque sobrecargue el '='
	this->coordenada = coordenada;
	this->soldado = NULL;
	this->minas = NULL;
}

Casillero::Casillero( Coordenada * coordenada, TipoTerrenoCasillero terreno ) {
	this->coordenada = coordenada;
	this->terreno = terreno;
	this->estado = EstadoCasillero::casillerovacio;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	this->soldado = NULL;
	this->minas = NULL;
}

Casillero::Casillero( Coordenada * coordenada, TipoTerrenoCasillero terreno, EstadoCasillero estado ) {
	this->coordenada = coordenada;
	this->terreno = terreno;
	this->estado = EstadoCasillero::casillerovacio;
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	this->soldado = NULL;
	this->minas = NULL;
}

Casillero::~Casillero() {
	this->estadoInactivoCasillero = 0;
	this->turnosDeInactividad = 0;
	delete this->coordenada;
}

// Setters

void Casillero::setCoordenada( Coordenada * coordenada ) {
	// Lo puedo hacer porque sobrecargue el '='
	this->coordenada = coordenada;
}

void Casillero::setTipoTerreno( TipoTerrenoCasillero terreno ) {
	this->terreno = terreno;
}

void Casillero::setEstadoCasillero( EstadoCasillero estado ) {
	this->estado = estado;
}

void Casillero::setSoldado( Soldado * soldado) {
	this->soldado = soldado;
}

void Casillero::setBarco( Barco * barco ) {
	this->barco = barco;
}

void Casillero::setAvion( Avion * avion ) {
	this->avion = avion;
}

void Casillero::setTurnosDeInactividad( int turnos ) {
	if ( turnos >= 0 ) {
		this->turnosDeInactividad = turnos;
	}
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

// Getters

Coordenada* Casillero::getCoordenada() {
	return this->coordenada;
}

TipoTerrenoCasillero Casillero::getTipoTerreno() {
	return this->terreno;
}

EstadoCasillero Casillero::getEstadoCasillero() {
	return this->estado;
}

Soldado * Casillero::getSoldado() {
	return this->soldado;
}

Barco * Casillero::getBarco() {
	return this->barco;
}

Avion*  Casillero::getAvion() {
	return this->avion;
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

int Casillero::getTurnosDeInactividad() {
	return  this->turnosDeInactividad;
}