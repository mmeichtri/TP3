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
    post: retorna el elemento
    */
    std::string getElemento();

    /*
    pre:
    post: destruye el objeto
    */
    ~Aire();
};

#endif // AIRE_H_INCLUDED
