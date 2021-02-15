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
    bool tieneEnergia = energia >= 8;
    if(tieneEnergia ){
        restarEnergia(8);
    }
    return tieneEnergia;
}

bool Aire ::energiaDefensa() {
    bool tieneEnergia = energia >= 15;
    if(tieneEnergia ){
        restarEnergia(15);
    }
    return tieneEnergia;
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


Aire ::~Aire() {

}