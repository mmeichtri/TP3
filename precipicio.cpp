#include "precipicio.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Precipicio::Precipicio(int fila, int columna ):Casillero(fila, columna ){
}

int Precipicio::restarGastoDeEnergia(Personaje* personajeJugador){
    if(personajeJugador->getElemento() == "tierra"){
        return 2;
    }
    if(personajeJugador->getElemento() == "fuego"){
        return 1;
    }
    if(personajeJugador->getElemento() == "agua"){
        return 1;
    }
    return 0;
}

Precipicio::~Precipicio(){
}
