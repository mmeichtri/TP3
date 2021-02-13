#include <iostream>
#include "agua.h"
#include "aire.h"
#include"personaje.h"
#include "tierra.h"
#include "fuego.h"
#include "juego.h"
#include "grafo.h"
#include "matriz.h"
#include "archivo.h"

using namespace std;


int main() {
    srand(time(nullptr));
   Juego iu;
   Matriz tablero;
   grafo graf;
   Archivo arch;
   arch.leerArchivo(&tablero,&graf);
   tablero.pasarAdyacencia(&graf);

    Aire air1("loco",1,100);
    Fuego fire1("el llamas",2,100);
    Agua water1("eldelfin77",0,100);
    Fuego fire("juan",0,100);
    Agua water("maria",0,100);
    Aire air("Juana",0,100);
    Tierra earth("Juan",0,100);
    fire.cambiarFYC(1,1);
    fire1.cambiarFYC(0,1);
    air1.cambiarFYC(1,0);
    water1.cambiarFYC(2,1);
    air.cambiarFYC(1,2);
    water.cambiarFYC(1,3);
    earth.cambiarFYC(0,0);
    Personaje* vector[3];
    Personaje* vector1[3];
    vector[0] = &fire;
    vector[1] = &air;
    vector[2] = &water;
    vector1[0] = &water1;
    vector1[1] = &air1;
    vector1[2] = &fire1;
iu.moverse(&graf,vector[0]);

    return 0;
}