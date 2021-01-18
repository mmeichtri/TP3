#include "tierra.h"
#include <iostream>

using namespace std;

Tierra::Tierra(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

void Tierra::alimentar(string nombre){
    if(this->energia > 20 || this->energia + 8 > 20){
        throw std::string("No se puede tener energia mayor a 20");
    }
    else{
        this->energia += 8;
    }
}

int Tierra::mostrarEnergiaActual(){
    return this->energia;
}

Tierra::~Tierra(){
}
