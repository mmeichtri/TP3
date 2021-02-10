#include "aire.h"
#include "personaje.h"
#include <iostream>

using namespace std;

Aire::Aire(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

<<<<<<< HEAD
void Aire::setFila(int fila){
    this->fila = fila;
}

void Aire::setColumna(int columna){
    this->columna = columna;
}

int Aire::getFila(){
    return this->fila;
}

int Aire::getColumna(){
    return this->columna;
}


=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
void Aire::alimentar(string nombre){
    cout << "Los personajes de aire, no se pueden alimentar" << endl;
}

int Aire::mostrarEnergiaActual(){
    return this->energia;
}

string Aire::getElemento(){
    return "aire";
}

Aire::~Aire(){
}
