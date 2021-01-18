#include "nodoJugador.h"

NodoJugador::NodoJugador(Jugador* d) {
    dato = d;
    siguiente = 0;
}

void NodoJugador::cambiar_siguiente(NodoJugador* s) {
    siguiente = s;
}

Jugador* NodoJugador::obtener_dato() {
    return dato;
}

NodoJugador* NodoJugador::obtener_siguiente() {
    return siguiente;
}
