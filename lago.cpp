#include "lago.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Lago::Lago(int fila, int columna):Casillero(fila, columna ){

}

void Lago::restarGastoDeEnergia(Personaje* personajeJugador){
    if(this->personajeJugador->getElemento == "fuego"){
        this->personajeJugador->energia -= 2;
    }
    if(this->personajeJugador->getElemento == "tierra"){
        this->personajeJugador->energia--;
    }
    if(this->personajeJugador->getElemento == "aire"){
        this->personajeJugador->energia--;
    }
}

Lago::~Lago(){
}
