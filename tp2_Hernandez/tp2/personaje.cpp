#include "personaje.h"

Personaje :: Personaje(string nombre ,int escudo,int vida){

    this -> nombre = nombre;
    this -> escudo = escudo;
    this -> vida =vida;
    energia = rand() % (EMAX+1);
}
void Personaje :: mostrarNombre() {
    cout << nombre << endl;
}
void Personaje ::mostrarPersonaje() {

    cout << "NOMBRE:" << nombre << endl;
    cout << "ESCUDO : " << escudo << endl;
    cout << " VIDA : " << vida << endl;
    cout << "ENERGIA: " << energia << endl;
}

string Personaje ::obtenerNombre() {
    return nombre;
}
