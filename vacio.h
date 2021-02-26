#ifndef VACIO_H_INCLUDED
#define VACIO_H_INCLUDED
#include "casillero.h"
#include "personaje.h"
class Vacio : public Casillero{
private:

public:
    /*
    pre:
    post:
    */
    Vacio(int, int );

    /*
   pre: si existe un personaje...
   post: valida el elemento del personaje, y retorna lo que cuesta pasar por esa casilla , segun corresponda
   */
    int restarGastoDeEnergia(Personaje* );

//    void ImprimirCasilla(string nombre);

    ~Vacio();
};


#endif // VACIO_H_INCLUDED
