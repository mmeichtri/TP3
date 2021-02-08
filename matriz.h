#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "grafo.h"
#include "casillero.h"
#include "montania.h"
#include "lago.h"
#include "precipicio.h"
#include "camino.h"
#include "vacio.h"
#include "volcan.h"
#define RANG 8

class Matriz {
private:
    Casillero* tablero[RANG][RANG];

    //PRE:
    //POST: COLOCA EL VALOR 0 EN CADA UNO DE LOS CASILLEROS DE LA MATRIZ.
    void iniciarMatriz();
public:
    //PRE:
    //POST: CREA UNA MATRIZ DE RANGO RANG CON TODOS SUS CASILLEROS EN CERO.
    Matriz();

    //PRE: PUNTERO A CASILLERO VALIDO , VARIABLES INT FILA Y COLUMNA VALIDAS.
    //POST: COLOCA LA VARIABLE DE TIPO CASILLERO* EN LA MATRIZ TABLERO EN LA POSICION DE LA FILA Y COL.
    void setTablero(Casillero* ,int  , int );

    //PRE: PUNTERO GRAFO VALIDO.
    //POST: LLENA LA MATRIZ DE ADYACENCIA, INDICANDO QUE VERTICES SON ADYACENTES.
    void pasarAdyacencia(Grafo* );

};


#endif // MATRIZ_H_INCLUDED
