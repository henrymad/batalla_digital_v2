#include "Tablero3D.h"
#include "MostrarCasillero.h"

class MostrarTablero
{
public:
	MostrarTablero( Tablero3D * );
	~MostrarTablero();
	void imprimir( string );
	void setNombreArchivo( string );
	void setJugador( Jugador * );
	void setJugador( int );
private:
	Tablero3D * tablero;
	string nombreArchivo;
	Jugador jugador;
};

