#include "PantallaGraficos.h"
#include <iostream>
using namespace std;

void PantallaGraficos::imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2){
    cout<<titulo<<endl;
    this->imprimirLineaHorizontal(40);
    cout<<">> "<<opcion1<<endl;
    cout<<">> "<<opcion2<<endl;
}

void PantallaGraficos::imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2, std::string opcion3){
    cout<<titulo<<endl;
    this->imprimirLineaHorizontal(40);
    cout<<">> "<<opcion1<<endl;
    cout<<">> "<<opcion2<<endl;
    cout<<">> "<<opcion3<<endl;
}

void PantallaGraficos::imprimirTitulo(std::string titulo) {
    cout<<titulo<<endl;
}

void PantallaGraficos::imprimirLineaHorizontal(int cantidadaLineas) {
    for(int i=0;i<cantidadaLineas;i++){
        cout<<"-";
    }
    cout<<""<<endl;
}

void PantallaGraficos::imprimirEspaciosVertical(int cantidadDeEspacios) {
    for(int i=0;i<cantidadDeEspacios;i++){
        cout<<" "<<endl;
    }
}



std::string PantallaGraficos::entradaUsuarioTexto(std::string textoInput){
    std::string  input;
    cout<<textoInput;
    cin>>input;
    return input;
}

void PantallaGraficos::imprimirItemsMenu() {
    cout<<">> "<<"Historial (H)"<<endl;
}

PantallaGraficos::PantallaGraficos() {

}

PantallaGraficos::~PantallaGraficos() {

}

int PantallaGraficos::entradaUsuarioNumero(std::string textoInput) {
    int  input;
    cout<<textoInput;
    cin>>input;
    return input;
}

void PantallaGraficos::imprimirMenuJugador(Jugador *jugador) {
    this->imprimirLineaHorizontal(20);
    cout<<" "<<endl;
    cout<<"Menu Jugador"<<endl;
    cout<<"Nombre: "<<jugador->getNombreJugador()<<endl;
    cout<<"Cantidad de Soldados: "<<jugador->getCantidadSoldados()<<endl;
    jugador->getSoldados()->iniciarCursor();
    while(jugador->getSoldados()->avanzarCursor()){
        cout<<"id_soldado: "<<jugador->getSoldados()->obtenerCursor()->getIDSoldado()<<endl;
        cout<<"Coordenadas: "<<"("<<jugador->getSoldados()->obtenerCursor()->getCoordenada()->getCoordenadaX()
        <<","<<jugador->getSoldados()->obtenerCursor()->getCoordenada()->getCoordenadaY()<<","<<jugador->getSoldados()->obtenerCursor()->getCoordenada()->getCoordenadaZ()<<")"<<endl;
    }
    if(jugador->getListaCartas()->estaVacia()){
        cout<<"Cartas: "<<" "<<endl;
    }
    else{
        jugador->getListaCartas()->iniciarCursor();
        cout<<"Cartas: ";
        while(jugador->getListaCartas()->avanzarCursor()){
            cout<<jugador->getListaCartas()->obtenerCursor()->getNombre()<<",";
        }
        cout<<""<<endl;
    }

    cout<<"Minas Activas: "<<jugador->getMinasActivas()->contarElementos()<<endl;
    jugador->getMinasActivas()->iniciarCursor();
    while(jugador->getMinasActivas()->avanzarCursor()){
        cout<<"id_mina: "<<jugador->getMinasActivas()->obtenerCursor()->getIdMina()<<endl;
        cout<<"Coordenadas: "<<"("<<jugador->getMinasActivas()->obtenerCursor()->getCordenada()->getCoordenadaX()
            <<","<<jugador->getMinasActivas()->obtenerCursor()->getCordenada()->getCoordenadaY()<<","<<jugador->getMinasActivas()->obtenerCursor()->getCordenada()->getCoordenadaZ()<<")"<<endl;
    }
    cout<<" "<<endl;
    this->imprimirLineaHorizontal(20);
}

void PantallaGraficos::imprimirTituloCentrado(std::string titulo, int margenDerecha) {
    for(int i=0;i<margenDerecha;i++){
        cout<<" ";
    }
    cout<<titulo<<endl;
}

Coordenada *PantallaGraficos::entradaCoordenada() {
    Coordenada *nuevaCoordenada;
    nuevaCoordenada = new Coordenada();
    nuevaCoordenada->setCoordenadaX(this->entradaUsuarioNumero("Ingresar coordenda en X: "));
    nuevaCoordenada->setCoordenadaY(this->entradaUsuarioNumero("Ingresar coordenda en Y: "));
    nuevaCoordenada->setCoordenadaZ(this->entradaUsuarioNumero("Ingresar coordenda en Z: "));
    return nuevaCoordenada;
}


