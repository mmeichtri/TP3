#include "aire.h"

Aire :: Aire(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

}
void Aire:: alimentarse() {
    cout << "LOS PERSONAJES DE AIRE NO SE ALIMENTAN " << endl;
}
void Aire::mostrarPersonajeEspecifico() {
    cout << "ELEMENTO: " << " AIRE" << endl;
    mostrarPersonaje();
}
Aire ::~Aire() {

}
