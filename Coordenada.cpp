#include "Coordenada.h"

Coordenada::Coordenada() {

}

int Coordenada::getCoordenadaX() const{
    return this->coordenadaX;
}

void Coordenada::setCoordenadaX(int coordenadaX) {
    this->coordenadaX = coordenadaX;
}

int Coordenada::getCoordenadaY() const {
    return this->coordenadaY;
}

void Coordenada::setCoordenadaY(int coordenadaY) {
    this->coordenadaY = coordenadaY;
}

int Coordenada::getCoordenadaZ() const {
    return this->coordenadaZ;
}

void Coordenada::setCoordenadaZ(int coordenadaZ) {
    this->coordenadaZ = coordenadaZ;
}

Coordenada::Coordenada(int, int, int) {

}

Coordenada::Coordenada(const Coordenada & coordenada) {
    if ( this != &coordenada ) {
        this->coordenadaX = coordenada.coordenadaX;
        this->coordenadaY = coordenada.coordenadaY;
        this->coordenadaZ = coordenada.coordenadaZ;
    }

}

Coordenada::~Coordenada() {

}

