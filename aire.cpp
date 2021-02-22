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
    bool tieneEnergia = energia >= 15;
    if(tieneEnergia ){
        restarEnergia(15);
    }
    return tieneEnergia;
}

void Aire ::modificarPorTurno() {
    sumarEnergia(5);
}
int Aire :: danoAtaque(Personaje *personajeAtacar) {

    if(personajeAtacar -> getElemento() == "tierra")
        return 20;
    else if(personajeAtacar -> getElemento() == "fuego")
        return  10;
    else
        return 15;

}

void Aire ::atacar(Personaje** personajeAtacado) {

     restarEnergia(8);
    for(int i = 0; i < MAXRIVALES ; i++){
        if(personajeAtacado[i] != nullptr){
            int dano = danoAtaque(personajeAtacado[i]);
            quitarVidaPersonaje(personajeAtacado[i],dano);
        }
    }

}


Aire ::~Aire() {

}