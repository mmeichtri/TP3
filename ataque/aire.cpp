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
    if(energia >= 8 )
        restarEnergia(8);
    return energia >= 8;
}

bool Aire ::energiaDefensa() {
     if(energia >= 15)
        restarEnergia(15);
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


Aire ::~Aire() {

}