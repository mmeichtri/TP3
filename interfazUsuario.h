//
// Created by jose on 8/2/21.
//

#ifndef ATAQUE_VINTERFAZUSUARIO_H
#define ATAQUE_VINTERFAZUSUARIO_H
#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;


typedef enum {MENU, JUGADOR, MATRIZ, SI_NO} instancias_t;

const vector<vector<string>> opcionesValidas = 
{
    {"1","2","3","4","5","6"},
    {"1","2","3"},
    {"0","1","2","3","4","5","6","7"},
    {"1","2"}
};



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
    int comprobarOpcion(int rangMinimo , int rangMaximo, instancias_t instancia);

    //PRE: RECIBE UN STRING ALFANUMERICO VALIDO.
    //POST: IMPRIME QUE NO SE ENCONTRO UN ELEMENTO DE ESE TIPO.
    void noEncontro(string str);


    //PRE: VARIABLE LINEA VALIDA
    //POST: IMPRIME LA LINEA PASADA POR PARAMETRO.
    void imprimirLinea(string linea, const string formato = __TEXT_NC__);

    //PRE:
    //POST:LIMPIA LA PANTALLA.
    void limpiarPantalla();

    //PRE:
    //POST: SALTA UNA LINEA
    void saltarLinea();

    //pre: atributos del personaje valido
    //post:Imprime los atributos de los personaje
    void mostrarPersonaje(string nombre , string elemento , int escudo ,int energia, int vida , int fila , int col );

    //pre:
    //post: imprime que no se pudo alimentar el personaje.
    void noSeAlimento();

    //pre:string elemento, comia e int energiaRecuperada validos.
    //post: imprime que se alimento el personaje.
    void alimentado(string elemento , string comida , int energiaRecuperada);

    //pre: variables int validas
    //post: imprime la casilla inicial y final del recorrido
    void caminoInicialFinal(int filaI , int colI , int filaF , int colF);
};


#endif //ATAQUE_VINTERFAZUSUARIO_H