#ifndef _GRAFICAS_H_INCLUDED_
#define _GRAFICAS_H_INCLUDED_

#include "Tablero3D.h"
#include "Jugador.h"
#include "EasyBMP.h"
#include "ColorJugador.h"

using namespace std;

class Graficas {
private:
	Tablero3D * tablero;
	int iHeight;
	int iWidth;
	int iPixelSize;
	// void dibujarPixel( int, int, Casillero * ,  BMP & );
	void dibujarPixel( Casillero *, BMP & );
	//void dibujarPixel( int, int, Casillero *, Jugador *,  BMP & );
	void dibujarPixel( Casillero *, Jugador *, BMP & );
	void dibujarSoldado( Casillero *, Jugador *, BMP &, ColorJugador * );
	void dibujarMina( Casillero *, Jugador *, BMP &, ColorJugador * );
	void dibujarAvion( Casillero *, Jugador *, BMP &, ColorJugador * );
	void dibujarBarco( Casillero *, Jugador *, BMP &, ColorJugador * );
	Casillero* detectarAvion( Casillero *, Jugador * );
public:
	Graficas();
	Graficas( Tablero3D * );
	~Graficas();
	void graficarSuperficie( string );
	void graficarSuperficie( string, Jugador * );
};

#endif	// _GRAFICAS_INCLUDED