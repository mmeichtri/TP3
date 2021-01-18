#include "listaJugador.h"
#include "jugador.h"
#include "nodoJugador.h"

ListaJugador::ListaJugador() {
    primero = 0;
    actual = 0;
    cantidad = 0;
}

bool ListaJugador::vacia() {
    return (cantidad == 0);
}

void ListaJugador::alta(Jugador* d, int pos) {
    NodoJugador* nuevo = new NodoJugador(d);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else {
        NodoJugador* anterior = obtener_nodo(pos - 1);
        NodoJugador* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

NodoJugador* ListaJugador::obtener_nodo(int pos) {
    NodoJugador* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

Jugador* ListaJugador::consulta(int pos) {
    NodoJugador* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void ListaJugador::baja(int pos) {
    NodoJugador* borrar;
    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else {
        NodoJugador* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        NodoJugador* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    reiniciar();
    delete borrar;
    cantidad--;
}

ListaJugador::~ListaJugador()  {
    while (!vacia())
        baja(1);
}

int ListaJugador::obtener_cantidad()  {
    return cantidad;
}

void ListaJugador::reiniciar() {
    actual = primero;
}

bool ListaJugador::hay_siguiente() {
    return (actual != 0);
}

Jugador* ListaJugador::siguiente() {
    NodoJugador* aux = actual;
    actual = actual->obtener_siguiente();
    return aux->obtener_dato();
}

bool ListaJugador::esta(Jugador* d) {
    bool encontrado = false;
    reiniciar();
    while (hay_siguiente() && ! encontrado) {
        if (siguiente() == d)
            encontrado = true;
    }
    return encontrado;
}
