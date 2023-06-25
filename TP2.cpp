// TP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include "Tablero3D.h"

#include "MostrarCasillero.h"
#include "MostrarTablero.h"
#include "Mapas.h"
#include "Graficas.h"

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

    Mapas* mapa;
    mapa = new Mapas(tablero);
    // mapa->cargarMapaDefault();                  // Esta funcion carga el Mapa en 3D.
    // mapa->cargarMapa2D( "mapadefault.txt" );    // Sólo carga la superficie.
    mapa->cargarMapa3D("mapadefault.txt", false);
    mapa->imprimirMapa("prueba1.txt", NULL);
    //mapa->grabarMapa2D( "mapadefault.txt" );
    // mapa->cargarMapa2D( "mapadefault.txt" );
    //mapa->grabarMapa2D( "mapadefault.txt" );

    casillero1 = tablero->getCasillero( 10, 10, NIVEL_SUPERFICIE );
    // casillero1->setTipoTerreno( tierra );
    casillero1->setSoldado( soldado );
    Mina * mina1, * mina2, * mina3;
    mina1 = new Mina( equipo1->getIdJugador() );
    mina2 = new Mina( equipo1->getIdJugador() );
    mina3 = new Mina( equipo1->getIdJugador() );
    casillero1 = tablero->getCasillero( 20, 50, NIVEL_SUPERFICIE );
    casillero1->setMina( mina1 );
    casillero1 = tablero->getCasillero( 20, 60, NIVEL_SUPERFICIE );
    casillero1->setMina( mina2 );
    casillero1 = tablero->getCasillero( 20, 70, NIVEL_SUPERFICIE );
    casillero1->setMina( mina3 );
    Barco * barco;
    barco = new Barco( equipo1->getIdJugador() );
    casillero1 = tablero->getCasillero( 85, 180, NIVEL_SUPERFICIE );
    casillero1->setBarco( barco );
    Avion * avion1, * avion2;
    avion1 = new Avion( equipo1->getIdJugador() );
    avion2 = new Avion( equipo1->getIdJugador() );
    casillero1 = tablero->getCasillero( 125, 90, NIVEL_SUPERFICIE + 10 );
    casillero1->setAvion( avion1 );
    casillero1 = tablero->getCasillero( 80, 160, NIVEL_SUPERFICIE + 8 );
    casillero1->setAvion( avion2 );


    // tablero->setCasillero(casillero1, 1, 1, NIVEL_SUPERFICIE);

    GraficoCasillero * graficocasillero;
    graficocasillero = new GraficoCasillero( tablero );
    graficocasillero->setCasillero( casillero1 );
    MostrarCasillero * mostrar;
    mostrar = new MostrarCasillero( graficocasillero );
    for (int i = 0; i < 3; i++ ) {
        cout << mostrar->emitir(i) << "\n";
    }

    MostrarTablero * salidaTablero;
    salidaTablero = new MostrarTablero( tablero, equipo1 );
    salidaTablero->imprimir( "prueba2.txt" );
    Graficas * bmpMapa;
    bmpMapa = new Graficas( tablero );
    bmpMapa->graficarSuperficie( "grafico.bmp", equipo1 );
    //bmpMapa->graficarSuperficie( "grafico.bmp" );

    delete bmpMapa;
    delete soldado;
    delete mina1;
    delete mina2;
    delete mina3;
    delete barco;
    delete avion1;
    delete avion2;
    delete coordenada;
    delete equipo1;

    delete graficocasillero;
    delete casillero1;
    delete salidaTablero;
    delete tablero;

}
