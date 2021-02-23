#ifndef PRECIPICIO_H_INCLUDED
#define PRECIPICIO_H_INCLUDED
#include "casillero.h"
#include "personaje.h"
class Precipicio : public Casillero{
private:

public:
    /*
    pre:
    post:
    */
    Precipicio(int, int );

    /*
   pre: si existe un personaje...
   post: valida el elemento del personaje, y retorna lo que cuesta pasar por esa casilla , segun corresponda
   */
    int restarGastoDeEnergia(Personaje* );

    ~Precipicio();
};


#endif // PRECIPICIO_H_INCLUDED
