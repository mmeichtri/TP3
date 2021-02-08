#include "volcan.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Volcan::Volcan(int fila, int columna ):Casillero(fila, columna ){
}

int Volcan::restarGastoDeEnergia(Personaje* personajeJugador){
    if(personajeJugador->getElemento() == "agua"){
        return 2;
    }
    if(personajeJugador->getElemento() == "tierra"){
        return 1;
    }
    if(personajeJugador->getElemento() == "aire"){
        return 1;
    }
    return 0;
}

Volcan::~Volcan(){
}
