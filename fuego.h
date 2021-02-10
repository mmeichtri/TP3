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

<<<<<<< HEAD
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


=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
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
