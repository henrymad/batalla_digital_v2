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
    cout<<"Cartas: "<<"Barco - Bomba quimica"<<endl;
    cout<<"Minas Activas: "<<jugador->getMinasActivas()->contarElementos()<<endl;
    cout<<"Cartas Activas: "<<"Avion"<<endl;
    cout<<" "<<endl;
    this->imprimirLineaHorizontal(20);
}

void PantallaGraficos::imprimirTituloCentrado(std::string titulo, int margenDerecha) {
    for(int i=0;i<margenDerecha;i++){
        cout<<" ";
    }
    cout<<titulo<<endl;
}


