#include "fuego.h"
Fuego :: Fuego(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

}
void Fuego :: alimentarse() {

    if(verificarVida()){
        vida = vida + 15;
        imprimirAlimentos();
    }else
        cout << "ERROR YA EL PERSONAJE TIENE LA VIDA SUFICIENTE " << endl;

}

bool Fuego::verificarVida() {

    return (vida + 15 <= VMAX);
}

void Fuego :: imprimirAlimentos(){
        cout << "SE ALIMENTO AL PERSONAJE DE FUEGO : " << nombre << " CON MADERA Y RECUPERO 15 PUNTOS DE VIDA ,AHORA TIENE " << vida  << endl;
}

void Fuego ::mostrarPersonajeEspecifico() {
    cout << "ELEMENTO :" << " FUEGO" << endl;
   mostrarPersonaje();
}
Fuego ::~Fuego() {

}
