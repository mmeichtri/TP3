//
// Created by jose on 2/2/21.
//

#include "tierra.h"
Tierra :: Tierra(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){
 escudoInicial = escudo;
}
string Tierra ::getElemento() {
    string element = "tierra";
    return element;
}

void Tierra::alimentarse() {

    if(verificarEnergia()){
        energia = energia + 8;
        imprimirAlimentos();
    }else
        cout << "ERROR EL PERSONAJE YA TIENE ENERGIA SUFICIENTE "<<endl;
}

bool Tierra::verificarEnergia() {

    return ( energia + 8 <= EMAX);
}

void Tierra :: imprimirAlimentos(){

    cout << "SE ALIMENTO AL PERSONAJE DE TIERRA : "  << nombre << " CON HIERBAS y AUMENTO 8 PUNTOS DE ENERGIA, AHORA SU ENERGIA ES "<< energia << endl;

}
bool Tierra :: energiaAtaque() {

      return energia >= 6;
}

bool Tierra ::energiaDefensa() {

    return energia >= 5;
}

int Tierra ::danoAtaque(int valorAtaque, Personaje *personajeAtacar) {

    if(personajeAtacar -> getElemento() == "aire")
        valorAtaque = 10;
    else if(personajeAtacar -> getElemento() == "agua")
        valorAtaque = valorAtaque + 20;
    return valorAtaque;
}


int Tierra ::danoPorRango(int filaAtacar, int columnaAtacar, int filaAtacado, int columnaAtacado) {

    int diferenciaFilas = filaAtacar-filaAtacado;
    int diferenciaColumnas = columnaAtacar-columnaAtacado;

    if(diferenciaFilas <= 2 && diferenciaFilas >= -2 )
         return condicionRangoDos(diferenciaColumnas);
    else if(diferenciaFilas <= 4 && diferenciaFilas >= -4)
        return condicionRangoCuatro(diferenciaColumnas);
    else
         return 10;
}

int Tierra ::condicionRangoDos(int diferenciaCol) {

    if(diferenciaCol <= 2 && diferenciaCol >= -2)
          return 30;
      else if(diferenciaCol <= 4 && diferenciaCol >= -4)
          return 20;
      else
          return 10;
}

int Tierra ::condicionRangoCuatro(int diferenciaCol) {
    if(diferenciaCol <= 4 && diferenciaCol >= -4)
        return 20;
    else
        return 10;
}

void Tierra :: atacar(Personaje** personajeAtacado ){

    for(int i = 0; i < MAXRIVALES ; i++){
        if(personajeAtacado[i] != nullptr){
            int danoRango = danoPorRango(fila,columna,personajeAtacado[i]->obtenerFila(),personajeAtacado[i]->obtenerColumna());
            int dano = danoAtaque(danoRango,personajeAtacado[i]);
            quitarVidaPersonaje(personajeAtacado[i],dano);
        }

    }
}


void Tierra ::modificarPorTurno() {
    if(escudoInicial != escudo)
        escudo = escudoInicial;
}

Tierra ::~Tierra() {

}
