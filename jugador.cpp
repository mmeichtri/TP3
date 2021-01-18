#include "jugador.h"
#include "listaJugador.h"
#include "nodoJugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(string nombre){
    this->nombreJugador = nombre;
}

string Jugador::getNombre(){
    return this->nombreJugador;
}
