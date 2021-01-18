#include "lista.h"
#include "personaje.h"
#include "nodo.h"
#include "juego.h"
#include <iostream>

using namespace std;

Lista::Lista() {
    primero = 0;
    actual = 0;
    cantidad = 0;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

void Lista::alta(Personaje* d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

Personaje* Lista::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista::baja(int pos) {
    Nodo* borrar;
    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    reiniciar();
    delete borrar;
    cantidad--;
}

void Lista::bajaPorNombre(Lista* listaPersonajes, int pos){
    Nodo* borrar;
    Nodo* siguiente;
    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else{
        Nodo* nodoAnterior = listaPersonajes->obtener_nodo(pos - 1);
        borrar = nodoAnterior->obtener_siguiente();
        siguiente = borrar->obtener_siguiente();
        nodoAnterior->cambiar_siguiente(siguiente);
    }
    reiniciar();
    delete borrar;
    this->cantidad--;
}

Lista::~Lista()  {
    while (!vacia())
        baja(1);
}

int Lista::obtener_cantidad()  {
    return cantidad;
}

void Lista::reiniciar() {
    actual = primero;
}

bool Lista::hay_siguiente() {
    return (actual != 0);
}

Personaje* Lista::siguiente() {
    Nodo* aux = actual;
    actual = actual->obtener_siguiente();
    return aux->obtener_dato();
}

bool Lista::esta(Personaje* d) {
    bool encontrado = false;
    reiniciar();
    while (hay_siguiente() && ! encontrado) {
        if (siguiente() == d)
            encontrado = true;
    }
    return encontrado;
}


