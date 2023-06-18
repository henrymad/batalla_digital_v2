#ifndef GRAFICAS_H_INCLUDED_
#define GRAFICAS_H_INCLUDED_

#include "Tablero3D.h"
#include "EasyBMP.h"

using namespace std;

class Graficas {
private:
	Tablero3D * tablero;
	int iHeight;
	int iWidth;
	int iPixelSize;
	void dibujarPixel( int, int, Casillero * , BMP );
public:
	Graficas();
	Graficas( Tablero3D * );
	~Graficas();
	void graficarSuperficie( string );
};

#endif	// GRAFICAS_INCLUDED