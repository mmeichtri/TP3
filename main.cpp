#include <iostream>
#include <string>
#include "menu.h"
#include "personajes.h"

using namespace std;

int main()
{
    Menu m;

    m.cargar();
    m.mostrarMenu();
    m.elegirOpcion();
    m.eleccion();



    return 0;
}
