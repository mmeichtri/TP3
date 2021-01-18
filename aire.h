#ifndef AIRE_H_INCLUDED
#define AIRE_H_INCLUDED
#include "personaje.h"

class Aire : public Personaje{
public:
    /*
    pre:
    post: crea un objeto del tipo Aire
    */
    Aire(std::string, int, int );

    /*
    pre: si el nombre del personaje, se encuentra en la lista
    post: alimenta el personaje indicado
    */
    void alimentar(std::string );

    /*
    pre:
    post:devuelve la energia actual del personaje asociado al tipo Aire
    */
    int mostrarEnergiaActual();

    /*
    pre:
    post: destruye el objeto
    */
    ~Aire();
};

#endif // AIRE_H_INCLUDED
