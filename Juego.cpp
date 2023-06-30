#include "Juego.h"
#include "PropiedadesDelJuego.h"
#include <time.h>
#include <stdlib.h>


Juego::Juego() {
    this->nivelPartida = 0;
    this->cantidadDeSoldados = 0;
    this->cantidadDeJugadores = 0;
    this->cartas = new Lista<Carta*>();
    this->jugadores = new Lista<Jugador*>();
    this->pantallaGraficos = new PantallaGraficos();
    this->tablero = new Tablero3D();
    this->graficocasillero = NULL;
    this->mostrar = NULL;
    this->salidaTablero = NULL;
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
        this->configurarCartas(nivelPartida);

    }
}

void Juego::configurarJugadores() {
        for (int i=0;i<this->cantidadDeJugadores;i++){
            Jugador *jugador = new Jugador(i+1);

            string nombre =  this->pantallaGraficos->entradaUsuarioTexto("Ingresar nombre jugador: ");
            Lista<Soldado*> *soldados = this->configurarSoldados(this->cantidadDeSoldados, jugador->getIdJugador());

            jugador->setNombreJugador(nombre);
            jugador->setMinasActivas(new Lista<Mina*>());
            jugador->setListaCartas(new Lista<Carta*>());
            jugador->setSoldados(soldados);
            this->jugadores->agregarFinal(jugador);
        }
}

Lista<Soldado *> *Juego::configurarSoldados(int cantidadDeSoldados, int idJugador) {
    Lista<Soldado*> *resultado = new Lista<Soldado*>();
    srand(time(NULL));
    for(int i=0;i<cantidadDeSoldados;i++){
        Soldado *soldado1;
        soldado1 = new Soldado(i+1);
        soldado1->getCoordenada()->setCoordenadaX(rand()%FILAS_TABLERO);
        soldado1->getCoordenada()->setCoordenadaY(rand()%COLUMNAS_TABLERO);
        int z = rand()%ALTURA_TABLERO;
        if(z<5){
            soldado1->getCoordenada()->setCoordenadaZ(z+NIVEL_SUPERFICIE);
        }
        else{
            soldado1->getCoordenada()->setCoordenadaZ(z);
        }
        soldado1->setJugador(idJugador);
        resultado->agregarFinal(soldado1);
        Casillero *casillero = this->tablero->getCasillero(soldado1->getCoordenada()->getCoordenadaX(),soldado1->getCoordenada()->getCoordenadaY(), soldado1->getCoordenada()->getCoordenadaZ());
        casillero->setEstadoCasillero(soldado);
        casillero->setSoldado(soldado1);
        this->tablero->setCasillero(casillero, casillero->getCoordenada()->getCoordenadaX(), casillero->getCoordenada()->getCoordenadaY(), casillero->getCoordenada()->getCoordenadaZ());
    }
    return resultado;
}

void Juego::empezarPartida() {

    this->mapa = new Mapas(this->tablero);
    this->mapa->cargarMapa3D( "mapadefault.txt", false );
    this->mapa->grabarMapa2D( "prueba1.txt" );

    this->jugadores->iniciarCursor();
    int cantidadDeJugadas = 1;
    int seTErminoELJuego = 0;
    while (this->jugadores->avanzarCursor() && seTErminoELJuego !=1){
        Jugador *jugador = this->jugadores->obtenerCursor();


        this->pantallaGraficos->imprimirEspaciosVertical(5);
        this->pantallaGraficos->imprimirLineaHorizontal(200);
        this->pantallaGraficos->imprimirTituloCentrado("BATALLA DIGITAL",100);
        this->pantallaGraficos->imprimirLineaHorizontal(200);

        this->pantallaGraficos->imprimirMenuJugador(jugador);
        this->pantallaGraficos->imprimirEspaciosVertical(1);
        this->pantallaGraficos->imprimirTitulo("Seleccionar Carta: ");

        int posicionCarta;

        if(this->nivelPartida >= 5){
            posicionCarta = this->pantallaGraficos->entradaUsuarioNumero("Ingresar numero del (1-3), para seleccionar una carta: ");
        }
        else{
            posicionCarta = this->pantallaGraficos->entradaUsuarioNumero("Ingresar numero del (1-2), para seleccionar una carta: ");
        }
        Carta *carta = new Carta();
        carta->setNombre(CARTAS[posicionCarta - 1]);
        carta->setIdJugador(this->jugadores->obtenerCursor()->getIdJugador());
        this->jugadores->obtenerCursor()->getListaCartas()->agregarFinal(carta);
        this->pantallaGraficos->imprimirEspaciosVertical(1);
        this->pantallaGraficos->imprimirTitulo("Mover soldado");
        int idSoldado = this->pantallaGraficos->entradaUsuarioNumero("Ingresar id del soldado que desea mover: ");

        Coordenada *nuevaCoordenada = this->pantallaGraficos->entradaCoordenada();
        nuevaCoordenada = this->coordenadaValida(nuevaCoordenada);

        this->jugadores->obtenerCursor()->actualizarPosicionSoldado(nuevaCoordenada, idSoldado, jugador);
        this->jugadores->obtenerCursor()->moverSoldado(tablero,nuevaCoordenada,idSoldado,this->jugadores);

        this->pantallaGraficos->imprimirEspaciosVertical(1);
        this->pantallaGraficos->imprimirTitulo("Minar Casiilero");

        Coordenada *coordenadaMina = this->pantallaGraficos->entradaCoordenada();
        coordenadaMina = this->coordenadaValida(coordenadaMina);

        this->jugadores->obtenerCursor()->minarCasillero(tablero,coordenadaMina,this->jugadores);

        string respuesta = this->pantallaGraficos->entradaUsuarioTexto("Desea jugar una carta: si/no: ");
        if(respuesta == "si"){
            respuesta = this->pantallaGraficos->entradaUsuarioTexto("Ingresar nombre de la carta: ");
            this->jugadores->obtenerCursor()->jugarCarta(respuesta);
        }
        this->eliminarJugador(jugador, cantidadDeJugadas);

        Graficas * bmpMapa;
        bmpMapa = new Graficas( tablero );
        bmpMapa->graficarSuperficie( "grafico.bmp", jugador );
        mapa->imprimirMapa("prueba1.txt", NULL);

        if(this->cantidadDeJugadores == 1){
            seTErminoELJuego = 1;
        }
        this->tablero->actualizarEstadoCasillero();
        if(cantidadDeJugadas == this->jugadores->contarElementos()){
            this->jugadores->iniciarCursor();
            cantidadDeJugadas = 1;
        }else{
            cantidadDeJugadas +=1;
        }
    }
    this->pantallaGraficos->imprimirTitulo("GANADOR");
    this->pantallaGraficos->imprimirLineaHorizontal(200);
    this->pantallaGraficos->imprimirTitulo(this->jugadores->obtenerDato(0)->getNombreJugador());
    this->pantallaGraficos->entradaUsuarioTexto("Ingresar cualquier caracter para terminar el juego");
    this->cartas->borrarLista();
}

void Juego::configurarCartas(int niverlJuego) {
    if(this->nivelPartida < niverlJuego){
        for(int i = 0; i<2;i++){
            Carta *carta = new Carta();
            carta->setNombre(CARTAS[i]);
            this->cartas->agregarFinal(carta);
        }
    }
    else{
        for(int i = 0; i<3;i++){
            Carta *carta = new Carta();
            carta->setNombre(CARTAS[i]);
            this->cartas->agregarFinal(carta);
        }
    }
}

Juego::~Juego() {
    this->jugadores->borrarLista();
    this->cartas->borrarLista();
    delete this->pantallaGraficos;
    delete this->tablero;
    this->pantallaGraficos = NULL;
    this->tablero= NULL;
}

void Juego::eliminarJugador(Jugador *jugador, int posicion) {
    if(jugador->getSoldados()->contarElementos() ==0){
        this->jugadores->remover(posicion);
    }
}

Coordenada *Juego::coordenadaValida(Coordenada *nuevoCoordenada) {
    Casillero *casillero = this->tablero->buscarCasilleroPorCoordenada(nuevoCoordenada->getCoordenadaX(), nuevoCoordenada->getCoordenadaY(),nuevoCoordenada->getCoordenadaZ());
    while(casillero->getEstadoCasillero() == casilleroinactivo){
        this->pantallaGraficos->imprimirTitulo("EL Casillero esta inactivo, ingresar nuevamente las coordenadas");
        nuevoCoordenada = this->pantallaGraficos->entradaCoordenada();
        casillero = this->tablero->buscarCasilleroPorCoordenada(nuevoCoordenada->getCoordenadaX(), nuevoCoordenada->getCoordenadaY(),nuevoCoordenada->getCoordenadaZ());
    }
    return nuevoCoordenada;
}


