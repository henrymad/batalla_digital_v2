//
// Created by lenovo on 16/06/23.
//

#ifndef _CARTA_H
#define _CARTA_H

#include <string>

class Carta{
private:
    int idJugador;
    std::string nombre;

public:
    Carta();
    void setIdJugador(int idJugador);
    void setNombre(std::string nombre);

    int getIdJugador(int idJugador);
    std::string getNombre();
};

#endif //_CARTA_H
