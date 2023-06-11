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

