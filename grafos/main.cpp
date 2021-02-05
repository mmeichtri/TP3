#include <iostream>
using namespace std;
#include "archivo.h"
#include "matriz.h"
#include "grafo.h"
int main() {

    grafo graf;
    Matriz tablero;
    Archivo arch;
    arch.leerArchivo(&tablero ,&graf);
    tablero.pasarAdyacencia(&graf);
   graf.caminoMinimo(0,0,7,7,"tierra");

    return 0;
}