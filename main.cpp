#include <iostream>
#include "matriz.h"
#include "grafo.h"
#include "lecturaCsvCasilleros.h"
#include "personaje.h"
#include "agua.h"
using namespace std;

int main()
{
    Grafo g;
    Matriz m;
    LecturaCsvCasilleros l;
    string csv = "mapa.csv";
    l.lecturaArchivo(&m, &g, csv);
    m.pasarAdyacencia(&g);
    Personaje* p = new Agua("mely", 1, 2);

    return 0;
}
