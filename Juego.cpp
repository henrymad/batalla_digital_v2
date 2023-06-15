#include "Juego.h"
#include "PropiedadesDelJuego.h"
#include <time.h>
#include <stdlib.h>


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
            this->jugadores->agregarFinal(jugador);
        }
}

Lista<Soldado *> *Juego::configurarSoldados(int cantidadDeSoldados, int idJugador) {
    Lista<Soldado*> *resultado = new Lista<Soldado*>();
    srand(time(NULL));
    for(int i=0;i<cantidadDeSoldados;i++){
        Soldado *soldado = new Soldado();
        soldado->getCoordenada()->setCoordenadaX(rand()%FILAS_TABLERO);
        soldado->getCoordenada()->setCoordenadaY(rand()%COLUMNAS_TABLERO);
        soldado->getCoordenada()->setCoordenadaZ(rand()%NIVEL_SUPERFICIE);
        soldado->setJugador(idJugador);
        resultado->agregarFinal(soldado);
    }
    return resultado;
}

void Juego::empezarPartida() {
    this->tablero = new Tablero3D();
    this->jugadores->iniciarCursor();
    int count = 0;
    while (this->jugadores->avanzarCursor()){
        Jugador *jugador = this->jugadores->obtenerCursor();
        this->pantallaGraficos->imprimirEspaciosVertical(5);
        this->pantallaGraficos->imprimirLineaHorizontal(200);
        this->pantallaGraficos->imprimirTituloCentrado("BATALLA DIGITAL",100);
        this->pantallaGraficos->imprimirLineaHorizontal(200);

        cout<<"imprimir tablero"<<endl;

        this->pantallaGraficos->imprimirMenuJugador(jugador);
        this->pantallaGraficos->imprimirEspaciosVertical(1);
        this->pantallaGraficos->imprimirTitulo("Mover soldado");

        int idSoldado = this->pantallaGraficos->entradaUsuarioNumero("Ingresar id del soldado que desea mover: ");

        Coordenada *nuevaCoordenada;
        nuevaCoordenada = new Coordenada();
        nuevaCoordenada->setCoordenadaX(this->pantallaGraficos->entradaUsuarioNumero("Ingresar nueva coordenda en X: "));
        nuevaCoordenada->setCoordenadaY(this->pantallaGraficos->entradaUsuarioNumero("Ingresar nueva coordenda en Y: "));
        nuevaCoordenada->setCoordenadaZ(this->pantallaGraficos->entradaUsuarioNumero("Ingresar nueva coordenda en Z: "));

        this->jugadores->obtenerCursor()->actualizarPosicionSoldado(nuevaCoordenada, idSoldado, jugador);
        this->jugadores->obtenerCursor()->moverSoldado(tablero,nuevaCoordenada,idSoldado,this->jugadores);

        this->pantallaGraficos->imprimirEspaciosVertical(1);
        this->pantallaGraficos->imprimirTitulo("Minar Casiilero");

        Coordenada *coordenadaMina;
        coordenadaMina = new Coordenada();
        coordenadaMina->setCoordenadaX(this->pantallaGraficos->entradaUsuarioNumero("Coordenda en X: "));
        coordenadaMina->setCoordenadaY(this->pantallaGraficos->entradaUsuarioNumero("Coordenda en Y: "));
        coordenadaMina->setCoordenadaZ(this->pantallaGraficos->entradaUsuarioNumero("Coordenda en Z: "));

        this->jugadores->obtenerCursor()->minarCasillero(tablero,coordenadaMina,this->jugadores);
        if(count == 1){
            this->jugadores->iniciarCursor();
            count = 0;
        }else{
            count =+1;
        }

    }

}
