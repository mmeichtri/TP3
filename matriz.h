#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "grafo.h"
#include "casillero.h"
#include "personaje.h"
#include <string.h>
using namespace std;
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

    //pre: valor int fila, columna y valor bool valido
    //post: coloca al puntero a personaje que esta en la casilla pasada por parametro en el valor bool pasadp
    void setHayPersonaje(int fila , int columna ,bool nuevoEstado );

    //pre:le pasa vectores de personajes validos
    //post: recorre el tablero y si en una casilla hay un personaje llama a retornarNombrePersonaje, sino llama a imprimir casilla con ""
    void mostrar(Personaje** jugadorUno , Personaje** jugadorDos);

    //pre:vectores a personajes validos y fila y columna validas
    //post: si existe un jugador en la fila columna pasada por parametro retorna las tres primeras letras del nombre.
    string retornarNombrePersonaje(Personaje** jugadorUno , Personaje** jugadorDos, int fila ,int columna);




};


#endif // MATRIZ_H_INCLUDED