#ifndef AGUA_H_INCLUDED
#define AGUA_H_INCLUDED
#include <string>
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
    post: devuelve el tipo de elemento
    */
    std::string getElemento();

    /*
    pre:
    post: destruye el objeto
    */
    ~Agua();
};


#endif // AGUA_H_INCLUDED
