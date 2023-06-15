#include "Tablero3D.h"
#include "Jugador.h"

class Mapas
{
	Mapas( Tablero3D * );
	void cargarMapaDefault();
	void leerMapa( string );
	void imprimirMapa( string );
	void imprimirGraficoSuperficie( string );
	void verMapa();
	void setJugador( Jugador * );
private:
	Tablero3D * tablero;
	Jugador * jugador;
};