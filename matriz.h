#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "grafo.h"
#include "casillero.h"
#include "personaje.h"
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

    Casillero* retornarCasillero(int fila , int columna);

    void setHayPersonaje(int fila , int columna ,bool nuevoEstado );

    void recorrerMatriz(Personaje** jugadorUno , Personaje** jugadorDos);

    string retornarElementoJugador(Personaje* jugadorUno , Personaje* jugadorDos);




};


#endif // MATRIZ_H_INCLUDED
