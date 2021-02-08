#include <iostream>
#include "agua.h"
#include "aire.h"
#include"personaje.h"
#include "tierra.h"
#include "fuego.h"
#include "juego.h"

using namespace std;


int main() {
   Juego iu;
    Aire air1("loco",1,100);
    Fuego fire1("el llamas",2,100);
    Agua water1("eldelfin77",0,100);
    Fuego fire("juan",0,80);
    Agua water("maria",0,90);
    Aire air("Juana",0,100);
    Tierra earth("Juan",0,100);
    fire.cambiarFYC(1,1);
    fire1.cambiarFYC(0,1);
    air1.cambiarFYC(1,0);
    water1.cambiarFYC(2,1);
    air.cambiarFYC(7,2);
    water.cambiarFYC(2,0);
    earth.cambiarFYC(0,0);
    Personaje* vector[3];
    Personaje* vector1[3];
    vector[0] = &fire;
    vector[1] = &air;
    vector[2] = &water;
    vector1[0] = &water1;
    vector1[1] = &air1;
    vector1[2] = &fire1;
    iu.jugar(vector,vector1);

    return 0;
}
