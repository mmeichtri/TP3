//
// Created by jose on 2/2/21.
//

#include "tierra.h"
Tierra :: Tierra(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

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


    if(diferenciaFilas <= 2 && diferenciaFilas >= -2 ){
      if(diferenciaColumnas <= 2 && diferenciaColumnas >= -2)
          return 30;
      else if(diferenciaColumnas <= 4 && diferenciaColumnas >= -4)
          return 20;
      else
          return 10;
    }
    else if(diferenciaFilas <= 4 && diferenciaFilas >= -4){
        if(diferenciaColumnas <= 4 && diferenciaColumnas >= -4)
            return 20;
        else
            return 10;
    }
    else
         return 10;
}

int Tierra :: atacar(Personaje* personajeAtacado ){

        int danoTotal;
        danoTotal = danoPorRango(fila,columna,personajeAtacado -> obtenerFila(),personajeAtacado -> obtenerColumna());
        danoTotal = danoAtaque(danoTotal, personajeAtacado);
        return danoTotal;
}

void Tierra :: defenderse() {

   energia = energia - 5;



}



Tierra ::~Tierra() {

}