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
    this->soldadoInfanteria->setCoordenada(  this->getCoordenada() );
}

void Casillero::setBarco( Barco * nave ) {
    this->barcoGuerra = nave;
    this->estado = barco;
    this->barcoGuerra->setCoordenada( this->getCoordenada() );
}

void Casillero::setAvion( Avion * aeronave ) {
    this->aeronave = aeronave;
    this->estado = avion;
    this->aeronave->setCoordenada( this->getCoordenada() );
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
    this->minacomun->setCoordenada( this->getCoordenada() );
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
    return this->soldadoInfanteria;
}

Barco * Casillero::getBarco() {
    return this->barcoGuerra;
}

Avion *  Casillero::getAvion() {
    return this->aeronave;
}


Mina * Casillero::getMina() {
    return this->minacomun;
}

BombaQuimica * Casillero::getBomba() {
    return this->bomba;
}

int Casillero::getTurnosDeInactividad() {
    return this->turnosDeInactividad;
}
