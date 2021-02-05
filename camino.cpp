#include "camino.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Camino::Camino(int fila, int columna):Casillero(fila, columna ){

}

//todos los personajes pierden la misma cantidad de energia al pasar por un casillero de tipo Camino
void Camino::restarGastoDeEnergia(Personaje* personajeJugador){
    //this->personajeJugador->energia -= 2;
}

Camino::~Camino(){
}
