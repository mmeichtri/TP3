#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>
#include "personajes.h"

using namespace std;

//se define a Dato como un tipo de puntero a Personajes
typedef Personajes* Dato;

class Nodo {
private:
    // atributos
    Dato dato;
    Nodo* siguiente;
    Nodo* anterior;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato = d y siguiente = 0
    Nodo(Dato d);

    //pre:-
    //post: recibe un dato como parametro y lo reemplaza por el dato almacenado actual.
    void cambiarDato(Dato d);

    //pre:-
    //post:cambia el puntero del nodo al siguiente, es decir saltea un elemento.
    void cambiarSiguiente(Nodo* s);

    //pre:-
    //post: devuelve un dato de tipo Dato.
    Dato obtenerDato();

    //pre:-
    //post: devuelve el siguiente dato.
    Nodo* obtenerSiguiente();
};
#endif // NODO_H_INCLUDED
