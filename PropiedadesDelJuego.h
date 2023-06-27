#ifndef PROPIEDADESDELJUEGO_H
#define PROPIEDADESDELJUEGO_H

const int FILAS_TABLERO = 200;
const int COLUMNAS_TABLERO = 200;
const int ALTURA_TABLERO = 20;
const int NIVEL_SUPERFICIE = 5;
const int INDICE_PIXELACION = 5;
const int PROFUNDIDAD_BIT = 16;

static const std::string CARTAS[3]= {"bombaquimica", "barco", "avion"};


enum EstadoCasillero { soldado, mina, casillerovacio, casilleroinactivo, avion, barco, bombaquimica };
enum TipoTerrenoCasillero { tierra, agua, aire };

const int MAXIMO_SOLDADOS = 4;
const int TIEMPO_INHABILITADA_MINA = 3;
const int TIEMPO_INHABILITADA_BOMBA = 5;
const int LIMITE_BANDOS = 4;

const bool SO_LINUX = false;

const int VERSION = 2;
const int SUBVERSION = 0;

#endif //PROPIEDADESDELJUEGO_H
