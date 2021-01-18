#ifndef AGUA_H_INCLUDED
#define AGUA_H_INCLUDED
#include "personaje.h"

class Agua : public Personaje{
private:
    int cantidadAlimentaciones = 0;
public:
    /*
    pre:
    post: crea un objeto del tipo Agua
    */
    Agua(std::string, int, int );

    /*
    pre: si this->energia < 20 && this->energia + 10 < 20
    post: alimenta el personaje indicado
    */
    void alimentar(std::string );

    /*
    pre:
    post: devuelve la energia actual del personaje asociado al tipo Agua
    */
    int mostrarEnergiaActual();

    /*
    pre:
    post: destruye el objeto
    */
    ~Agua();
};

#endif // AGUA_H_INCLUDED
