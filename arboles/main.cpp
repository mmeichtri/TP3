
#include "arbol.h"

int main() {
    arbol arb;
arb.cargarArbol(30);
arb.cargarArbol(20);
arb.cargarArbol(45);
arb.cargarArbol(2);
arb.cargarArbol(50);
arb.cargarArbol(25);

arb.eliminarNodo(30);
arb.inOrden(arb.getRaiz());

    return 0;
}
