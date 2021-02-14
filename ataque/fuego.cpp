//
// Created by jose on 2/2/21.
//

#include "fuego.h"
Fuego :: Fuego(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

}

string Fuego ::getElemento(){

    string element = "fuego";
    return element;
}
void Fuego :: alimentarse() {

    if(verificarVida()){
        vida = vida + 5;
        energia = energia + 10;
        imprimirAlimentos();
    }else
        cout << "ERROR EL PERSONAJE DE FUEGO NO SE PUDO ALIMENTAR ENERGIA O VIDA YA SOM SUFICIENTES " << endl;

}

bool Fuego::verificarVida() {

    return (vida + 5 <= VMAX && energia + 10 <= EMAX );
}

void Fuego :: imprimirAlimentos(){

    cout << "SE ALIMENTO AL PERSONAJE DE FUEGO : " << nombre << " CON MADERA Y RECUPERO 5 PUNTOS DE VIDA y 10 DE ENERGIA ,AHORA TIENE " << vida  << endl;
}

bool Fuego ::energiaAtaque() {
    if (energia >= 5)
        restarEnergia(5);
    return energia >= 5;
}

bool Fuego :: energiaDefensa() {

    if(energia >= 10)
        restarEnergia(10);
    return energia >= 10;
}

int Fuego ::danoAtaque(Personaje *personajeAtacar) {

    if(personajeAtacar -> getElemento() == "aire")
        return 30;
    else if(personajeAtacar -> getElemento() == "agua")
       return 10;
    else
       return 20;

}

bool Fuego ::comprobarFilas(int filaAtaque, int filaAtacar) {

    int diferenciaFilas = filaAtaque - filaAtacar;
    return (diferenciaFilas <= 1 && diferenciaFilas >= -1);
}

int Fuego :: atacar (Personaje* personajeAtacado) {

      if(comprobarFilas(personajeAtacado -> obtenerFila(), personajeAtacado -> obtenerColumna()))
           return danoAtaque(personajeAtacado);
      else
          return 0;
}

Fuego ::~Fuego() {

}