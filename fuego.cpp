#include "fuego.h"
#include <iostream>
#include "personaje.h"
<<<<<<< HEAD

=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
using namespace std;

Fuego::Fuego(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

<<<<<<< HEAD
void Fuego::setFila(int fila){
    this->fila = fila;
}

void Fuego::setColumna(int columna){
    this->columna = columna;
}

int Fuego::getFila(){
    return this->fila;
}

int Fuego::getColumna(){
    return this->columna;
}

=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6

void Fuego::alimentar(string nombre){
    if(this->energia > 20 || this->energia + 15 > 20){
        throw std::string("No se puede tener energia mayor a 20");
    }
    else{
        this->energia += 15;
    }
}

int Fuego::mostrarEnergiaActual(){
    return this->energia;
}

string Fuego::getElemento(){
    return "fuego";
}

Fuego::~Fuego(){
}
