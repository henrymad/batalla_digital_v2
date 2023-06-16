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
    Lista<string *> *cartas;
    Tablero3D *tablero;
    PantallaGraficos *pantallaGraficos;


    void configurarJugadores();
    void configurarTablero(int nivelPartida);
    void configurarCartas(int niverlJuego);
    Lista<Soldado*> *configurarSoldados(int cantidadDeSoldados,int idJugador);

public:
    Juego();
    void configurarPartida();
    void empezarPartida();

};

#endif //JUEGO_H
