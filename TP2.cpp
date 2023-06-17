// TP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include "Tablero3D.h"

#include "MostrarCasillero.h"
#include "MostrarTablero.h"
#include "Mapas.h"

using namespace std;

int main()
{
    Jugador * equipo1;
    equipo1 = new Jugador( "Equipo1" );
    std::cout << "Test de subcomponentes \n" << "Equipo: " << equipo1->getNombreJugador() << "(" << equipo1->getIdJugador() << ")" << "\n";

    Coordenada * coordenada;
    coordenada = new Coordenada();
    Soldado * soldado;
    soldado = new Soldado( equipo1->getIdJugador() );
    Casillero * casillero1;
    Tablero3D * tablero;
    tablero = new Tablero3D;
    casillero1 = tablero->getCasillero( 1, 1, NIVEL_SUPERFICIE );
    casillero1->setTipoTerreno(TipoTerrenoCasillero::tierra);
    casillero1->setSoldado(soldado);

    // tablero->setCasillero(casillero1, 1, 1, NIVEL_SUPERFICIE);

    GraficoCasillero * graficocasillero;
    graficocasillero = new GraficoCasillero( tablero );
    graficocasillero->setCasillero( casillero1 );
    MostrarCasillero * mostrar;
    mostrar = new MostrarCasillero( graficocasillero );
    for (int i = 0; i < 3; i++ ) {
        cout << mostrar->emitir(i) << "\n";
    }

    Mapas * mapa;
    mapa = new Mapas( tablero );
    mapa->cargarMapaDefault();
    mapa->imprimirMapa("prueba1.txt", NULL );

    MostrarTablero * salidaTablero;
    salidaTablero = new MostrarTablero( tablero, equipo1 );
    salidaTablero->imprimir( "prueba2.txt" );

    delete soldado;                                                                                                             
    delete coordenada;
    delete equipo1;

    delete graficocasillero;
    delete casillero1;
    delete salidaTablero;
    delete tablero;

}