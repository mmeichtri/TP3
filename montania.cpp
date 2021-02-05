#include "montania.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Montania::Montania(int fila, int columna ):Casillero(fila, columna ){
}

void Montania::restarGastoDeEnergia(Personaje* personajeJugador){
    if(this->personajeJugador->getElemento == "aire"){
        this->personajeJugador->energia -= 2;
    }
    if(this->personajeJugador->getElemento == "fuego"){
        this->personajeJugador->energia--;
    }
    if(this->personajeJugador->getElemento == "agua"){
        this->personajeJugador->energia--;
    }
}

Montania::~Montania(){
}
