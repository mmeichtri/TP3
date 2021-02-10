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
    pre: si fila >=0 || fila < 64
    post: guarda la fila
    */
    void setFila(int );

    /*
    pre: si columna >=0 || columna < 64
    post: guarda la columna
    */
    void setColumna(int );

        /*
    pre:
    post: devuelve la fila
    */
    int getFila();

    /*
    pre:
    post: devuelve la columna
    */
    int getColumna();


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
    post: retorna el elemento
    */
    std::string getElemento();

    /*
    pre:
    post: destruye el objeto
    */
    ~Tierra();
};

#endif // TIERRA_H_INCLUDED
