#ifndef PROPIEDADESDELJUEGO_H
#define PROPIEDADESDELJUEGO_H

static const int CANTIDAD_DE_CASILLERO_EJE_X = 10;
static const int CANTIDAD_DE_CASILLERO_EJE_Y = 10;
static const int CANTIDAD_DE_CASILLERO_EJE_Z = 2;

static const string TIERRA = "tierra";
static const string AGUA = "agua";


enum EstadoCelda { soldado, mina, casillavacia, casillainactiva, avion, barco, bombaquimica};
enum TipoTerrenoCelda { tierra, agua, aire };

#endif //PROPIEDADESDELJUEGO_H
