#include "grafo.h"
#include "casillero.h"
#include "personaje.h"
#include <iostream>
#include <string>
using namespace std;

void Grafo::iniciarMatriz(int matriz[MAX][MAX]) {
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            matriz[i][j] = 0;
    }
}

Grafo::Grafo(){
    iniciarMatriz(matrizAdyacencia);
}

void Grafo::ingresarVertice(Casillero* dato, int posicion){
     this->arrayVertice[posicion] = dato;
}

int Grafo::buscarPosicion(int fila, int columna){
    int posicion = -1;
    bool encontrado = false;
    int cont = 0;

    while(cont < MAX && !encontrado){
        if(this->arrayVertice[cont]->getFila() == fila && this->arrayVertice[cont]->getColumna() == columna ){
            posicion = cont;
            encontrado = true;
        }
        cont++;
    }
    return posicion;
}


void Grafo::ingresarArista(Casillero* v1, Casillero* v2, int peso) {
    int posicionInicial = buscarPosicion(v1->getFila() ,v1->getColumna());
    int posicionFinal = buscarPosicion(v2->getFila(),v2->getColumna());
    matrizAdyacencia[posicionInicial][posicionFinal] = peso;
}

void Grafo ::iniciarBool(bool *array) {
    for(int i = 0; i < MAX ; i++)
        array[i] = false;
}

void Grafo::iniciarArray(int* vec){
    for(int i = 0; i < MAX ; i++)
        vec[i] = 0;
}

void Grafo::iniciarDistancia(int *vecDistancia, int inicial , Personaje* personaje){
    for(int i = 0; i < MAX; i++){
        if(matrizAdyacencia[inicial][i] == 0)
            vecDistancia[i] = 6000;
        else
            vecDistancia[i] = this->arrayVertice[i]->restarGastoDeEnergia(personaje);
    }
}

int Grafo::minimoVectorNoVisto(bool *visto, int *distancia) {
    int posicion = 0;
    int menor = 100000;
    for(int i = 0; i < MAX ; i++){
        if(distancia[i] < menor && visto[i] == false){
            menor = distancia[i];
            posicion = i;
        }
    }
    return posicion;
}

int Grafo::caminoMinimo(int filaInicial, int columnaInicial , int filaFinal , int columnaFinal, Personaje* personaje){
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
               if(distancia[w] > distancia[vertice] + this->arrayVertice[w]->restarGastoDeEnergia(personaje))
                  distancia[w] = distancia[vertice] + this->arrayVertice[w]->restarGastoDeEnergia(personaje);
           }
        }
    }

    return distancia[final] ;

}


Grafo::~Grafo(){
    for(int i = 0; i < MAX ; i++)
        delete this->arrayVertice[i];
}