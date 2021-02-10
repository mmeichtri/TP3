#include "personaje.h"
#include <iostream>
#include <string>

using namespace std;

Personaje::Personaje(string nombre, int escudo, int vida){
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
}

string Personaje::getNombre(){
    return this->nombre;
}

int Personaje::getEscudo(){
    return this->escudo;
}

int Personaje::getVida(){
    return this->vida;
}

void Personaje::alimentar(string nombrePersonaje){
}

int Personaje::mostrarEnergiaActual(){
    return this->energia;
}

string Personaje::getElemento(){
}

Personaje::~Personaje(){
}
