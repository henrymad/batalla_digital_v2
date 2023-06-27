#include "Casillero.h"

Casillero::Casillero() {
    this->terreno = tierra;
    this->estado = casillerovacio;
    this->estadoInactivoCasillero = 0;
    this->turnosDeInactividad = 0;
    this->coordenada = NULL;
    this->soldadoInfanteria = NULL;
    this->minacomun = NULL;
    this->aeronave = NULL;
    this->barcoGuerra = NULL;
    this->bomba = NULL;
}

Casillero::Casillero( int x, int y, int z ) {
    this->terreno = tierra;
    this->estado = casillerovacio;
    this->estadoInactivoCasillero = 0;
    this->turnosDeInactividad = 0;
    this->coordenada = new Coordenada( x, y, z );
    this->soldadoInfanteria = NULL;
    this->minacomun = NULL;
    this->aeronave = NULL;
    this->barcoGuerra = NULL;
    this->bomba = NULL;
}

Casillero::Casillero( Coordenada * coordenada ) {
    this->terreno = tierra;
    this->estado = casillerovacio;
    this->estadoInactivoCasillero = 0;
    this->turnosDeInactividad = 0;
    // Lo puedo hacer porque sobrecargue el '='
    this->coordenada = coordenada;
    this->soldadoInfanteria = NULL;
    this->minacomun = NULL;
    this->aeronave = NULL;
    this->barcoGuerra = NULL;
    this->bomba = NULL;
}

Casillero::Casillero( Coordenada * coordenada, TipoTerrenoCasillero terreno ) {
    this->coordenada = coordenada;
    this->terreno = terreno;
    this->estado = casillerovacio;
    this->estadoInactivoCasillero = 0;
    this->turnosDeInactividad = 0;
    this->soldadoInfanteria = NULL;
    this->minacomun = NULL;
    this->aeronave = NULL;
    this->barcoGuerra = NULL;
    this->bomba = NULL;
}

Casillero::Casillero( Coordenada * coordenada, TipoTerrenoCasillero terreno, EstadoCasillero estado ) {
    this->coordenada = coordenada;
    this->terreno = terreno;
    this->estado = casillerovacio;
    this->estadoInactivoCasillero = 0;
    this->turnosDeInactividad = 0;
    this->soldadoInfanteria = NULL;
    this->minacomun = NULL;
    this->barcoGuerra = NULL;
    this->aeronave = NULL;
    this->bomba = NULL;
}

Casillero::~Casillero() {
    this->estadoInactivoCasillero = 0;
    this->turnosDeInactividad = 0;
    delete this->coordenada;
    this->soldadoInfanteria = NULL;
    this->minacomun = NULL;
    this->aeronave = NULL;
    this->bomba = NULL;
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

void Casillero::setSoldado( Soldado * soldadoInfanteria) {
    this->soldadoInfanteria = soldadoInfanteria;
    this->estado = soldado;
}

void Casillero::setBarco( Barco * nave ) {
    this->barcoGuerra = nave;
    this->estado = barco;
}

void Casillero::setAvion( Avion * aeronave ) {
    this->aeronave = aeronave;
    this->estado = avion;
}

void Casillero::setBomba( BombaQuimica * bomba ) {
    this->bomba = bomba;
    this->estadoInactivoCasillero = TIEMPO_INHABILITADA_BOMBA;
    this->turnosDeInactividad = TIEMPO_INHABILITADA_BOMBA;
    this->estado = casilleroinactivo;
}

void Casillero::setTurnosDeInactividad( int turnos ) {
    if ( turnos >= 0 ) {
        this->turnosDeInactividad = turnos;
    }
}

void Casillero::setMina( Mina * minacomun ) {
    this->minacomun = minacomun;
    this->estadoInactivoCasillero = TIEMPO_INHABILITADA_MINA;
    this->turnosDeInactividad = TIEMPO_INHABILITADA_MINA;
    this->estado = mina;
}

/*
void Casillero::agregarMina( Mina * mina ) {
	if ( mina != NULL ) {
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
*/

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
    return this->soldadoInfanteria;
}

Barco * Casillero::getBarco() {
    return this->barcoGuerra;
}

Avion *  Casillero::getAvion() {
    return this->aeronave;
}

/*
Lista< Mina * > * Casillero::getListaMinas() {
	return this->minas;
}

Mina * Casillero::getMina( int jugador ) {
	Mina * mina = NULL;
	Lista< Mina * > * listaminas = this->minas;
	if ( this->minas != NULL ) {
		listaminas->iniciarCursor();
		while ( listaminas->avanzarCursor() ) {
			Mina* aux = listaminas->obtenerCursor();
			if ( aux->getJugador() == jugador ) {
				mina = aux;
				break;
			}
		}
	}
	return mina;
}
*/

Mina * Casillero::getMina() {
    return this->minacomun;
}

BombaQuimica * Casillero::getBomba() {
    return this->bomba;
}

int Casillero::getTurnosDeInactividad() {
    return this->turnosDeInactividad;
}
