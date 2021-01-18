#ifndef AIRE_H_INCLUDED
#define AIRE_H_INCLUDED

#include "personajes.h"

class Aire : public Personajes
{
private:
    //atributos
    string elemento;
public:
    //metodos

    //constructor
    Aire(string n,int v,int e,int en,string el);

    //pre:-
    //post: alimenta al personaje que es de clase derivada aire, esta clase no se alimenta por lo que imprime por pantalla que este personaje no se alimenta.
    void alimentarse();

    //pre:-
    //post: devuelve el nombre del personaje.
    string getNombre();

    //pre:-
    //post: devuelve el alimento del personaje.
    string getAlimento();

    //pre:-
    //post: devuelve el elemento del personaje.
    string getElemento();

};

#endif // AIRE_H_INCLUDED
