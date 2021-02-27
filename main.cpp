#include "menuPrincipal.h"
#include "grafo.h"
#include "matriz.h"
#include "diccionario.h"
#include "lecturaCsvCasilleros.h"
#include "fstream"
#include "juego.h"
#include "argumentos.h"


static void iniciarTablero(Grafo* grafo , Matriz* matriz, const char* path){
    LecturaCsvCasilleros archivo;
    archivo.lecturaArchivo(matriz, grafo, path);
    matriz->pasarAdyacencia(grafo);
}



int main(int argc, char const *argv[]) {
    if(!validarArgs(argc))
        return -1;

    srand(time(nullptr));
    Diccionario diccionario;
    Grafo grafo;
    Matriz tablero;
    iniciarTablero(&grafo,&tablero, argv[2]);
    MenuPrincipal menuPrincipal(&diccionario);
    menuPrincipal.menu(&grafo,&tablero, argv[1]);

    return 0;
}
