#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Tablero3D.h"
#include "PantallaGraficos.h"
#include "Carta.h"
#include "Mapas.h"
#include "GraficoCasillero.h"
#include "MostrarCasillero.h"
#include "MostrarTablero.h"

class Juego{
private:
    int cantidadDeSoldados;
    int cantidadDeJugadores;
    int nivelPartida;

    Lista<Jugador*> *jugadores;
    Lista<Carta *> *cartas;
    Tablero3D *tablero;
    PantallaGraficos *pantallaGraficos;
    Mapas *mapa;

    GraficoCasillero * graficocasillero;
    MostrarCasillero * mostrar;
    MostrarTablero * salidaTablero;


    void configurarJugadores();
    void configurarTablero(int nivelPartida);
    void configurarCartas(int niverlJuego);
    Lista<Soldado*> *configurarSoldados(int cantidadDeSoldados,int idJugador);
    void eliminarJugador(Jugador *jugador, int posicion);
    Coordenada *coordenadaValida(Coordenada *nuevoCoordenada);
    Coordenada *coordenadaValidaCarta(Coordenada *nuevoCoordenada);

public:
    Juego();
    ~Juego();
    void configurarPartida();
    void empezarPartida();

};

#endif //JUEGO_H
