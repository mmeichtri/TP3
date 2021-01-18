#ifndef FUEGO_H_INCLUDED
#define FUEGO_H_INCLUDED

#include "personajes.h"

class Fuego : public Personajes
{
private:
    //atributos
    string elemento;
    string alimento;
public:
    //metodos
    //constructor
    Fuego(string n,int v,int e,int en,string el,string al);

    //pre:-
    //post:alimenta al personaje y en este caso le otorga 15 puntos de vida.
    void alimentarse();

    //pre:-
    //post: devuelve el nombre del personaje.
    string getNombre();

    //pre:-
    //post:devuelve el alimento del personaje.
    string getAlimento();

    //pre:-
    //post:devuelve el elemento del personaje.
    string getElemento();

    //pre:-
    //post:devuelve la vida del personaje si esta se encuentra entre 10 y 100 inclusive, de ser menor a 10 devuelve 10 y de ser mayor a 100 devuelve 100.
    int verificarVida(int v);
};


#endif // FUEGO_H_INCLUDED
