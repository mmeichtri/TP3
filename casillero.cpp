#include "casillero.h"
#include <iostream>
#include <string>

using namespace std;

Casillero::Casillero(int fila, int columna, Personaje* personaje){
    this->fila = fila;
    this->columna = columna;
    this->personajeJugador = 0;
}

string Casillero::getTipo(){
    return this->tipo;
}

int Casillero::getFila(){
    return this->fila;
}

int Casillero::getColumna(){
    return this->columna;
}

Casillero::~Casillero(){
}



