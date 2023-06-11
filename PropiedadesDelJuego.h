#ifndef PROPIEDADESDELJUEGO_H
#define PROPIEDADESDELJUEGO_H


static const int CANTIDAD_DE_CASILLERO_EJE_X = 200;
static const int CANTIDAD_DE_CASILLERO_EJE_Y = 200;
static const int CANTIDAD_DE_CASILLERO_EJE_Z = 20;


enum EstadoCelda { soldado, mina, casillavacia, casillainactiva, avion, barco, bombaquimica};
enum TipoTerrenoCelda { tierra, agua, aire };

#endif //PROPIEDADESDELJUEGO_H
