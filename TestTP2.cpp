// TestTP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Jugador.h"
#include "Casillero.h"
#include "Tablero3D.h"
#include "Definiciones.h"
#include "BombaQuimica.h"

int main()
{
    Jugador * equipo1;
    equipo1 = new Jugador("Equipo1");
    std::cout << "Test de subcomponentes \n" << "Equipo: " << equipo1->getNombreJugador() << "(" << equipo1->getIdJugador() << ")" << "\n";

    Casillero* casillero1;
    Tablero3D* tablero;
    tablero = new Tablero3D;
    casillero1 = tablero->getCasillero(1, 1, NIVEL_SUPERFICIE);
    casillero1->setTipoTerreno(TipoTerrenoCasillero::tierra);
    // tablero->setCasillero(casillero1, 1, 1, NIVEL_SUPERFICIE);
    BombaQuimica * bomba;
    bomba = new BombaQuimica( equipo1->getIdJugador() );

    delete bomba;
    delete tablero;
    delete casillero1;
    delete equipo1;

}
