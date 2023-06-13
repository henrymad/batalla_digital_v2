#ifndef _CASILLERO_INCLUDED_
#define _CASILLERO_INCLUDED_

#include <string>
#include "lista.h"

#include "Definiciones.h"
#include "Coordenada.h"
#include "Soldado.h"
#include "Mina.h"
#include "Jugador.h"
#include "Avion.h"
#include "Barco.h"
#include "BombaQuimica.h"

class Casillero {
private:
	Coordenada * coordenada;
	TipoTerrenoCasillero terreno;
	EstadoCasillero estado;
	int estadoInactivoCasillero = 0;	// Lo imagino bool
	int turnosDeInactividad = 0;		// valor >= 0 y cambia con cada turno
	Soldado * soldado;
	Lista< Mina *> * minas;
public:
	Casillero();
	Casillero( Coordenada * );
	Casillero( Coordenada *, TipoTerrenoCasillero );
	Casillero( Coordenada *, TipoTerrenoCasillero, EstadoCasillero );
	virtual ~Casillero();
	Coordenada * getCoordenada();
	void setCoordenada( Coordenada * );
	void setTipoTerreno( TipoTerrenoCasillero );
	void setEstadoCasillero( EstadoCasillero );
	void setTurnosDeInactividad( int );
	void setSoldado( Soldado * );
	void agregarMina( Mina * );
	TipoTerrenoCasillero getTipoTerreno();
	EstadoCasillero getEstadoCasillero();
	int getTurnosDeInactividad();
	Soldado * getSoldado();
	Lista<Mina *> * getListaMinas();
	Mina * getMina( int );
};

#endif  // _CASILLERO_INCLUDED_

