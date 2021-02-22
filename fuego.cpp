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

    return energia >= 5;

}

bool Fuego :: energiaDefensa() {

    bool tieneEnergia = energia >= 10;
    if(tieneEnergia ){
        restarEnergia(10);
    }
    return tieneEnergia;
}

void Fuego::modificarPorTurno() {
    if(energia == 0)
        restarVida(5);
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


void Fuego :: atacar (Personaje** personajeAtacado) {

    restarEnergia(5);

      for(int i = 0; i < MAXRIVALES ; i++){
          if(personajeAtacado[i] != nullptr){
              if(comprobarFilas(fila,personajeAtacado[i]->obtenerFila())){
              int dano = danoAtaque(personajeAtacado[i]);
              quitarVidaPersonaje(personajeAtacado[i],dano);
                }
          }
      }
}

Fuego ::~Fuego() {

}