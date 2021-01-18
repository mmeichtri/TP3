#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "personaje.h"
#include <string>

class Personaje;

class Nodo{
private:
    // atributos
    Personaje* dato;
    Nodo* siguiente;
    Nodo* anterior;

public:

    // PRE:
    // POS: crea un nodo con Personaje* = d y siguiente = 0
    Nodo(Personaje* d);

    /*
    PRE:
    POST:
    */
    void cambiar_siguiente(Nodo* s);

    /*
    PRE:
    POST:
    */
    Personaje* obtener_dato();

    /*
    PRE:
    POST:
    */
    Nodo* obtener_siguiente();

};

#endif // NODO_H_INCLUDED
