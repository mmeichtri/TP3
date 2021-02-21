//
// Created by jose on 29/12/20.
//

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H
#define MAX 64
#include "casillero.h"

class Grafo {
private:
    Casillero* arrayVertice[MAX];
    int padre[MAX];
    int  matrizAdyacencia[MAX][MAX];

    //PRE:
    //POST:
    void iniciarMatriz(int mat[MAX][MAX]);

    //PRE:
    //POST:
    int minimoVectorNoVisto(bool visto[], int distancia[]);

  //PRE:
  //POST:
    void iniciarBool(bool array[]);

   //PRE:
   //POST:
    int buscarPosicion(int fila , int columna);

   //PRE:
   //POST:
    void iniciarArray(int* vec , int valor);

    /*PRE :
     POST :
     */
    void iniciarDistancia(int *vecDistancia , int inicial , string personaje, bool* visto);

    //PRE:
    //POST:
    void iniciarPadre(int inicial , bool* visto , int* distancia);

    //PRE:
    //POST:
    void condicionCaminoMinimo(int* distancia , int vertice , string personaje);

public :
    /*PRE :
     POST:
     */
    Grafo();

    /* PRE :
      POST:
      */
    void ingresarVertice(Casillero* casillero, int posicion);

    /* PRE :
      POST:
     */
    void ingresarArista(Casillero* v1 , Casillero* v2 , int peso);

    /*PRE:
     POST: */
    int caminoMinimo(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal, string personaje);

    /* PRE:
     * POST<.

     */
    void recorridoMinimo(int final);

    /*PRE :
      POST: ELIMINA CADA UNO DE LOS PUNTEROS A CASILLERO QUE SE ENCUENTRAN EN EL ARRAY VERTICES.
     */
    ~Grafo();

};


#endif //GRAFO_GRAFO_H
