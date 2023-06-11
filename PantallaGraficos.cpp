#include "PantallaGraficos.h"
#include <iostream>
using namespace std;

void InterfacePantalla::imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2){
    cout<<titulo<<endl;
    this->imprimirLineaHorizontal(40);
    cout<<">> "<<opcion1<<endl;
    cout<<">> "<<opcion2<<endl;
}

void InterfacePantalla::imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2, std::string opcion3){
    cout<<titulo<<endl;
    this->imprimirLineaHorizontal(40);
    cout<<">> "<<opcion1<<endl;
    cout<<">> "<<opcion2<<endl;
    cout<<">> "<<opcion3<<endl;
}

void InterfacePantalla::imprimirTitulo() {
    cout<<this->titulo<<endl;
}

void InterfacePantalla::imprimirLineaHorizontal(int cantidadaLineas) {
    for(int i=0;i<cantidadaLineas;i++){
        cout<<"-";
    }
    cout<<""<<endl;
}

void InterfacePantalla::imprimirEspaciosVertical(int cantidadDeEspacios) {
    for(int i=0;i<cantidadDeEspacios;i++){
        cout<<" "<<endl;
    }
}



std::string InterfacePantalla::entradaUsuarioTexto(std::string textoInput){
    std::string  input;
    cout<<textoInput;
    cin>>input;
    return input;
}

void InterfacePantalla::imprimirItemsMenu() {
    cout<<">> "<<"Historial (H)"<<endl;
}

InterfacePantalla::InterfacePantalla() {

}

InterfacePantalla::~InterfacePantalla() {

}

int InterfacePantalla::entradaUsuarioNumero(std::string textoInput) {
    int  input;
    cout<<textoInput;
    cin>>input;
    return input;
}


