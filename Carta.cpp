//
// Created by lenovo on 16/06/23.
//
#include "Carta.h"

void Carta::setIdJugador(int idJugador) {
    this->idJugador = idJugador;
}

void Carta::setNombre(std::string nombre) {
    this->nombre = nombre;
}

int Carta::getIdJugador(int idJugador) {
    return this->idJugador;
}

std::string Carta::getNombre() {
    return this->nombre;
}

Carta::Carta() {
    this->idJugador = 0;
    this->nombre = "";
}

