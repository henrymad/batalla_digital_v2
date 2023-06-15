#ifndef PROPIEDADESDELJUEGO_H
#define PROPIEDADESDELJUEGO_H

const int FILAS_TABLERO = 200;
const int COLUMNAS_TABLERO = 200;
const int ALTURA_TABLERO = 20;
const int NIVEL_SUPERFICIE = 5;
const int INDICE_PIXELACION = 5;
const int PROFUNDIDAD_BIT = 24;

static const std::string TIERRA = "tierra";
static const std::string AGUA = "agua";


enum EstadoCasillero { soldado, mina, casillerovacio, casilleroinactivo, avion, barco, bombaquimica };
enum TipoTerrenoCasillero { tierra, agua, aire };

#endif //PROPIEDADESDELJUEGO_H
