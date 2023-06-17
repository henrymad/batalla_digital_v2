#ifndef _CASILLERO_H_INCLUDED_
#define _CASILLERO_H_INCLUDED_

#include <string>
#include "lista.h"

#include "Definiciones.h"
#include "Coordenada.h"
#include "BombaQuimica.h"
//#include "Soldado.h"
//#include "Mina.h"

//#include "Jugador.h"
//#include "Barco.h"
//#include "Avion.h"

class Casillero {
private:
	Coordenada * coordenada;
	TipoTerrenoCasillero terreno;
	EstadoCasillero estado;
	int estadoInactivoCasillero = 0;	// Lo imagino bool
	int turnosDeInactividad = 0;		// valor >= 0 y cambia con cada turno
	//Soldado * soldado;
	//Lista< Mina *> * minas;
	//Barco * barco;
	//Avion * avion;
	// BombaQuimica * bomba;				// Se marca el casillero donde deton�.
public:
	Casillero();
	Casillero( Coordenada * );
	Casillero( int, int, int );
	Casillero( Coordenada *, TipoTerrenoCasillero );
	Casillero( Coordenada *, TipoTerrenoCasillero, EstadoCasillero );
	virtual ~Casillero();
	Coordenada * getCoordenada();
	void setCoordenada( Coordenada * );
	void setTipoTerreno( TipoTerrenoCasillero );
	void setEstadoCasillero( EstadoCasillero );
	void setTurnosDeInactividad( int );
	//void setSoldado( Soldado * );
	//void setBarco( Barco * );
	//void setAvion( Avion * );
	// void setBomba( BombaQuimica * );
	//void agregarMina( Mina * );
	TipoTerrenoCasillero getTipoTerreno();
	EstadoCasillero getEstadoCasillero();
	int getTurnosDeInactividad();
	//Soldado * getSoldado();
	//Lista<Mina *> * getListaMinas();
	//Mina * getMina( int );
	//Barco * getBarco();
	//Avion * getAvion();
	// BombaQuimica * getBomba();
};

#endif  // _CASILLERO_INCLUDED_

