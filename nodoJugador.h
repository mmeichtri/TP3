#ifndef NODOJUGADOR_H_INCLUDED
#define NODOJUGADOR_H_INCLUDED
#include "jugador.h"
#include <string>

class Jugador;

class NodoJugador{
private:
    // atributos
    Jugador* dato;
    NodoJugador* siguiente;
    NodoJugador* anterior;

public:

    // PRE:
    // POS: crea un nodo con Personaje* = d y siguiente = 0
    NodoJugador(Jugador* d);

    /*
    PRE:
    POST:
    */
    void cambiar_siguiente(NodoJugador* s);

    /*
    PRE:
    POST:
    */
    Jugador* obtener_dato();

    /*
    PRE:
    POST:
    */
    NodoJugador* obtener_siguiente();

};

#endif // NODOJUGADOR_H_INCLUDED
