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

    //PRE: matriz pasada por parametro valida.
    //POST: asigna a la matriz pasada por parametro el valor 0 en cada posicion.
    void iniciarMatriz(int mat[MAX][MAX]);

    //PRE: vectores visto y distancia valido.
    //POST: retorna la posicion del minimo vector no visto
    int minimoVectorNoVisto(bool visto[], int distancia[]);

  //PRE: vector de bool valido
  //POST: inicia el vector en todas sus posiciones en false
    void iniciarBool(bool array[]);

   //PRE: fila y columna validas, con un valor entre el rango establecido.
   /*POST: busca si la fila y columna pasadas por parametros son iguales a algun casillero* en arrayVertice,
    cuando lo encuentra retorna la posicion
    */
   int buscarPosicion(int fila , int columna);

   //PRE: vector de entero valido y un valor int valido.
   //POST: inicia cada una de las posiciones del vector con el valor int pasado por parametro.
    void iniciarArray(int* vec , int valor);

    /*PRE : vector  int distancia y bool visto  , valor int inicial y string personaje validos.
     POST : si un vertice es adyacente al inicial pasado por parametro se coloca el valor en vecDistancia
     lo que cuesta al personaje pasar por ese vertice, si no son adyacentes, coloca 6000.
     */
    void iniciarDistancia(int *vecDistancia , int inicial , string personaje, bool* visto);

    //PRE: variable int, vector visto y distancia validos.
    /*POST: inicia el vector padre en -1 y luego busca la posicion del minimo vector no visto y se la asigna
    a padre.
    */
    void iniciarPadre(int inicial , bool* visto , int* distancia);

    //PRE: vector distancia , valor del vertice y string de personaje validos.
    /*POST: si el valor en vec distancia en una posicion es mayor que el vector distancia en la posicion
    vertice + lo que cuesta pasar por la posicion misma que tiene el vec distancia , se cambia vecDistancia
     en esa posicion por el valor obtenido y al padre en la posicion se le asigna: vertice.
    */void condicionCaminoMinimo(int* distancia , int vertice , string personaje);

public :
    /*PRE :
     POST: crea un grafo con la matriz de adyacencia inicializada en cero
     */
    Grafo();

    /* PRE : puntero a casillero valido y posicion valida
      POST: coloca en arrayVertice en la posicion pasada por parametro el valor del casillero*.
      */
    void ingresarVertice(Casillero* dato, int posicion);

    /* PRE : dos punteros a casillero validos y un valor peso valido.
      POST: llama a buscarPosicion() y busca las posiciones de los casilleros pasados por parametro
      en arrayVertice una vez obtenidos, lo coloca en la matriz de adyacencia en la pos
      fila: casilleroUno , columna:  casilleroDos , con el valor peso.
     */
    void ingresarArista(Casillero* casilleroUno , Casillero* casilleroDos  , int peso);

    /*PRE: 4 int validos y un string personaje correctamente creado.
     POST: busca y retorna el camino minimo desde la fila y columna inicial , hasta la fila y col final.
     */
    int caminoMinimo(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal, string personaje);

    /* PRE: variable final valida.
     * POST: hasta que padre[final] = -1 va haciendo final = padre[final] y va  imprimiendo
     la fila y la columna en la posiion final .
     */
    void recorridoMinimo(int final);

    /*PRE :
      POST: elimina los punteros a casillero que estan en el array vertice.
     */
    ~Grafo();

};


#endif //GRAFO_GRAFO_H