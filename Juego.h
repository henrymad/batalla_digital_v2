#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Tablero3D.h"

class Juego{
private:
    int cantidadDeSoldados;
    int cantidadDeJugadores;
    int nivelPartida;
    Lista<Jugador*> *jugadores;
    Tablero3D *tablero;

    void configurarJugadores(Lista<Jugador*> *jugadores, int cantidadDeJugadores, int cantidadDeSoldados);
    void configurarTablero(Lista<Jugador*> *jugadores, int nivelPartida);
public:
    Juego();
    void configurarPartida();
    void empezarPartida();

};

#endif JUEGO_H
