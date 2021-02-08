#include "aire.h"
#include "personaje.h"
#include <iostream>

using namespace std;

Aire::Aire(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

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
