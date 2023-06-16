#include <fstream>

#include "Tablero3D.h"
#include "Jugador.h"

class Mapas
{
public:
	Mapas( Tablero3D * );
	void cargarMapaDefault();
	void leerMapa( string );
	void imprimirMapa( string, Jugador * );
	void imprimirGraficoSuperficie( string );
	void verMapa();
	void setJugador( Jugador * );
	void setNombreArchivo( string );
private:
	Tablero3D * tablero;
	Jugador * jugador;
	string nombreArchivo;
	string Celda( Casillero *, Jugador * );
	string hayAvion( Casillero *, Jugador * );
};