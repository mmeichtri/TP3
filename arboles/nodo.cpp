

#include "nodo.h"
nodo ::nodo(DATO clave, nodo *papa) {
    this -> clave = clave;

    this -> papa = papa;
    derecho = nullptr;
    izq = nullptr;
}
void nodo::setClave(DATO clave) {
    this -> clave = clave;
}

void nodo ::setIzq(nodo *izq) {
    this -> izq = izq;
}

void nodo::setDerecho(nodo *derecho) {
    this -> derecho = derecho;
}

void nodo ::setPadre(nodo* papa) {
    this -> papa = papa;
}

nodo* nodo ::getPadre() {
    return papa;
}
nodo* nodo ::getDerecho() {
    return derecho;
}

nodo* nodo::getIzq() {
    return izq;
}

DATO nodo ::getClave() {
    return clave;
}
