#include <new>
#include <iostream>

#include "Tablero3D.h"

class GraficoCasillero {
public:
	GraficoCasillero();
	GraficoCasillero( Tablero3D *, Casillero * );
	GraficoCasillero( TipoTerrenoCasillero );
	GraficoCasillero( TipoTerrenoCasillero, EstadoCasillero );
	~GraficoCasillero( );
	// Setters
	void setSoldado( Tablero3D * );
	void setSoldado( Soldado * );
	void setMina( Mina * );
	void setBombaQuimica( BombaQuimica * );
	void setAvion( Avion * );
	void setBarco( Barco * );
	char ** getMiniTablero();
private:
	Tablero3D * tablero;
	char ** miniTablero = NULL;
	int sizeFilas = 3, sizeColumnas = 3;
};

