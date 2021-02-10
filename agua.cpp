#include "agua.h"
<<<<<<< HEAD
#include <iostream>
#include <string>
#include "personaje.h"

=======
//#include "interfazUsuario.h"
#include <iostream>
#include <string>
#include "personaje.h"
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
using namespace std;

Agua::Agua(string nombre, int escudo, int vida):Personaje(nombre, escudo, vida){
    this->energia = rand() % 21;
}

<<<<<<< HEAD
void Agua::setFila(int fila){
    this->fila = fila;
}

void Agua::setColumna(int columna){
    this->columna = columna;
}

int Agua::getFila(){
    return this->fila;
}

int Agua::getColumna(){
    return this->columna;
}


=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
void Agua::alimentar(string nombre){
    if(this->energia > 20 || this->energia + 10 > 20 || this->cantidadAlimentaciones > 3){
        throw std::string("No se puede tener energia mayor a 20, ni se puede alimentar mas de 3 veces");
    }
    else{
        this->energia += 10;
        this->cantidadAlimentaciones++;
    }
}

int Agua::mostrarEnergiaActual(){
    return this->energia;
}

string Agua::getElemento(){
    return "agua";
}

Agua::~Agua(){
}
