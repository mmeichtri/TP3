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

void Precipicio::ImprimirCasilla(string nombre) {
    if(hayPersonajeEnCasillero())
        cout << __YLW__ << "[" << nombre << "]" << __NC__;
    else
        cout << __YLW__ << "[___]" << __NC__;
}
Precipicio::~Precipicio(){
}
