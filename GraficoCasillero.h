#include <new>
#include <iostream>

#include "Casillero.h"

class GraficoCasillero {
public:
	GraficoCasillero();
	GraficoCasillero( Casillero * );
	GraficoCasillero( TipoTerrenoCasillero );
	GraficoCasillero( TipoTerrenoCasillero, EstadoCasillero );
	~GraficoCasillero( );
	// Setters
	void setSoldado( Soldado * );
	void setMina( Mina * );
	void setBombaQuimica( BombaQuimica * );
	void setAvion( Avion * );
	void setBarco( Barco * );
	char ** getMiniTablero();
private:
	char ** miniTablero = NULL;
	int sizeFilas = 3, sizeColumnas = 3;
};

