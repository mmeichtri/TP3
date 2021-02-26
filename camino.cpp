#include "camino.h"
#include "personaje.h"
#include <iostream>
using namespace std;

Camino::Camino(int fila, int columna):Casillero(fila, columna ){

}

//todos los personajes pierden la misma cantidad de energia al pasar por un casillero de tipo Camino
int Camino::restarGastoDeEnergia(Personaje* personajeJugador){
    return 1;
}
void Camino::ImprimirCasilla(string nombre) {
    if(hayPersonajeEnCasillero())
        cout << __GRY__ <<"["<<nombre << "]";
    else
        cout << __GRY__ << "[___]";
}

Camino::~Camino(){
}
