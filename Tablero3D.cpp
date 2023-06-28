
#include "Tablero3D.h"
#include "PropiedadesDelJuego.h"

Tablero3D::Tablero3D() {
    this->tablero = NULL;
    this->size_x = FILAS_TABLERO;
    this->size_y = COLUMNAS_TABLERO;
    this->size_z = ALTURA_TABLERO;
    this->tablero = new Lista < Lista < Lista < Casillero * > * > * >;
    this->casillerosInactivos = new Lista<Casillero*>();

    for (int x = 0; x < this->size_x; x++) {
        Lista < Lista < Casillero * > * > * elemento;
        elemento = new Lista < Lista < Casillero * > * >;
        for (int y = 0; y < this->size_y; y++) {
            Lista < Casillero * > * subelemento;
            subelemento = new Lista < Casillero * >;
            for (int z = 0; z < this->size_z; z++) {
                Casillero * casillero;
                casillero = new Casillero(x, y, z);
                subelemento->agregar( casillero);
            }
            elemento->agregar(subelemento);
        }
        this->tablero->agregar(elemento);
    }
}

Tablero3D::Tablero3D( int size_x, int size_y, int size_z) {
    this->tablero = NULL;
    this->size_x = size_x;
    this->size_y = size_y;
    this->size_z = size_z;
    this->tablero = new Lista < Lista < Lista < Casillero* > * > * >;

    for ( int x = 0; x < this->size_x; x++ ) {
        Lista < Lista < Casillero * > * > * elemento;
        elemento = new Lista < Lista < Casillero * > * >;
        for ( int y = 0; y < this->size_y; y++ ) {
            Lista < Casillero * > * subelemento;
            subelemento = new Lista < Casillero * >;
            for ( int z = 0; z < this->size_z; z++ ) {
                Casillero * casillero;
                casillero = new Casillero( x, y, z);
                subelemento->agregarFinal( casillero );
            }
            elemento->agregarFinal( subelemento );
        }
        this->tablero->agregarFinal( elemento );
    }
}

Tablero3D::~Tablero3D() {
    for ( int x = 0; x < this->size_x; x++ ) {
        Lista < Lista < Casillero * > * > * elemento;
        elemento = this->tablero->obtenerDato( x );
        for ( int y = 0; y < this->size_y; y++ ) {
            Lista < Casillero* > * subelemento;
            subelemento = elemento->obtenerDato(y);
            subelemento->borrarLista();
        }
        elemento->borrarLista();
    }
    this->size_x = 0;
    this->size_y = 0;
    this->size_z = 0;
    this->tablero = NULL;
}

void Tablero3D::setCasillero( Casillero * casillero, int x, int y, int z ) {
    if ( ! this->checkCoordenadas(x, y, z)) {
        return;
    }
    Lista < Lista < Casillero * > * > * elemento;
    Lista < Casillero * > * subelemento;

    // Traslaci�n de coordenadas
    x--; y--; z--;
    casillero->getCoordenada()->setCoordenadaX( x );
    casillero->getCoordenada()->setCoordenadaY( y );
    casillero->getCoordenada()->setCoordenadaZ( z );
    elemento = this->tablero->obtenerDato( x );
    subelemento = elemento->obtenerDato( y );
    subelemento->asignar( casillero, z );
}

Casillero * Tablero3D::getCasillero( int x, int y, int z ) {
    if ( ! this->checkCoordenadas( x, y, z ) ) {
        return NULL;
    }
    Lista < Lista < Casillero * > * > * elemento;
    Lista < Casillero * > * subelemento;
    // Traslaci�n de coordenadas
    x--; y--; z--;
    elemento = this->tablero->obtenerDato( x );
    subelemento = elemento->obtenerDato( y );
    Casillero * casillero;
    casillero = subelemento->obtenerDato( z );
    return casillero;
}

int Tablero3D::getSize_x() {
    return this->size_x;
}

int Tablero3D::getSize_y() {
    return this->size_y;
}

int Tablero3D::getSize_z() {
    return this->size_z;
}

bool Tablero3D::checkCoordenadas( int x, int y, int z ) {
    if ( x < 0 || x > this->size_x - 1 ) {
        return false;
    }
    if ( y < 0 || y > this->size_y - 1) {
        return false;
    }
    if ( z < 0 || z > this->size_z - 1) {
        return false;
    }
    return true;
}

Casillero *Tablero3D::buscarCasilleroPorCoordenada(int x, int y, int z) {
    this->tablero->iniciarCursor();
    while(this->tablero->avanzarCursor()){
        Lista < Lista < Casillero * > * > * elemento = this->tablero->obtenerCursor();
        elemento->iniciarCursor();
        while (elemento->avanzarCursor()){
            Lista < Casillero * > * subelemento = elemento->obtenerCursor();
            subelemento->iniciarCursor();
            while(subelemento->avanzarCursor()){
                Casillero *casillero = subelemento->obtenerCursor();
                if(casillero->getCoordenada()->getCoordenadaX() == x && casillero->getCoordenada()->getCoordenadaY() == y && casillero->getCoordenada()->getCoordenadaZ() == z ){
                    return casillero;
                }
            }
        }
    }
    return NULL;
}

void Tablero3D::guardarCasilleroPorCoordenada(Casillero *casillero, int x, int y, int z) {
    this->tablero->iniciarCursor();
    while(this->tablero->avanzarCursor()){
        Lista < Lista < Casillero * > * > * elemento = this->tablero->obtenerCursor();
        elemento->iniciarCursor();
        while (elemento->avanzarCursor()){
            Lista < Casillero * > * subelemento = elemento->obtenerCursor();
            subelemento->agregar(casillero, z);
        }
    }
}

void Tablero3D::guardarCasilleroInactivo(Casillero *casillero) {
    this->casillerosInactivos->agregarFinal(casillero);
}

void Tablero3D::actualizarEstadoCasillero() {
    if(!this->casillerosInactivos->estaVacia()){
        this->casillerosInactivos->iniciarCursor();
        int posicion = 1;
        while(this->casillerosInactivos->avanzarCursor()){
            Casillero * casillero = this->casillerosInactivos->obtenerCursor();
            if(casillero->getTurnosDeInactividad() == 0){
                casillero->setEstadoCasillero(casillerovacio);
                this->guardarCasilleroPorCoordenada(casillero, casillero->getCoordenada()->getCoordenadaX(),casillero->getCoordenada()->getCoordenadaY(),casillero->getCoordenada()->getCoordenadaZ());
                this->casillerosInactivos->remover(posicion);
                posicion++;
            }else{
                int turnos = casillero->getTurnosDeInactividad();
                turnos--;
                casillero->setTurnosDeInactividad(turnos);
                posicion++;
            }
        }
    }

}

