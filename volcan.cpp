#include "volcan.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Volcan::Volcan(int fila, int columna ):Casillero(fila, columna ){
}

void Volcan::restarGastoDeEnergia(Personaje* personajeJugador){
    if(this->personajeJugador->getElemento == "agua"){
        this->personajeJugador->energia -= 2;
    }
    if(this->personajeJugador->getElemento == "tierra"){
        this->personajeJugador->energia--;
    }
    if(this->personajeJugador->getElemento == "aire"){
        this->personajeJugador->energia--;
    }
}

Volcan::~Volcan(){
}
