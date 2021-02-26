#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED
#include <string.h>
#include "personaje.h"
#define __NC__ "\033[0m"
#define __RED__ "\033[30;41m"
#define __GRN__ "\033[30;42m"
#define __YLW__ "\033[1;30;43m"
#define __BLU__ "\033[30;44m"
#define __PUR__ "\033[30;45m"
#define __CYN__ "\033[30;46m"
#define __GRY__ "\033[30;47m"
#define __REDB__ "\033[41m"

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
