#ifndef VISTAMENU_H
#define VISTAMENU_H
#include <string>
#include <iostream>
using namespace std;

class VistaMenu{
public:
    //PRE : RECIBE UN STRING ALFANUMERICO VALIDO.
    /*POST: RETORNA EL VALOR DE TIPO DE STRING INGRESADO POR PARAMETRO*/
    string ingresarString(string str);

    //PRE:
    //POST: IMPRIME EL MENU DE OPCIONES.
    void menu();

    //PRE: RECIBE POR REFERENCIA LA VARIABLE OPCION.
    //POST LE ASIGNA A OPCION UN VALOR ENTRE 1 Y 6
    void comprobarOpcion(int *opcion);

    //PRE: RECIBE UN STRING ALFANUMERICO VALIDO.
    //POST: IMPRIME QUE NO SE ENCONTRO UN ELEMENTO DE ESE TIPO.
    void noEncontro(string str);

    //PRE:
    //POST: INDICA SI EL NOMBRE INGRESADO YA EXISTE EN LA LISTA.
    void yaExiste();

    //PRE:
    //POST:LIMPIA LA PANTALLA.
    void limpiarPantalla();

    //PRE:
    //POST: SALTA UNA LINEA
    void saltarLinea();
};

#endif // VISTAMENU_H
