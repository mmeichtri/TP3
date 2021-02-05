#include "precipicio.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Precipicio::Precipicio(int fila, int columna ):Casillero(fila, columna ){
}

void Precipicio::restarGastoDeEnergia(Personaje* personajeJugador){
    if(this->personajeJugador->getElemento == "tierra"){
        this->personajeJugador->energia -= 2;
    }
    if(this->personajeJugador->getElemento == "fuego"){
        this->personajeJugador->energia--;
    }
    if(this->personajeJugador->getElemento == "agua"){
        this->personajeJugador->energia--;
    }
}

Precipicio::~Precipicio(){
}
