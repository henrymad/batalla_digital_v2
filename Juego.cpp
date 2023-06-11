#include "Juego.h"
#include "NumeroRandom.h"
#include "PropiedadesDelJuego.h"

Juego::Juego() {
    this->nivelPartida = 0;
    this->cantidadDeSoldados = 0;
    this->cantidadDeJugadores = 0;

    //this->tablero = new Tablero3D();
    this->jugadores = new Lista<Jugador*>();
    this->pantallaGraficos = new PantallaGraficos();
}

void Juego::configurarPartida() {
    this->pantallaGraficos->imprimirEspaciosVertical(7);
    this->pantallaGraficos->imprimirPantalla("BATALLA DIGITAL", "Empezar Partida (E)", "Historial Partida (H)");
    std::string respuesta = this->pantallaGraficos->entradaUsuarioTexto("Ingresar Respuesta: ");

    if(respuesta == "E"){
        this->pantallaGraficos->imprimirEspaciosVertical(7);
        this->pantallaGraficos->imprimirPantalla("CONFIGURACION PARTIDA", "Cantidad De Jugadores", "Seleccionar Nivel (1-10)", "Cantidad De Soldados");
        this->pantallaGraficos->imprimirEspaciosVertical(1);

        this->cantidadDeJugadores = this->pantallaGraficos->entradaUsuarioNumero("Ingresar cantidad de Jugadores: ");
        this->nivelPartida = this->pantallaGraficos->entradaUsuarioNumero("Ingresar nivel partida: ");
        this->cantidadDeSoldados = this->pantallaGraficos->entradaUsuarioNumero("Ingresar cantidad de Soldados: ");
        this->pantallaGraficos->imprimirEspaciosVertical(1);

        this->configurarJugadores();

    }
}

void Juego::configurarJugadores() {
        for (int i=0;i<this->cantidadDeJugadores;i++){
            Jugador *jugador = new Jugador();

            string nombre =  this->pantallaGraficos->entradaUsuarioTexto("Ingresar nombre jugador: ");
            Lista<Soldado*> *soldados = this->configurarSoldados(this->cantidadDeSoldados, jugador->getIdJugador());

            jugador->setNombreJugador(nombre);
            jugador->setMinasActivas(new Lista<Mina*>());
            jugador->setSoldados(soldados);
            this->jugadores->agregar(jugador);
        }
}

Lista<Soldado *> *Juego::configurarSoldados(int cantidadDeSoldados, int idJugador) {
    Lista<Soldado*> *resultado = new Lista<Soldado*>();

    for(int i=0;i<cantidadDeSoldados;i++){
        Soldado *soldado = new Soldado();
        soldado->getCoordenada()->setCoordenadaX(NumeroRandom::numeroAleatorioSuperficie(CANTIDAD_DE_CASILLERO_EJE_X));
        soldado->getCoordenada()->setCoordenadaY(NumeroRandom::numeroAleatorioSuperficie(CANTIDAD_DE_CASILLERO_EJE_Y));
        soldado->getCoordenada()->setCoordenadaZ(NumeroRandom::numeroAleatorioAltura(CANTIDAD_DE_CASILLERO_EJE_Z));
        soldado->setJugador(idJugador);
        resultado->agregar(soldado);
        cout<<soldado->getCoordenada()->getCoordenadaX()<<","<<soldado->getCoordenada()->getCoordenadaY()<<","<<soldado->getCoordenada()->getCoordenadaZ()<<","<<endl;
    }
    return resultado;
}
