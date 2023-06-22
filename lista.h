#ifndef __LISTA_H__
#define __LISTA_H__

#include "nodo.h"

template<class T>
class Lista{
	private:
		Nodo<T> *primero;
		Nodo<T> *cursor;
		int tamanio;
		
	public:
		/*post: Lista vacía*/	
		Lista() {
			this->primero = 0;      //Puntero a Nodo, inicializandolo al vacio
			this->cursor = 0;       //Puntero a Nodo, inicializandolo al vacio
			this->tamanio = 0;      //El tamanio de la lista inicializada en cero
		}

		/*post: Lista  identica a la Lista pasadapor argumento  */ 
		Lista(Lista<T> &otraLista) {   //Vamos a crear otra lista
			this->primero = 0;          //Inicializando los atributos.
			this->cursor = 0;
			this->tamanio = 0;
	
			this->agregar(otraLista);   //
		}

		/*post: indica si la Lista tiene algún elemento  */
		bool estaVacia() {
			return (this->tamanio == 0);    //Devuelve true o false, true si el tamanio es igual a cero
		}

		/*post: devuelve la cantidad de elementos que tiene la Lista*/
		int contarElementos() {
			return this->tamanio;        //Devuelve el tamanio de la lista
		}
		
		/* post: agrega elemento al inicio de Lista, posición contarElementos() + 1  */
		void agregar(T elemento){
			Nodo<T> *aux = new Nodo<T>(elemento); 
	
			aux->setSig(primero); 
	
			primero = aux;
	
			tamanio++;
	
		}

		/* post: este si agrega elemento al final de Lista, posición contarElementos() + 1  */
		void agregarFinal( T elemento ) {
			Nodo<T>* aux = new Nodo<T>(elemento);
			if ( primero == NULL ) {
				primero = aux;
				tamanio = 1;
			}
			else {
				Nodo<T>* sig = primero;
				while ( sig->getSig() != NULL) {
					sig = sig->getSig();
				}
				sig->setSig(aux);
				tamanio++;
			}
		}

		/*
		void Lista::agregar(int elemento){
		this->agregar(elemento, this->tamanio + 1);   //Agregando Nodos en la lista llamando otro metodo
		}*/
		
		//pre : posición pertenece al intervalo: [1, contarElementos() + 1]
		//post: agrega el elemento en la posición indicada */
		void agregar(T elemento, int posicion){
			if ((posicion > 0) && (posicion < this->tamanio+1)){    //Si la posicion es entre 1 y la longitud de la lista + 1
				Nodo<T> *nuevo = new Nodo<T>(elemento);                  //Creamos un nuevo Nodo, con un puntero que apunta a ese Nodo nuevo
		
				if (posicion == 1) {                 //Si queremos agregar un Nodo al principio de la lista
					nuevo->setSig(this->primero);    //Voy al Nodo donde apunta nuevo y lo enganchamos al nodo donde apunta primero que es el 1er nodo
					this->primero = nuevo;  //Ahora decimos al ptro primero de apuntar al Nodo recien creado, y ahora sera el primer nodo de la lista
				}                           //CREO QUE PRIMERO O P, SIEMPRE APUNTA AL INICIO DE LA LISTA(PRIMER NODO) HASTA AHORA NO SE PORQUE
				else {                                                  //Sino
					Nodo<T> *anterior = this->obtenerNodo(posicion - 1);  //Defino un ptro anterior que apuntara al nodo anterior a la posicion deseada
			
					nuevo->setSig(anterior->getSig()); //Voy al nodo donde apunta nuevo y lo enganchamos al nodo que sigue el nodo que apunta anterior
					anterior->setSig(nuevo);       //Ahora decimos al nodo que apunta anterior de apuntar al nodo que apunta nuevo que es 
				}                                 //  el nodo recien creado(lo del new)
		
				this->tamanio++;            //Crecemos el tamanio ahora ya no va se cero
		
				this->iniciarCursor();      //Volvemos a ubicar el ptro cursor
			}
		}


		//-------------------------------Falta entender--------------------------------------------------------------------------------
		/* post: agrega todos los elementos de otraLista  a partir de la posición contarElementos() + 1  */
		void agregar(Lista &otraLista){
			otraLista.iniciarCursor();           //Cursor de OtraLista  se inicializa en NULL
	
			while (otraLista.avanzarCursor()){                   //Mientras  exista un nodo apuntado por el cursor 
				this->agregar(otraLista.obtenerContenidoCursor());  //Se agrega al final el dato del nodo apuntado por el cursor
			}
		}
		//---------------------------------------_______________-----------------------------------------------------------------------

		// pre : posición pertenece al intervalo: [1, contarElementos()]
		//post: devuelve el elemento en la posición indicada   */
		T obtenerDato(int posicion){
			T elemento;
	
			if ( posicion >= 0 && posicion < this->tamanio ) {
				elemento = this->obtenerNodo(posicion)->getInfo();  //obtenerNodo(posición) retorna un puntero al nodo, con el 
																	//  cual invocamos a obtenerDato()
			}
			else {
				throw "posición fuera de rango";
			}
			return elemento;
		}                                                          
		
		//pre :posición pertenece al intervalo: [1, contarElementos()]
		//post: cambia elemento de posición indicada por elemento pasado.
		void asignar(T elemento, int posicion){
			if (posicion>0 && (posicion <= tamanio))
				this->obtenerNodo(posicion)->setInfo(elemento);  //obtenerNodo(posición) retorna un puntero al nodo, con el cual 
		}                                                       //  invocamos a  cambiarDato con elemento como argumento.
		
		//pre : posición pertenece al intervalo: [1, contarElementos()]
      	//post: remueve de la Lista el elemento en la posición indicada
		void remover(int posicion){
			if (posicion>0 && (posicion <= tamanio)){
				Nodo<T> *removido;
		
				if (posicion == 1) {
					removido = this->primero;
					this->primero = removido->getSig();
				}
				else {
					Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
			
					removido = anterior->getSig();     //Estaba en el Nodo anterior a la posicion deseada, ahora me muevo a la posicion deseada
					anterior->setSig(removido->getSig()); //N.B: aca es como: Nodo *posterior = removido->getSig() tal que posterior es otro 
				}                                         //     ptro a Nodo que apunta en una posicion posterior al Nodo donde apunta removido
		
				delete removido;
		
				this->tamanio--;
		
				//Cualquier recorrido actual quedara invalido
				this->iniciarCursor();
			}
		}
		
		// post: deja cursor de Lista preparado para hacer nuevo recorrido.
		void iniciarCursor(){  //si
			this->cursor = 0;
		}
		
		/*  
			El método avanzar cursor permite el movimiento de un nodo al siguiente usando el cursor
			
			pre : se ha iniciado un recorrido (invocando el método iniciarCursor()) 
				y desde entonces no se han agregado o  removido elementos de la Lista.
			
			post: mueve cursor; lo posiciona en siguiente elemento del recorrido
				El valor de retorno indica si el cursor quedó posicionado sobre un  
				elemento o no (en caso de que la Lista esté vacía o no existan más elementos por recorrer.) 
		*/
		bool avanzarCursor(){
			if (this->cursor == 0) {
				this->cursor = this->primero;
			}
			else {
				this->cursor = this->cursor->getSig();
			}
		
			return (this->cursor != 0);   //Si el cursor apunta a un Nodo devuelve true
		}
		
		//pre : el cursor está posicionado sobre un elemento de la Lista (fue invocado el método 
		//		avanzarCursor() y devolvió true)
    	//post: devuelve el elemento en la posición del cursor.
		T obtenerCursor(){   //si
			T elemento;
	
			if ( this->cursor != 0 ) {
				elemento = this->cursor->getInfo();
			}
			else {
				throw "posición fuera de rango";
			}
		
			return elemento;
		}

		/* post: libera los recursos asociados a la Lista. */
		~Lista(){
			while (this->primero){
				Nodo<T> *aborrar = this->primero;
		
				this->primero = this->primero->getSig();
				delete aborrar;
			}
		}

		void borrarLista() {
			while (this->primero) {
				Nodo<T>* aborrar = this->primero;

				this->primero = this->primero->getSig();
				delete aborrar;
			}
			this->primero = NULL;
		}

		private:
			//pre : posición pertenece al intervalo: [1, contarElementos()]
			//post: devuelve el nodo en la posición indicada.
			Nodo<T>* obtenerNodo(int posicion){
				Nodo<T> *actual = this->primero;
	
				for ( int i = 0; i < posicion; i++ ) {
												//Si tengo que llegar al Nodo 5, al llegar a la posicion 4
					actual = actual->getSig();  // Decimos a actual de apuntar al Nodo siguiente que es Nodo 5, Ya que i=5 No es < posicion=5 salgo
				}
		
				return actual;
			}
};

#endif //__LISTA_H__
