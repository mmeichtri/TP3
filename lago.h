#ifndef LAGO_H_INCLUDED
#define LAGO_H_INCLUDED
#include "casillero.h"
#include "personaje.h"
class Lago : public Casillero{
private:

public:
    /*
    pre:
    post:
    */
    Lago(int, int );

    /*
    pre: si existe un personaje...
    post: valida el elemento del personaje, y resta la energia, segun corresponda
    */
    int restarGastoDeEnergia(Personaje* );

    ~Lago();
};

#endif // LAGO_H_INCLUDED
