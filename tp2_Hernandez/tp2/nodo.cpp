#include "nodo.h"

Nodo :: Nodo(Personaje* dato){
    this -> dato = dato;
    siguiente = 0;
}

void Nodo :: cambiarSiguiente(Nodo* sig) {
    this -> siguiente = sig;
}

Nodo* Nodo ::obtenerSiguiente() {
    return siguiente;
}

Personaje* Nodo ::obtenerDato() {
    return dato;
}
Nodo ::~Nodo(){
    delete dato;
}
