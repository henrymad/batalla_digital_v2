#ifndef _CASILLERO_H_
#define _CASILLERO_H_

#include <string>
#include "Lista.h"

#include "Coordenada.h"
#include "Soldado.h"
#include "Mina.h"
#include "PropiedadesDelJuego.h"
#include "Barco.h"
#include "Avion.h"

class Casillero {
private:
    Coordenada * coordenada;
    TipoTerrenoCasillero terreno;
    EstadoCasillero estado;
    int estadoInactivoCasillero;	// Lo imagino bool
    int turnosDeInactividad;		// valor >= 0 y cambia con cada turno
    Soldado * soldado;
    Mina *mina;
    Lista< Mina *> * minas;
    Barco * barco;
    Avion * avion;
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
    void setSoldado( Soldado * );
    void setBarco( Barco * );
    void setAvion( Avion * );
    void agregarMina( Mina * );

    void setMina(Mina * mina);
    Mina *getMina();
    TipoTerrenoCasillero getTipoTerreno();
    EstadoCasillero getEstadoCasillero();
    int getTurnosDeInactividad();
    Soldado * getSoldado();
    Lista<Mina *> * getListaMinas();
    Mina * getMina( int );
    Barco * getBarco();
    Avion * getAvion();
};

#endif  // _CASILLERO_H_

