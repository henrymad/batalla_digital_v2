#ifndef TABLERO3D_H
#define TABLERO3D_H

#include <iostream>

#include"Lista.h"
#include "Casillero.h"


class Tablero3D{
private:
    Lista<Lista<Lista<Casillero*>*>*> *tablero;
    int size_x, size_y, size_z;
    bool checkCoordenadas( int , int , int );
public:
    Tablero3D();
    Tablero3D( int, int, int );
    virtual ~Tablero3D();
    void setCasillero( Casillero *casillero, int, int, int );
    Casillero * getCasillero( int, int, int );
    int getSize_x();
    int getSize_y();
    int getSize_z();

};


#endif	//TABLERO3D_H

  