#include "menuPrincipal.h"
#include "grafo.h"
#include "matriz.h"
#include "diccionario.h"
#include "ArchivoPartidaGuardada.h"
#include "lecturaCsvCasilleros.h"
#include "fstream"
#include "juego.h"
#include "argumentos.h"

void iniciarPrograma(Grafo* grafo, Matriz* tablero, Diccionario* diccionario, const char* path){
    fstream archivo;
    archivo.open("partida.csv");
    if(archivo.is_open()){
        ArchivoPartidaGuardada archivo;
        Juego juego(grafo,tablero,diccionario);
        archivo.cargarPartida(&juego, tablero);
        juego.iniciarJuegoCargado();
    }else{
        MenuPrincipal menuPrincipal(diccionario);
        menuPrincipal.menu(grafo,tablero, path);
    }
    archivo.close();
}

static void iniciarTablero(Grafo* grafo , Matriz* matriz, const char* path){
    LecturaCsvCasilleros archivo;
    archivo.lecturaArchivo(matriz, grafo, path);
    matriz->pasarAdyacencia(grafo);
}

static void salida(){
    cout << "Saliendo del juego" << endl << endl << __TEXT_YLW__ << "GRACIAS POR JUGAR :D" << __TEXT_NC__ << endl << endl;
}

int main(int argc, char const *argv[]) {
    if(!validarArgs(argc))
        return -1;

    srand(time(nullptr));
    Diccionario diccionario;
    Grafo grafo;
    Matriz tablero;
    iniciarTablero(&grafo,&tablero, argv[2]);
    iniciarPrograma(&grafo,&tablero,&diccionario, argv[1]);

    salida();
    return 0;
}
