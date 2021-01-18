#include "personaje.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "juego.h"
#include "lectorCsv.h"
#include "interfazUsuario.h"
#include "lista.h"
#include "interfazUsuario.h"
using namespace std;

Personaje::Personaje(string nombre, int escudo, int vida){
    this->elemento = elemento;
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

bool Personaje::validarCoincidencia(string personajeActualLista, string personajeBuscado){
    return personajeActualLista == personajeBuscado;
}

Personaje::~Personaje(){
}



