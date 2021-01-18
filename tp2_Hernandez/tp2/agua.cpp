#include "agua.h"

Agua :: Agua(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){
      contarComida = 0;
}

void Agua :: alimentarse() {

    if(verificarEnergia()){
        contarComida++;
        energia = energia + 10;
        imprimirAlimentos();
    }
    else
        cout << "ERROR NO SE PUDO ALIMENTAR AL PERSONAJE" << endl;
}

bool Agua ::verificarEnergia() {

   return ((energia + 10 <= EMAX ) && (contarComida < 3));

}

void Agua :: imprimirAlimentos() {

    cout << "SE ALIMENTO AL PERSONAJE DE AGUA : " << nombre << " CON PLACTON Y RECUPERO 10 PUNTOS DE ENERGIA AHORA TIENE  "<< energia << endl;
}

void Agua ::mostrarPersonajeEspecifico() {
    cout << "ELEMENTO: "<< " AGUA " << endl;
    mostrarPersonaje();
}

Agua::~Agua() {

}

