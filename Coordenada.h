#ifndef _COORDENADA_H_INCLUDED_
#define _COORDENADA_H_INCLUDED_

//#include "Tablero3D.h"	/* Necesitaría tablero para validar rangos de las coordenadas */

/* Faltaria definir si la traslación de 0-size-1 a 1-size lo hacemos acá o en otra parte */

class Coordenada
{
private:
	int coordenada_x = 0;
	int coordenada_y = 0;
	int coordenada_z = 0;

public:
	Coordenada();
	Coordenada( int, int, int );
	Coordenada( Coordenada const & );
	~Coordenada();
	Coordenada const & operator=( Coordenada const& );
	void setCoordenada_x( int );
	void setCoordenada_y( int );
	void setCoordenada_z( int );
	int getCoordenada_x();
	int getCoordenada_y();
	int getCoordenada_z();
};

#endif

