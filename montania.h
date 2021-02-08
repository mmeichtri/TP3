#ifndef MONTANIA_H_INCLUDED
#define MONTANIA_H_INCLUDED
#include "casillero.h"
#include "personaje.h"
class Montania : public Casillero{
private:

public:
    /*
    pre:
    post:
    */
    Montania(int, int );

    /*
    pre: si existe un personaje...
    post: valida el elemento del personaje, y resta la energia, segun corresponda
    */
    int restarGastoDeEnergia(Personaje* );

    ~Montania();
};


#endif // MONTANIA_H_INCLUDED
