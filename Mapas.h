#include "Tablero3D.h"
#include "Jugador.h"

class Mapas
{
public:
	Mapas( Tablero3D * );
	void cargarMapaDefault();
	void leerMapa( string );
	void imprimirMapa( string );
	void imprimirGraficoSuperficie( string );
	void verMapa();
private:
	Tablero3D * tablero;
};