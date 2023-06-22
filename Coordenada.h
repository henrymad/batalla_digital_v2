#ifndef _COORDENADA_H_INCLUDED_
#define _COORDENADA_H_INCLUDED_

// #include "Tablero3D.h"	/* Necesitaría tablero para validar rangos de las coordenadas */

/* Faltaria definir si la traslación de 0-size-1 a 1-size lo hacemos acá o en otra parte */
#include <iostream>

using namespace std;

class Coordenada
{
private:
	int coordenada_x;
	int coordenada_y;
	int coordenada_z;

public:
	Coordenada();
	Coordenada( int, int, int );
	Coordenada( Coordenada const & );
	~Coordenada();
	Coordenada const & operator=( Coordenada const & );
	void setCoordenada_x( int );
	void setCoordenada_y( int );
	void setCoordenada_z( int );
	int getCoordenada_x();
	int getCoordenada_y();
	int getCoordenada_z();
};

#endif

