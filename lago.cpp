#include "lago.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Lago::Lago(int fila, int columna):Casillero(fila, columna ){

}

int Lago::restarGastoDeEnergia(Personaje* personajeJugador){
    if(personajeJugador->getElemento() == "fuego"){
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

Lago::~Lago(){
}
