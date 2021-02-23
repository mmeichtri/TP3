#include <iostream>
#include "agua.h"
#include "aire.h"
#include"personaje.h"
#include "tierra.h"
#include "fuego.h"
#include "juego.h"
#include "grafo.h"
#include "matriz.h"
#include "lecturaCsvCasilleros.h"

using namespace std;


int main() {
    srand(time(nullptr));

    Matriz tablero;
    Grafo graf;
    string csv = "mapa.csv";
    LecturaCsvCasilleros arch;
    arch.lecturaArchivo(&tablero,&graf,csv);
    tablero.pasarAdyacencia(&graf);
    Juego iu(&graf);
    iu.jugar();

    return 0;
}
