#ifndef PANTALLA_GRAFICO_H
#define PANTALLA_GRAFICO_H

#include<string>

class InterfacePantalla {
private:
    std::string titulo;
    std::string opcion1;
    std::string opcion2;

public:
    InterfacePantalla();
    virtual ~InterfacePantalla();

    void imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2);
    void imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2, std::string opcion3);
    void imprimirEspaciosVertical(int cantidadDeEspacios);
    void imprimirTitulo();
    void imprimirLineaHorizontal(int cantidadLineas);
    void imprimirItemsMenu();
    void imprimirPantalla();

    std::string  entradaUsuarioTexto(std::string textoInput);
    int entradaUsuarioNumero(std::string textoInput);

};

#endif //PANTALLA_GRAFICO_H
