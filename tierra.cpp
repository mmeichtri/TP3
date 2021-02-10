#include "tierra.h"
#include <iostream>
#include "personaje.h"
<<<<<<< HEAD

=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
using namespace std;

Tierra::Tierra(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

<<<<<<< HEAD
void Tierra::setFila(int fila){
    this->fila = fila;
}

void Tierra::setColumna(int columna){
    this->columna = columna;
}

int Tierra::getFila(){
    return this->fila;
}

int Tierra::getColumna(){
    return this->columna;
}


=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
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

string Tierra::getElemento(){
    return "tierra";
}

Tierra::~Tierra(){
}
