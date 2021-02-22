//
// Created by jose on 8/2/21.
//

#ifndef ATAQUE_VINTERFAZUSUARIO_H
#define ATAQUE_VINTERFAZUSUARIO_H
#include <iostream>
#include <string>
using namespace std;

class VInterfazUsuario {
public:

    // PRE: VARIABLE STRING VALIDA
    // POST: DEVUELVE LA VARIABLE FILA O COLUMNA LEIDA POR TECLADO
    int leerFilaOColumna(string dato);


    //PRE : RECIBE UN STRING ALFANUMERICO VALIDO.
    /*POST: RETORNA EL VALOR DE TIPO DE STRING INGRESADO POR PARAMETRO*/
    string ingresarString(string str);

    //PRE:
    //POST: IMPRIME EL MENU PRINCIPAL DE OPCIONES.
    void menuPrincipal();

    //PRE:
    //POST: IMPRIME EL MENU DONDE LOS JUGADORES ELEGIRAN SUS PERSONAJES.

    void menuJugadores();

    //PRE:
    //POST: IMPRIME EL PRIMER MENU DE TURNOS

    void primerMenuTurno();

    //PRE:
    //POST: IMPRIME EL SEGUNDO MENU DE TURNOS.

    void segundoMenuTurno();

    //PRE: RECIBE DOS VARIABLES ENTERAS VALIDAS..
    //POST: RETORNA LA OPCION VALIDA DENTRO DEL RANGO DE LAS VARIABLES PASADAS POR PARAMETRO.
    int comprobarOpcion(int rangMinimo , int rangMaximo);

    //PRE: RECIBE UN STRING ALFANUMERICO VALIDO.
    //POST: IMPRIME QUE NO SE ENCONTRO UN ELEMENTO DE ESE TIPO.
    void noEncontro(string str);


    //PRE: VARIABLE LINEA VALIDA
    //POST: IMPRIME LA LINEA PASADA POR PARAMETRO.
    void imprimirLinea(string linea);

    //PRE:
    //POST:LIMPIA LA PANTALLA.
    void limpiarPantalla();

    //PRE:
    //POST: SALTA UNA LINEA
    void saltarLinea();

};


#endif //ATAQUE_VINTERFAZUSUARIO_H