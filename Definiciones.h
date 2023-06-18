#ifndef _DEFINICIONES_H_INCLUDED_
#define _DEFINICIONES_H_INCLUDED_

const int FILAS_TABLERO = 200;
const int COLUMNAS_TABLERO = 200;
const int ALTURA_TABLERO = 20;
const int NIVEL_SUPERFICIE = 5;
const int INDICE_PIXELACION = 3;
const int PROFUNDIDAD_BIT = 16;

enum EstadoCasillero { soldado, mina, casillerovacio, casilleroinactivo, avion, barco, bombaquimica };
enum TipoTerrenoCasillero { tierra, agua, aire };

const int MAXIMO_SOLDADOS = 4;
const int TIEMPO_INHABILITADA_MINA = 3;
const int TIEMPO_INHABILITADA_BOMBA = 5;
const int LIMITE_BANDOS = 4;

const bool SO_LINUX = false;

const int VERSION = 2;
const int SUBVERSION = 0;

#endif	// _DEFINICIONES_INCLUDED_