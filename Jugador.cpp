#include "Jugador.h"

Jugador::Jugador() {
	this->idJugador = this->NuevoID( 0 );
	this->nombre = "";
	this->soldados = NULL;
	this->minasActivas = NULL;
    this->cartas = NULL;
}

int Jugador::NuevoID( int numero = 0 ) {
	// Cada vez que se instancia un nuevo jugador en la partida se crea un ID de bando del Jugador.
	static int numeroInicial;
	if ( numero <= 0) {
		numeroInicial = 1;
	}
	else {
		numeroInicial = numero;
	}
	return numeroInicial++;
}

Jugador::Jugador( string nombre ) {
	this->idJugador = this->NuevoID();
	this->nombre = nombre;
	this->soldados = NULL;
	// this->minasActivas = nullptr;
}

Jugador::~Jugador() {
	// Liberar listas?
	this->nombre = "";
}

// Setters

void Jugador::setNombreJugador(string nombre) {
	this->nombre = nombre;
}

void Jugador::reiniciarID() {
	this->NuevoID( 0 );
}

// Getters

int Jugador::getCantidadSoldados() {
	return this->soldados->contarElementos();
}

string Jugador::getNombreJugador() {
	return this->nombre;
}

int Jugador::getIdJugador() {
	return this->idJugador;
}

Jugador * Jugador::getJugador() {
	return this;
}

void Jugador::setMinasActivas(Lista<Mina *> *minasActivas) {
    this->minasActivas = minasActivas;
}

void Jugador::setSoldados(Lista<Soldado *> *soldados) {
    this->soldados = soldados;
}

Lista<Mina *> *Jugador::getMinasActivas() {
    return this->minasActivas;
}

// Acciones

/*
void Jugador::moverSoldado( Tablero3D * tablero, Coordenada * coordenadaDestino, Soldado * Soldado ) {
	// 	Nota La validaci�n del movimiento, Coordenadas Origen y Destino
	//   deben ser realizadas por el m�dulo de l�gica del juego.
	//
	
}*/

void Jugador::moverSoldado(Tablero3D *tablero1, Coordenada *coordenadaDestino, int idSoldado, Lista<Jugador*> *jugadores) {
    Casillero *casillero = tablero1->getCasillero(coordenadaDestino->getCoordenadaX(),coordenadaDestino->getCoordenadaY(),coordenadaDestino->getCoordenadaZ());
    if(casillero->getEstadoCasillero() != casillerovacio){
        if(casillero->getEstadoCasillero() == soldado){
            int encontroSoldado = 0;
            jugadores->iniciarCursor();
            while(jugadores->avanzarCursor() && encontroSoldado !=1){
                if(jugadores->obtenerCursor()->idJugador == casillero->getSoldado()->getJugador()){
                    jugadores->obtenerCursor()->eliminarSoldado(casillero->getSoldado()->getIDSoldado());
                    encontroSoldado = 1;
                    casillero->setSoldado(NULL);
                    casillero->setEstadoCasillero(casillerovacio);
                }
            }
            this->eliminarSoldado(idSoldado);
        }
        else if(casillero->getEstadoCasillero() == mina){
            int encontroMina = 0;
            jugadores->iniciarCursor();
            while(jugadores->avanzarCursor() && encontroMina !=1){
                if(jugadores->obtenerCursor()->idJugador == casillero->getMina()->getJugador()){
                    jugadores->obtenerCursor()->eliminarMina(casillero->getMina());
                    encontroMina = 1;
                    casillero->setMina(NULL);
                    casillero->setSoldado(NULL);
                    casillero->setEstadoCasillero(casilleroinactivo);
                    casillero->setTurnosDeInactividad(5);
                }
            }
            this->eliminarSoldado(idSoldado);
        }
    }else{
        casillero->setEstadoCasillero(soldado);
        casillero->setSoldado(this->obtenerSoldadoPorId(idSoldado));
    }
}

void Jugador::actualizarPosicionSoldado(Coordenada *coordenada, int idSoldado, Jugador *jugador) {
    jugador->getSoldados()->iniciarCursor();
    while(jugador->getSoldados()->avanzarCursor()){
        Soldado *soldado = jugador->getSoldados()->obtenerCursor();
        if(soldado->getIDSoldado() == idSoldado){
            jugador->getSoldados()->obtenerCursor()->setCoordenada(coordenada);
            return;
        }
    }
}

Lista<Soldado *> *Jugador::getSoldados() {
    return this->soldados;
}

void Jugador::eliminarSoldado(int idSoldado) {
    this->soldados->iniciarCursor();
    int contador = 0;
    while (this->soldados->avanzarCursor()){
        if(this->soldados->obtenerCursor()->getIDSoldado() == idSoldado){
            this->soldados->remover(contador);
            return;
        }
        contador +=1;
    }
}

void Jugador::eliminarMina(Mina *mina) {
    this->minasActivas->iniciarCursor();
    int contador = 0;
    while(this-minasActivas->avanzarCursor()){
        if(this->minasActivas->obtenerCursor()->getIdMina() == mina->getIdMina()){
            this->minasActivas->remover(contador);
            return;
        }
        contador +=1;
    }
}

Soldado *Jugador::obtenerSoldadoPorId(int idSolado) {
    this->soldados->iniciarCursor();
    while (this->soldados->avanzarCursor()){
        if(this->soldados->obtenerCursor()->getIDSoldado() == idSolado){
            return this->soldados->obtenerCursor();
        }
    }
    return NULL;
}

void Jugador::minarCasillero(Tablero3D *tablero, Coordenada *coordenadaDestino, Lista<Jugador *> *jugadores) {
    Mina *minaActiva;
    minaActiva = new Mina();
    minaActiva->setCoordenada(coordenadaDestino);
    Casillero *casillero = tablero->getCasillero(coordenadaDestino->getCoordenadaX(),coordenadaDestino->getCoordenadaY(),coordenadaDestino->getCoordenadaZ());
    if(casillero->getEstadoCasillero() != casillerovacio){
        if(casillero->getEstadoCasillero() == soldado){
            jugadores->iniciarCursor();
            while(jugadores->avanzarCursor()){
                if(jugadores->obtenerCursor()->getIdJugador() == casillero->getSoldado()->getJugador()){
                    jugadores->obtenerCursor()->eliminarSoldado(casillero->getSoldado()->getIDSoldado());
                    casillero->setEstadoCasillero(casilleroinactivo);
                    casillero->setTurnosDeInactividad(5);
                    casillero->setMina(NULL);
                    casillero->setSoldado(NULL);
                    return;
                }
            }
        }
        else if(casillero->getEstadoCasillero() == mina){
            jugadores->iniciarCursor();
            while(jugadores->avanzarCursor()){
                if(jugadores->obtenerCursor()->getIdJugador() == casillero->getMina()->getJugador()){
                    jugadores->obtenerCursor()->eliminarMina(casillero->getMina());
                    this->eliminarMina(casillero->getMina());
                    casillero->setEstadoCasillero(casilleroinactivo);
                    casillero->setTurnosDeInactividad(5);
                    casillero->setMina(NULL);
                    casillero->setSoldado(NULL);
                    return;
                }
            }
        }
    }
    else{
        casillero->setMina(minaActiva);
        casillero->setEstadoCasillero(mina);
        this->minasActivas->agregarFinal(minaActiva);
    }
}

void Jugador::setListaCartas(Lista<string *> *cartas) {
    this->cartas = cartas;
}

Lista<string *> *Jugador::getListaCartas() {
    return this->cartas;
}

void Jugador::jugarCarta(std::string carta) {
    if(carta == "barco" ){
        Barco *barco = new Barco();
        barco->getJugador();
    }
}
