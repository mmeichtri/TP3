#include "grafo.h"
#include "casillero.h"
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


void Grafo::ingresarArista(Casillero* casilleroUno, Casillero* casilleroDos, int peso) {
    int posicionInicial = buscarPosicion(casilleroUno->getFila() ,casilleroUno->getColumna());
    int posicionFinal = buscarPosicion(casilleroDos->getFila(),casilleroDos->getColumna());
    matrizAdyacencia[posicionInicial][posicionFinal] = peso;
}

void Grafo ::iniciarBool(bool *array) {
    for(int i = 0; i < MAX ; i++)
        array[i] = false;
}

void Grafo::iniciarArray(int* vec , int valor){
    for(int i = 0; i < MAX ; i++)
        vec[i] = valor;
}

void Grafo::iniciarDistancia(int *vecDistancia, int inicial , Personaje* personaje, bool* visto){
    for(int i = 0; i < MAX; i++){
        if(matrizAdyacencia[inicial][i] == 0)
            vecDistancia[i] = 6000;
        else
            vecDistancia[i] = this->arrayVertice[i]->restarGastoDeEnergia(personaje);
    }
    vecDistancia[inicial] = 0;
    visto[inicial] = true;
}

int Grafo::minimoVectorNoVisto(bool *visto, int *distancia) {
    int posicion = 0;
    int menor = 100000; //numero arbitrario mayor que el mas grande en distancia
    for(int i = 0; i < MAX ; i++){
        if(distancia[i] < menor && visto[i] == false){
            menor = distancia[i];
            posicion = i;
        }
    }
    return posicion;
}

void Grafo:: iniciarPadre(int inicial, bool * visto , int* distancia){
    iniciarArray(padre,-1);
    int primerMinimo = minimoVectorNoVisto(visto,distancia);
    padre[primerMinimo] = inicial;
}

int Grafo::caminoMinimo(int filaInicial, int columnaInicial , int filaFinal , int columnaFinal, Personaje* personaje){
    int inicial = buscarPosicion(filaInicial,columnaInicial);
    int final = buscarPosicion(filaFinal,columnaFinal);
    int distancia[MAX];
    bool visto[MAX];
    iniciarBool(visto);
    iniciarArray(distancia , 0);
    iniciarDistancia(distancia, inicial, personaje,visto);
    iniciarPadre(inicial,visto,distancia);

    while(!visto[final]){
        int  vertice = minimoVectorNoVisto(visto,distancia);
        visto[vertice] = true;
        condicionCaminoMinimo(distancia,vertice,personaje);
    }

    return distancia[final] ;
}


void Grafo::condicionCaminoMinimo(int *distancia , int vertice , Personaje *personaje) {

    for(int w = 0; w < MAX; w++){
        if(matrizAdyacencia[vertice][w] != 0 ){
            if(distancia[w] > distancia[vertice] + arrayVertice[w]->restarGastoDeEnergia(personaje)){
                distancia[w] = distancia[vertice] + arrayVertice[w]->restarGastoDeEnergia(personaje);
                padre[w] = vertice;
            }
        }
    }
}

void Grafo ::recorridoMinimo(int final) {

    if(padre[final] == -1)
      return;
    else{
        final = padre[final];
        recorridoMinimo(final);
        cout <<" ("<< arrayVertice[final]->getFila() << " , " << arrayVertice[final]->getColumna()<<" )  " ;
       return;
    }

}

Grafo::~Grafo(){
    for(int i = 0; i < MAX ; i++)
        delete this->arrayVertice[i];
}
