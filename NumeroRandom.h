
#ifndef BATALLA_DIGITAL_V3_NUMERORANDOM_H
#define BATALLA_DIGITAL_V3_NUMERORANDOM_H

#include<stdlib.h>
#include<time.h>


class NumeroRandom{
public:

    static int numeroAleatorioAltura(int cantidadFilas);
    static int numeroAleatorioSuperficie(int altura);
};

int NumeroRandom::numeroAleatorioAltura(int altura) {
    srand(time(NULL));
    return rand()%altura;
}

int NumeroRandom::numeroAleatorioSuperficie(int cantidadFilas) {
    srand(time(NULL));
    return rand()%cantidadFilas ;
}

#endif //BATALLA_DIGITAL_V3_NUMERORANDOM_H
