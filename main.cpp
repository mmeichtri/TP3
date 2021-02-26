
#include "menuPrincipal.h"
#include "grafo.h"
#include "matriz.h"
#include "diccionario.h"
#include "lecturaCsvCasilleros.h"
#include "fstream"
#include "juego.h"


void iniciarTablero(Grafo* grafo , Matriz* matriz){
    string csv = "mapa.csv";
    LecturaCsvCasilleros archivo;
    archivo.lecturaArchivo(matriz,grafo,csv);
    matriz->pasarAdyacencia(grafo);
}



int main() {
    srand(time(nullptr));
    Diccionario diccionario;
    Grafo grafo;
    Juego* juego;
    Matriz tablero;
    iniciarTablero(&grafo,&tablero);
    MenuPrincipal menuPrincipal(&diccionario);
    menuPrincipal.menu(&grafo,&tablero);


    return 0;
}
