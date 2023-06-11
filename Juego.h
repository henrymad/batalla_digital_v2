#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Tablero3D.h"
#include "PantallaGraficos.h"

class Juego{
private:
    int cantidadDeSoldados;
    int cantidadDeJugadores;
    int nivelPartida;

    Lista<Jugador*> *jugadores;
    Tablero3D *tablero;
    PantallaGraficos *pantallaGraficos;


    void configurarJugadores();
    void configurarTablero(Lista<Jugador*> *jugadores, int nivelPartida);
    Lista<Soldado*> *configurarSoldados(int cantidadDeSoldados,int idJugador);

public:
    Juego();
    void configurarPartida();
    void empezarPartida();

};

#endif //JUEGO_H
