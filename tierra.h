#ifndef TIERRA_H_INCLUDED
#define TIERRA_H_INCLUDED

#include "personajes.h"

class Tierra : public Personajes
{
private:
    //atributos

    string elemento;
    string alimento;

public:
    //metodos
    //constructor
    Tierra(string n,int v,int e,int en,string el,string al);

    //pre:-
    //post:alimenta al personaje en este caso de Tierra el cual recibe 8 de energia al alimentarse
    void alimentarse();

    //pre:-
    //post:devuelve el nombre del personaje.
    string getNombre();

    //pre:-
    //post: devuelve el alimento del personaje.
    string getAlimento();

    //pre:-
    //post:devuelve el elemento del personaje.
    string getElemento();

    //pre:-
    //post: verifica que la energia se encuentre entre 0 y 20, si este es el caso la devuelve como fue ingresada de ser menor a 0 devuelve 0 y de ser mayor a 20 devuelve 20.
    int verificarEnergia(int e);
};



#endif // TIERRA_H_INCLUDED
