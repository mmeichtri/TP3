#include "tierra.h"
Tierra :: Tierra(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

}

void Tierra::alimentarse() {

    if(verificarEnergia()){
        energia = energia + 8;
        imprimirAlimentos();
    }else
        cout << "ERROR YA EL PERSONAJE TIENE LA ENERGIA SUFICIENTE "<<endl;
}

bool Tierra::verificarEnergia() {

    return ( energia + 8 <= EMAX);
}

void Tierra :: imprimirAlimentos(){

    cout << "SE ALIMENTO AL PERSONAJE DE TIERRA : "  << nombre << " CON HIERBAS y AUMENTO 8 PUNTOS DE ENERGIA, AHORA SU ENERGIA ES "<< energia << endl;

}
void Tierra :: mostrarPersonajeEspecifico() {

    cout << "ELEMENTO: " << " TIERRA" << endl;
    mostrarPersonaje();

}
Tierra ::~Tierra() {

}
