#ifndef _CASILLERO_
#define _CASILLERO_

#include <string>
#include "Lista.h"

#include "Coordenada.h"
#include "Soldado.h"
#include "Mina.h"
#include "Jugador.h"
#include "PropiedadesDelJuego.h"

class Casillero {
private:
	Coordenada coordenada;
    TipoTerrenoCelda terreno;
    EstadoCelda estadoCelda;

    // opcionales
    std::string estado;
    std::string tipoTerreno;

	int estadoInactivoCasillero;	// Lo imagino bool
	int turnosDeInactividad;		// valor >= 0 y cambia con cada turno
	/* Ac� ir�an los posibles elementos que puede contener un casillero
	*    Avi�n, Barco, Mina, Soldado, ...
	*/
	Soldado * soldado;
	Lista< Mina *> * minas;
public:
	Casillero();
	//Casillero( Coordenada );
	Casillero( Coordenada, TipoTerrenoCelda );
	virtual ~Casillero();
	Coordenada getCoordenada();
    TipoTerrenoCelda getTipoTerreno();
	void setCoordenada( Coordenada );
	void setTipoTerreno( TipoTerrenoCelda );
    void setEstadoCelda(EstadoCelda estadoCelda);
    EstadoCelda getEstadoCelda();

    void setEstado(std::string estado);
    std::string getEstado();

    void setTerreno(std::string tipoTerreno);
    std::string getTerreno();

	void setSoldado( Soldado * );
	void agregarMina( Mina * );
	Soldado * getSoldado();
	Lista<Mina *> * getListaMinas();
	Mina * getMina( int );
};

#endif  // _CASILLERO_

