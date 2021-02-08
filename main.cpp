#include <iostream>
#include "matriz.h"
#include "grafo.h"
#include "lecturaCsvCasilleros.h"
#include "personaje.h"
#include "agua.h"
#include "tierra.h"
#include "aire.h"
#include "fuego.h"

using namespace std;

int main()
{
    Grafo g;
    Matriz m;
    LecturaCsvCasilleros l;
    string csv = "mapa.csv";
    l.lecturaArchivo(&m, &g, csv);
    m.pasarAdyacencia(&g);
    Personaje* p = new Tierra("mely", 1, 2);
    cout << g.caminoMinimo(1, 1, 7, 4, p) << endl;
    return 0;
}
