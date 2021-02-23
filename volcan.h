#ifndef VOLCAN_H_INCLUDED
#define VOLCAN_H_INCLUDED
#include "casillero.h"
#include "personaje.h"
class Volcan : public Casillero{
private:

public:
    /*
    pre:
    post:
    */
    Volcan(int, int );

    /*
    pre: si existe un personaje...
    post: valida el elemento del personaje, y retorna lo que cuesta pasar por esa casilla , segun corresponda
    */
    int restarGastoDeEnergia(Personaje* );

    ~Volcan();
};


#endif // VOLCAN_H_INCLUDED
