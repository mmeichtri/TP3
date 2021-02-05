#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include "casillero.h"
#include "personaje.h"
class Camino : public Casillero{
private:

public:
    /*
    pre:
    post:
    */
    Camino(int, int );

    /*
    pre: si existe un personaje...
    post: valida el elemento del personaje, y resta la energia, segun corresponda
    */
    void restarGastoDeEnergia(Personaje* );

    ~Camino();
};


#endif // CAMINO_H_INCLUDED
