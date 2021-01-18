#include "nodo.h"

Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

void Nodo::cambiarDato(Dato d) {
    dato = d;
}

void Nodo::cambiarSiguiente(Nodo* s) {
    siguiente = s;
}

Dato Nodo::obtenerDato() {
    return dato;
}

Nodo* Nodo::obtenerSiguiente() {
    return siguiente;
}
