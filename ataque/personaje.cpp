//
// Created by jose on 2/2/21.
//

#include "personaje.h"
Personaje :: Personaje(string nombre,int escudo,int vida){

    this -> nombre = nombre;
    this -> escudo = escudo;
    this -> vida =vida;
    energia = rand() % (EMAX+1);
}

void Personaje ::mostrarPersonaje() {

    cout << "NOMBRE:" << nombre << endl;
    cout << "ELEMENTO: " << getElemento() << endl;
    cout << "ESCUDO : " << escudo << endl;
    cout << " VIDA : " << vida << endl;
    cout << "ENERGIA: " << energia << endl;
}

string Personaje ::obtenerNombre() {
    return nombre;
}

int Personaje :: defensaEscudo(int valorDano) {

    if(escudo == 1)
       valorDano = valorDano - ((valorDano *10) / 100 );
    else if(escudo == 2)
        valorDano = valorDano - ((valorDano *20) / 100 );
    else if(escudo > 2 && getElemento() == "tierra")
        valorDano = valorDano - ((valorDano *80) / 100 );

    return valorDano;
}

void Personaje ::cambiarFYC(int fila, int columna) {
    this -> fila = fila;
    this -> columna = columna;
}

int Personaje ::obtenerFila() {
    return fila;
}
int Personaje ::obtenerColumna() {
    return columna;
}
void Personaje ::restarVida(int restar) {
    vida = vida - restar;
}

int Personaje ::obtenerVida() {
    return vida;
}

bool Personaje ::comprobarVida() {
    return vida > 0;
}

bool Personaje ::tieneEnergia(int energiaR) {
    return (energia-energiaR > 0);
}

void Personaje ::restarEnergia(int eRestar) {
    energia = energia - eRestar;
}

void Personaje ::sumarVida(int sumar) {
    if(vida + sumar < 100)
        vida = vida + sumar;
    else
        vida = 100;
}
void Personaje ::sumarEnergia(int sumar) {
    if(energia + sumar < 20)
        energia = energia + sumar;
    else
        energia = 20;
}
