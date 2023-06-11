#include <iostream>
#include "Juego.h"

using namespace std;

int main(){
    Juego *juego = new Juego();
    juego->configurarPartida();
    cout<<"Hola mundo"<<endl;
    delete juego;
 return 0;
}
