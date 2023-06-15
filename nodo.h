#include <iostream>

#ifndef __NODO_H__

#define __NODO_H__

template<class T>
class Nodo{
	private:
		T info;
		Nodo<T> *sig;
		
	public:
		Nodo(T x){
			info = x;
			sig = 0;
	
			//std::cout << "Se construyo un nodo con valor " << x << std::endl;
		}
		
		~Nodo(){
			//std::cout << "Se destruyo un nodo con valor " << info << std::endl;
		}
		
		T getInfo(){
			return info;
		}
		
		Nodo<T>* getSig(){   //obtenerSiguiente()
			return sig;
		}
		
		void setInfo(T i){     //cambiar_dato
			info = i;
		}
		
		void setSig(Nodo *n){
			sig = n;
		}
};

#endif //__NODO_H__
