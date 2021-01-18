#ifndef AGUA_H_INCLUDED
#define AGUA_H_INCLUDED

#include "personajes.h"

using namespace std;

class Agua : public Personajes{
    private:
        //atributos

        string elemento;
        string alimento;
        int cantAlimentacion;

    public:

        //metodos
        //constructor
        Agua(string n,int v,int e,int en,int cant,string el,string al);

        //pre:-
        //post:alimenta al personaje de clase derivada agua, este personaje recibe 15 de energia al alimentarse.
        void alimentarse();

        //pre:-
        //post:devuelve el alimento del personaje.
        string getAlimento();

        //pre:-
        //post: devuele el elemento del personaje.
        string getElemento();

        //pre:-
        //post: devuelve la energia del personaje si se encuentra entro 0 y 20, si la energia es menor a 0 devuelve 0 y si es mayor a 20 devuelve 20.
        int verificarEnergia(int e);
};


#endif // AGUA_H_INCLUDED
