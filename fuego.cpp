#include "fuego.h"
#include <iostream>
#include "personaje.h"

using namespace std;

Fuego::Fuego(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

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
