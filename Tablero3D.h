#ifndef TABLERO2_H_
#define TABLERO2_H_

#include <iostream>

#include"Lista.h"
#include "Casillero.h"

using namespace std;

class Tablero3D
{
private:
	Lista <Lista <Lista < Casillero * > * > * > * tablero;
	int size_x, size_y, size_z;
	bool checkCoordenadas( int , int , int );
public:
	Tablero3D();
	Tablero3D( int, int, int );
	virtual ~Tablero3D();
	void setCasillero( Casillero *, int, int, int );
	Casillero * getCasillero( int, int, int );
	int getSize_x();
	int getSize_y();
	int getSize_z();

};

#endif	//TABLERO2_H_

  