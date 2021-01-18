#ifndef NODO_H
#define NODO_H
#include "personaje.h"
#include "cstdlib"

class Nodo {

private:
    Personaje* dato;
    Nodo* siguiente;
public:
    // PRE: PUNTERO A UN PERSONAJE VALIDO.
    // POST: CREA UN NODO CON dato VALIDO Y siguiente APUNTANDO A NULL.
    Nodo(Personaje* dato);

    //PRE:
    //POST: DEVUELVE LA DIRECCION AL SIGUIENTE NODO.
    Nodo* obtenerSiguiente();

    //PRE:
    //POST: DEVUELVE LA DIRECCION EN MEMORIA DEL PERSONAJE.
    Personaje* obtenerDato();

    // PRE: RECIBE UN PUNTERO A UN NODO VALIDO.
    // POST: EL NODO AHORA APUNTA A LA DIRECCION PASADA POR PARAMETRO.
    void cambiarSiguiente(Nodo* sig);

    //Pre:
    //Post:ELIMINA UN DATO DINAMICO, DESTRUYE UN NODO.
    ~Nodo();
};


#endif // NODO_H
