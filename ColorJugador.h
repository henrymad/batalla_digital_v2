#ifndef _COLORJUGADOR_H_INCLUDED_
#define _COLORJUGADOR_H_INCLUDED_

class ColorJugador
{
public:
	ColorJugador();
	ColorJugador( int );
	~ColorJugador();
	void setJugador( int );
	int getColorVerde();
	int getColorRojo();
	int getColorAzul();
	int getColorVerde( int );
	int getColorRojo( int );
	int getColorAzul( int );
private:
	int jugador;
	void setColores();
	int colorRojo, colorVerde, colorAzul;
};

#endif   // _COLORJUGADOR_H_INCLUDED_