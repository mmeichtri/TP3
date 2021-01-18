#include <iostream>
#include "cola.h"

Cola::Cola() {
    primero = 0;
    ultimo = 0;
}

void Cola::alta(Dato d) {
    Nodo* nuevo = new Nodo(d);
    if (vacia())
        primero = nuevo;
    else
        ultimo->cambiarSiguiente(nuevo);
    ultimo = nuevo;
}

void Cola::baja() {
    Nodo* borrar = primero;
    primero = borrar->obtenerSiguiente();
    if (! primero)
        ultimo = 0;
    delete borrar;
}

Dato Cola::consulta() {
    return primero->obtenerDato();
}

bool Cola::vacia() {
    return (ultimo == 0);
}

Cola::~Cola() {
    std::cout << "Estoy ejecutando el destructor " << std::endl;
    while (! vacia())
        baja();
}

