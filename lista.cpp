#include "lista.h"

Lista::Lista() {
    primero = 0;
    actual = 0;
    cantidad = 0;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (pos == 1) {
        nuevo->cambiarSiguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else {
        Nodo* anterior = obtenerNodo(pos - 1);
        Nodo* siguiente = anterior->obtenerSiguiente();
        nuevo->cambiarSiguiente(siguiente);
        anterior->cambiarSiguiente(nuevo);
    }
    cantidad++;
}

Nodo* Lista::obtenerNodo(int pos) {
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtenerSiguiente();
    return aux;
}

Dato Lista::consulta(int pos) {
    Nodo* aux = obtenerNodo(pos);
    return aux->obtenerDato();
}

void Lista::baja(int pos) {
    Nodo* borrar;
    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtenerSiguiente();
    }
    else {
        Nodo* anterior = obtenerNodo(pos - 1);
        borrar = anterior->obtenerSiguiente();
        Nodo* siguiente = borrar->obtenerSiguiente();
        anterior->cambiarSiguiente(siguiente);
    }
    reiniciar();
    delete borrar;
    cantidad--;
}

Lista::~Lista()  {
    while (! vacia())
        baja(1);
}

int Lista::obtenerCantidad()  {
    return cantidad;
}

void Lista::reiniciar() {
    actual = primero;
}

bool Lista::haySiguiente() {
    return (actual != 0);
}

Dato Lista::siguiente() {
    Nodo* aux = actual;
    actual = actual->obtenerSiguiente();
    return aux->obtenerDato();
}

bool Lista::esta(Dato d) {
    bool encontrado = false;
    reiniciar();
    while (haySiguiente() && ! encontrado) {
        if (siguiente() == d)
            encontrado = true;
    }
    return encontrado;
}


