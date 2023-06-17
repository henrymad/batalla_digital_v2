#ifndef GRAFICAS_H_INCLUDED_
#define GRAFICAS_H_INCLUDED_

#include "Tablero3D.h"
#include "Casillero.h"
#include "EasyBMP.h"

using namespace std;

class Graficas {
private:
	Tablero3D * partida;
	int iHeight;
	int iWidth;
	int iPixelSize;
	void dibujarPixel( int, int, Casillero* , BMP );
public:
	Graficas();
	Graficas( Tablero3D * oTablero);
	~Graficas();
	void graficarSuperficie( string );
};

#endif	// GRAFICAS_INCLUDED