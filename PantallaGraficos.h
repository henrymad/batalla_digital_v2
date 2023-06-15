#ifndef PANTALLA_GRAFICO_H
#define PANTALLA_GRAFICO_H

#include<string>
#include "Jugador.h"

class PantallaGraficos {
public:
    PantallaGraficos();
    virtual ~PantallaGraficos();

    void imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2);
    void imprimirPantalla(std::string titulo,std::string opcion1,std::string opcion2, std::string opcion3);
    void imprimirEspaciosVertical(int cantidadDeEspacios);
    void imprimirTitulo(std::string titulo);
    void imprimirTituloCentrado(std::string titulo, int margenDerecha);

    void imprimirLineaHorizontal(int cantidadLineas);
    void imprimirItemsMenu();
    void imprimirPantalla();
    void imprimirMenuJugador(Jugador *jugador);

    std::string  entradaUsuarioTexto(std::string textoInput);
    int entradaUsuarioNumero(std::string textoInput);

};

#endif //PANTALLA_GRAFICO_H
