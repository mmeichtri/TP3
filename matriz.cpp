#include "matriz.h"

Matriz::Matriz() {
    iniciarMatriz();
}

void Matriz::iniciarMatriz() {
    for(int fila = 0; fila < RANG ; fila++){
        for(int col = 0; col < RANG ; col++)
           tablero[fila][col] = 0;
    }
}

void Matriz::setTablero(Casillero *tipoCasillero, int fila, int columna) {
    tablero[fila][columna] = tipoCasillero;
}

void Matriz::pasarAdyacencia(Grafo *grafo) {
    for(int fila = 0; fila  < RANG ; fila ++) {
        for (int columna = 0; columna < RANG; columna ++) {

            if (columna - 1 >= 0)
                grafo -> ingresarArista(tablero[fila][columna], tablero[fila][columna - 1], 1);
            if (columna + 1 < RANG)
                grafo -> ingresarArista(tablero[fila][columna], tablero[fila][columna+ 1], 1);
            if (fila == 0)
                grafo -> ingresarArista(tablero[fila][columna], tablero[fila + 1][columna], 1);
            else if (fila == RANG-1)
                grafo -> ingresarArista(tablero[fila][columna], tablero[fila - 1][columna], 1);
            else {
                grafo -> ingresarArista(tablero[fila][columna], tablero[fila - 1][columna], 1);
                grafo -> ingresarArista(tablero[fila][columna], tablero[fila + 1][columna], 1);
            }
        }
    }
}

void Matriz::mostrar(Personaje **jugadorUno, Personaje **jugadorDos) {
    string nombre;
    for(int fila = 0; fila < 8; fila++){
        for(int col = 0; col < 8 ; col++){
            if(tablero[fila][col]->hayPersonajeEnCasillero()){
               nombre =  retornarNombrePersonaje(jugadorUno,jugadorDos,fila,col);
                tablero[fila][col]->ImprimirCasilla(nombre);
            }
            else
                tablero[fila][col]->ImprimirCasilla("");
        }
        //ACÁ HABÍA UN NC PERO LO BORRÉ PORQUE NO ESTÁ DECLARADO EN ESTE ARCHIVO. LUCIANO
        cout << endl;
    }
}

string Matriz::retornarNombrePersonaje(Personaje** jugadorUno, Personaje** jugadorDos,int fila , int columna) {
    bool encontrado = false;
    string nombre;
    int cont = 0;
    while(cont < 3 && !encontrado){
        if(jugadorUno[cont]->getFila() == fila && jugadorUno[cont]->getColumna() == columna){
            nombre = jugadorUno[cont]->getNombre();
            encontrado = true;
        }
        if(jugadorDos[cont]->getFila() == fila && jugadorDos[cont]->getColumna() == columna){
            nombre = jugadorDos[cont]->getNombre();
            encontrado = true;
        }
       cont++;
    }
    return nombre.substr(0,3);
}

void Matriz ::setHayPersonaje(int fila, int columna, bool nuevoEstado) {
    tablero[fila][columna]->setHayPersonaje(nuevoEstado);
}

