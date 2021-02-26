#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED
#include <string.h>
#include "personaje.h"
#define NC "\e[0m"
#define RED "\e[30;41m"
#define GRN "\e[30;42m"
#define YLW "\e[1;30;43m"
#define BLU "\e[30;44m"
#define PUR "\e[30;45m"
#define CYN "\e[30;46m"
#define REDB "\e[41m"
#define GRY "\e[30;47m"

class Casillero{
protected:
    int fila;
    int columna;
    bool hayPersonaje = false ;
    std::string tipo;

public:

    /*
    pre:
    post:
    */
    Casillero(int, int );

    /*
    pre:
    post: devuelve el tipo asociado al casillero
    */
    std::string getTipo();

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
    pre:
    post: devuelve el peso
    */
    int devolverPeso(std::string );

    /*
    pre:
    post: segun el tipo de elemento, y tipo de casillero, resta la energia correspondiente
    */
    virtual int restarGastoDeEnergia(Personaje* ) = 0;

    void setHayPersonaje(bool nuevaCondicion);

    bool hayPersonajeEnCasillero();

    virtual void ImprimirCasilla(string nombre) = 0;

    virtual ~Casillero();



};

#endif // CASILLERO_H_INCLUDED
