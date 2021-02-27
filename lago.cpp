#include "lago.h"

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

void Lago :: ImprimirCasilla(string nombre) {
     if(hayPersonajeEnCasillero())
         cout << __BLU__ << "[" << nombre << "]" << __NC__;
     else
         cout << __BLU__ << "[___]" << __NC__;
}

Lago::~Lago(){
}
