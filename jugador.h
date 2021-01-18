#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "listaJugador.h"
#include "nodoJugador.h"
#include <string>
class ListaJugador;
class NodoJugador;

class Jugador{
private:
    ListaJugador* jugadores;
    std::string nombreJugador;
public:
    /*
    pre:
    post: recibe un nombre, y crea un nuevo objeto de la clase Jugador
    */
    Jugador(std::string );

    /*
    pre;
    post: devuelve el nombre del jugador
    */
    std::string getNombre();

};

#endif // JUGADOR_H_INCLUDED
