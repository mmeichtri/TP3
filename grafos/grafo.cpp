//
// Created by jose on 29/12/20.
//

#include "grafo.h"

#include <iostream>
using namespace std;


void grafo ::iniciarMatriz(int mat[MAX][MAX]) {

    for(int fila = 0; fila < MAX; fila ++){
        for(int columna = 0; columna < MAX; columna ++)
            mat[fila][columna] = 0;
    }
}

grafo ::grafo() {

    iniciarMatriz(matrizAdyacencia);
}


void grafo ::ingresarVertice(Casillero* dato, int posicion) {
     arrayVertice[posicion] = dato;

}
int grafo ::buscarPosicion(int fila, int columna) {
    int posicion = -1;
    bool encontrado = false;
    int cont = 0;

    while(cont < MAX && ! encontrado){
        if(arrayVertice[cont] -> devolverfila() == fila && arrayVertice[cont] -> devolverColumna() == columna ){
            posicion = cont;
            encontrado = true;
        }
        cont ++;
    }
    return posicion;
}


void grafo ::ingresarArista(Casillero* v1, Casillero* v2, int peso) {

    int posicionInicial = buscarPosicion(v1 -> devolverfila(),v1 -> devolverColumna());
    int posicionFinal = buscarPosicion(v2 -> devolverfila(),v2 -> devolverColumna());
    matrizAdyacencia[posicionInicial][posicionFinal] = peso;
}

void grafo ::iniciarBool(bool *array) {
    for(int i = 0; i< MAX ; i++)
        array[i] = false;
}

void grafo :: iniciarArray(int* vec){
    for(int i = 0; i < MAX ; i++)
        vec[i] = 0;
}

void grafo:: iniciarDistancia(int * vecDistancia, int inicial , string personaje){

    for(int i = 0; i < MAX; i++){

        if(matrizAdyacencia[inicial][i] == 0)
            vecDistancia[i] = 6000;
        else
            vecDistancia[i] = arrayVertice[i] -> devolverPeso(personaje);
    }
}

int grafo ::minimoVectorNoVisto(bool *visto, int *distancia) {

    int posicion = 0;
    int menor = 100000;
    for( int i = 0; i < MAX ; i++){
        if(distancia[i] < menor && visto[i] == false){
            menor = distancia[i];
            posicion = i;
        }
    }

    return posicion;
}

int grafo ::caminoMinimo(int filaInicial, int columnaInicial , int filaFinal , int columnaFinal,string personaje) {

    int inicial = buscarPosicion(filaInicial,columnaInicial);
    int final = buscarPosicion(filaFinal,columnaFinal);
    int distancia[MAX];
    bool visto[MAX];
    iniciarBool(visto);
    iniciarArray(distancia);

    iniciarDistancia(distancia, inicial, personaje);

    distancia[inicial] = 0;
    visto[inicial] = true;

    while(!visto[final]){
        int  vertice = minimoVectorNoVisto(visto,distancia);
        visto[vertice] = true;

        for(int w = 0; w < MAX; w++){
           if(matrizAdyacencia[vertice][w] != 0 ){
               if(distancia[w] > distancia[vertice] + arrayVertice[w] -> devolverPeso(personaje))
                   distancia[w] = distancia[vertice] + arrayVertice[w] -> devolverPeso(personaje);
           }
        }
    }
    cout << " el valor de ir de " << inicial << " a " << final << " es " << distancia[final] << endl;
    return distancia[final];
}


grafo ::~grafo() {
    for(int i = 0; i < MAX ; i++)
        delete arrayVertice[i];
}