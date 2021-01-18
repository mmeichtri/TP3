#ifndef TIERRA_H_INCLUDED
#define TIERRA_H_INCLUDED
#include "personaje.h"

class Tierra : public Personaje{
public:
    /*
    pre:
    post: crea un objeto del tipo Tierra
    */
    Tierra(std::string, int, int );

    /*
    pre: si this->energia < 20 && this->energia + 8 < 20
    post: alimenta el personaje indicado
    */
    void alimentar(std::string );

    /*
    pre:
    post: devuelve la energia actual asociado al personaje de tipo Tierra
    */
    int mostrarEnergiaActual();

    /*
    pre:
    post: destruye el objeto
    */
    ~Tierra();
};

#endif // TIERRA_H_INCLUDED
