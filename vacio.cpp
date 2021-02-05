#include "vacio.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Vacio::Vacio(int fila, int columna ):Casillero(fila, columna ){

}

//todos los personajes pierden 15 de energia al estar en un casillero de tipo Vacio
int Vacio::restarGastoDeEnergia(Personaje* personajeJugador){
    return 15;
}

Vacio::~Vacio(){
}
