#include "nodo.h"

Nodo::Nodo(Personaje* d) {
    dato = d;
    siguiente = nullptr;
}

void Nodo::cambiar_siguiente(Nodo* s) {
    siguiente = s;
}

Personaje* Nodo::obtener_dato() {
    return dato;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}
