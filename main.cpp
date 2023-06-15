#include <iostream>
#include "Juego.h"

using namespace std;

int main(){
    Juego *juego;
    juego = new Juego();
    juego->configurarPartida();
    juego->empezarPartida();
    delete juego;
 return 0;
}
