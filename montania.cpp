#include "montania.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Montania::Montania(int fila, int columna ):Casillero(fila, columna ){
}

int Montania::restarGastoDeEnergia(Personaje* personajeJugador){
    if(personajeJugador->getElemento() == "aire"){
        return 2;
    }
    if(personajeJugador->getElemento() == "fuego"){
        return 1;;
    }
    if(personajeJugador->getElemento() == "agua"){
        return 1;;
    }
    return 0;
}

void Montania::ImprimirCasilla(string nombre) {
    if(hayPersonajeEnCasillero())
        cout << __GRN__ <<"["<<nombre << "]";
    else
        cout << __GRN__ << "[___]";
}

Montania::~Montania(){
}
