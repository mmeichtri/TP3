//
// Created by jose on 2/2/21.
//

#include "aire.h"
Aire :: Aire(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

}

string Aire ::getElemento() {
    string element = "aire";
    return element;
}
void Aire:: alimentarse() {
    cout << "los personajes de aire no se alimentan "<< endl;
}

bool Aire ::energiaAtaque() {
    return energia >= 8;
}

bool Aire ::energiaDefensa() {

    return energia >= 15;
}

int Aire :: danoAtaque(Personaje *personajeAtacar) {

    if(personajeAtacar -> getElemento() == "tierra")
        return 20;
    else if(personajeAtacar -> getElemento() == "fuego")
        return  10;
    else
        return 15;

}

int Aire ::atacar(Personaje *personajeAtacado) {

        return danoAtaque(personajeAtacado);
}

void Aire :: defenderse(int fila , int columna) {

    cambiarFYC(fila,columna);
}

Aire ::~Aire() {

}