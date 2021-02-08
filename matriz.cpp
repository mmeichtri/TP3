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
