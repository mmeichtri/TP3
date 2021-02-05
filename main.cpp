#include <iostream>
#include "agua.h"
#include "aire.h"
#include"personaje.h"
#include "tierra.h"
#include "fuego.h"


int visualFila(){
    int fila;
    cout << "INGRESE FILA :" << endl;
    cin >> fila;
   return fila;
}
int visualColumna(){
    int fila;
    cout << "INGRESE COLUMNA :" << endl;
    cin >> fila;
    return fila;
}

bool casillaNoOcupada(bool desicion){
    if(desicion == false)
        cout << "ERROR NO HAY UN PERSONAJE EN LA CASILLA QUE INGRESO POR PANTALLA " << endl;
    return desicion;
}



void ataquePersonajeAgua(Personaje* atacante, Personaje* victimas[3]){

    int fila , columna , i = 0 , ataque;
    bool encontrado = false;
    fila = visualFila();
    columna = visualColumna();
    while(i < 3 && !encontrado){

        if(victimas[i] -> obtenerFila() == fila && victimas[i] -> obtenerColumna() == columna){
            encontrado = true;
            ataque = atacante -> atacar(victimas[i]);
            victimas[i] -> modificarVida(victimas[i] -> obtenerVida() - victimas[i] -> defensaEscudo(ataque));
        }
        i++;
    }
    casillaNoOcupada(encontrado);

}



void ataquePersonajes(Personaje* atacante , Personaje* victimas[3]){

    int ataque;
    for(int i = 0; i< 3 ;i++){
        ataque = atacante -> atacar(victimas[i]);
       victimas[i] -> modificarVida(victimas[i] -> obtenerVida() - victimas[i] -> defensaEscudo(ataque));
    }


}

void atacarPersonaje(Personaje* atacante, Personaje* victimas[3]){

    if(atacante -> energiaAtaque()){
        if(atacante -> elemento() == "AGUA")
            ataquePersonajeAgua(atacante , victimas);
        else
            ataquePersonajes(atacante,victimas);
    }

    else
        cout << "ERROR EL PERSONAJE NO TIENE LA ENERGIA SUFICIENTE PARA ATACAR" << endl;
}



int main() {

  Fuego fire("juan",0,80);
  Agua water("maria",0,90);
  Aire air("Juana",0,100);
  Tierra earth("Juan",0,100);
  fire.cambiarFYC(1,1);
  air.cambiarFYC(7,2);
  water.cambiarFYC(2,0);
  earth.cambiarFYC(0,0);
  Personaje* vector[3];
  vector[0] = &fire;
  vector[1] = &air;
  vector[2] = &water;




  atacarPersonaje(&earth,vector);



    return 0;
}
