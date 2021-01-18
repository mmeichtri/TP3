#ifndef PERSONAJE_H
#define PERSONAJE_H


#include <string>
#include <iostream>
#include "random"
using namespace std;

const int EMAX = 20;
const int VMAX = 100;


class Personaje {
protected:
    string nombre;
    int escudo;
    int vida;
    int energia;

public:
    /* PRE : NOMBRE VALIDO DE TIPO ALFANUMERICO, ESCUDO CON VALOR DE TIPO ENTERO ENTRE 0 A 2
     * Y VIDA CON VALOR TIPO ENTERO ENTRE 10 A 100.*/
    /* POST: CONSTRUYE UN OBJETO DE CLASE Personaje, ASIGNANDOLE UN VALOR DE ENERGIA ALEATORIO
     * DENTRO DEL RANGO ESTABLECIDO.*/
    Personaje(string nombre,int escudo,int vida);

    // PRE:
    // POST: METODO VIRTUAL DE LA CLASE PERSONAJE
    virtual void alimentarse() = 0;

    // PRE:
    // POST: METODO VIRTUAL DE UN PERSONAJE.
    virtual void mostrarPersonajeEspecifico() = 0;

    //PRE:
    //POST: IMPRIME EL NOMBRE,ESCUDO,VIDA Y ENERGIA DE UN PERSONAJE.
    void mostrarPersonaje();
    // PRE:
    // POST: IMPRIME EL NOMBRE DE UN PERSONAJE.
    void mostrarNombre();

    // PRE:
    // POST: DEVUELVE EL VALOR STRING NOMBRE DE UN PERSONAJE.
    string obtenerNombre();

    virtual ~Personaje() {;}

};

#endif // PERSONAJE_H
