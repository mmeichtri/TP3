#ifndef FUEGO_H_INCLUDED
#define FUEGO_H_INCLUDED
#include "personaje.h"

class Fuego : public Personaje{
public:
    /*
    pre:
    post: crea un objeto del tipo Fuego
    */
    Fuego(std::string, int, int );

    /*
    pre: si this->energia < 20 && this->energia + 15 < 20
    post: alimenta el personaje indicado
    */
    void alimentar(std::string );

    /*
    pre:
    post: devuelve la energia actual del personaje asociado al tipo Fuego
    */
    int mostrarEnergiaActual();

    /*
    pre:
    post: retorna el elemento
    */
    std::string getElemento();

    /*
    pre:
    post: destruye el objeto
    */
    ~Fuego();
};

#endif // FUEGO_H_INCLUDED
