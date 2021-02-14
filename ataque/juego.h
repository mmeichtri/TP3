//
// Created by jose on 8/2/21.
//

#ifndef ATAQUE_JUEGO_H
#define ATAQUE_JUEGO_H


#include "vInterfazUsuario.h"
#include "personaje.h"
#include "agua.h"
#include "fuego.h"
#include "aire.h"
#include "tierra.h"
#include "stdlib.h"
#include "grafo.h"
#define MAXJUGADORES 3
#define SALIR 2
#define PRIMERO 1


class Juego {
private:
    VInterfazUsuario vista;
    Personaje* jugadorUno[MAXJUGADORES];
    Personaje* jugadorDos[MAXJUGADORES];
public:
    //PRE : PUNTERO Y VECTOR A PUNTEROS DE PERSONAJE VALIDOS.
    /* POST: SI EL PERSONAJE TIENE ENERGIA PARA ATACAR, SI EL PERSONAJE ES AGUA LLAMA A ATAQUE DE AGUA, SINO,
     LLAMA A recorrerRivalAtaque , SI NO TIENE ENERGIA LO INDICA.*/
    void ataque(Personaje* personajeTurno, Personaje** victima);

    //PRE : VECTORES DE ATACANTE Y VICTIMA VALIDOS
    //POST : SEGUN LA OPCION PASADA POR TECLADO REALIZA UNA ACCION.
    void menuJuegoAccion(Personaje** usuario,Personaje** contrario, Personaje* );

    //PRE:PUNTERO PERSONAJE Y VECTOR DE PERSONAJE VALIDOS
    /*POST: LLAMA A LA FUNCION ATACAR DEL PERSONAJE QUE ATACA Y EL VALOR OBTENIDO  MODIFICA EN LA VICTIMA,
     DEPENDIENDO DEL ESCUDO QUE ESTA TENGA.
     */
    void ataquePersonajes(Personaje* atacante , Personaje* victima);

    //PRE: PUNTERO A PERSONAJE Y VECTOR DE PERSONAJE VALIDOS.
    /*POST: AL PEDIR LA FILA Y COLUMNA QUE EL PERSONAJE VA A ATACAR, LO BUSCA EN EL VECTOR DE VICTIMAS Y SI LO
     ENCUENTRA LO ATACA , SI NO HAY NINGUN PERSONAJE EN LA FILA PASADA POR TECLADO LO INDICA EN PANTALLA.
    */
    void ataquePersonajeAgua(Personaje* atacante, Personaje** victimas);

    /* PRE: PUNTERO A PERSONAJE VALIDO.
     * POST: MENU DE OPCIONES , DONDE DEPENDIENDO LO QUE INGRESE EL USUARIO ALIMENTARA UN PERSONAJE , LO MOVERA
     * O PASARA OPCION.
*/
    void menuMoverAlimentarse(Personaje* personajeTurno);

    //PRE: GRAFO Y PUNTERO A PERSONAJE VALIDO.
    /*POST: DEPENDIENDO DE LO INGRESADO POR TECLADO POR EL USUARIO, SI UN PERSONAJE TIENE ENERGIA SE MUEVE
     * A OTRA CASILLA DEL TABLERO.
    */
    void moverse(grafo* graf , Personaje* personajeTurno);

    bool condicionMoverse(Personaje* personajeTurno , int caminoMinimo, int fila , int col);

    int errorMoverse(bool seMovio);

    //PRE:
    //POST:
    bool casillaVacia(Personaje** equipo , int fila, int columna);

   //PRE: VECTOR DE PERSONAJES VALIDO
   //POST: DEVUELVE TRUE SI TODOS LOS PERSONAJES DE ESE EQUIPO SE QUEDARON SI VIDA, FALSE EN CASO CONTRARIO.
   bool equipoSinVida(Personaje** equipo);

   //PRE: PUNTERO A PERSONAJE VALIDO.
   //POST: RECIBE POR TECLADO UNA POSICION DEL TABLERO Y SE LE ASIGNA AL PERSONAJE PASADO POR PARAMETRO.
   void asignarCasilla(Personaje* personajeTurno);

   //PRE:VECTORES DE PUNTEROS A PERSONAJE VALIDOS.
   // POST: RECORRE LA LISTA DE LOS PERSONAJE DE ALIADOS, LLAMANDO A menuMoverAlimentarse y menuJuegoAccion.
   void turno(Personaje** aliados, Personaje** enemigos);

   //PRE: VECTOR DE PERSONAJES VALIDOS.
   /*POST:LLAMA A TURNO RANDOM Y PERDEDOR TURNO PARA SABER ALEATORIAMENTE QUE JUAGDOR SALDRA PRIMERO,
    LUEGO HASTA QUE ALGUNO DE LOS DOS EQUIPOS SE QUEDE SIN VIDA, LLAMARA A LA FUNCION DE turnos.
    */
   void jugar(Personaje** jugadorUno,Personaje** jugadorDos);

   //PRE: VECTOR DE PERSONAJE VALIDO Y POSICION VALIDA.
   //POST: DEPENDIENDO DE LO QUE EL USUARIO ESCOJA POR PANTALLA, MOSTRARA LOS PERSONAJE O EL USUARIO ELEGIRA UN PERSONAJE.
   void menuElegirPersonaje(Personaje** jugador, int posicion);

   //PRE: VECTOR DE PERSONAJE VALIDO, VARIABLE INT VALIDA.
   /*POST: PIDE EL NOMBRE AL USUARIO Y SI ESTE NOMBRE SE ENCUENTRA EN EL DICCIONARIO Y A SU VEZ NO ESTA
    * ELEGIDO, LO AGREGA A AL VECTOR EN LA POSICION PASADA POR PARAMETRO.
   */
   void elegirPersonaje(Personaje** jugador, int posicion);

   //PRE:VECTOR DE PUNTEROS DE PERSONAJE VALIDO.
   //POST: LLAMA A elegirPersonaje PARA CADA UNO DE LOS VECTORES PASADOS POR PARAMETRO.
   void turnosSeleccion(Personaje** jugadorUno, Personaje** jugadorDos);

   //PRE: VECTOR DE PUNTERO A PERSONAJE VALIDO.
   //POST: SI LA FUNCION RAND ES UNO RETORNA EL VECTOR jugadorUno, SINO jugadorDos
   Personaje** turnoRandom(Personaje** jugadorUno, Personaje** jugadorDos);

   //PRE: TRES VECTORES DE PUNTERO A PERSONAJE VALIDOS.
   /*POST: SI EL VECTOR jugadorUno EN LA POSICION CERO ES IGUAL AL VECTOR seleccionado EN LA MISMA POSICION
    * RETORNA EL VECTO jugadorDos, SINO RETORNA jugadorUno.
    */
   Personaje** perdedorTurno(Personaje** jugadorUno, Personaje** jugadorDos , Personaje** seleccionado);

   //PRE: DOS VECTORES DE PUNTEROS DE PERSONAJE VALIDOS.
   /*POST: ASIGNA CON LA FUNCION turnoRandom Y perdedorTurno QUIEN VA A SER EL PRIMERO EN SELECCIONAR POSICION,
      Y LUEGO LLAMA A LA FUNCION asignarCasilla */
   void seleccionarPosiciones(Personaje** jugadorUno, Personaje** jugadorDos);


   //PRE:PUNTERO DE PERSONAJE Y VECTOR DE PUNTERO DE PERSONAJE VALIDO.
   //POST: RECORRE UN FOR DE TRES ITERACIONES DONDE EL ATACANTE ATACARA A CADA UNO DE LOS PERSONAJES DEL VECTOR.
   void recorrerRivalAtaque(Personaje** rival, Personaje* atacante);

   //PRE:
   //POST:
   void defenderse(Personaje* personajeTurno);

   void condicionDefensa(Personaje* personajeTurno);

   //PRE:
   //POST:
   void condicionEspecialPersonaje(Personaje* personajeTurno);

   //PRE:
   //POST:
   void  defensaAgua(Personaje* personajeTurno);

   //PRE:
   //POST:
   void defensaAire(Personaje* personajeTurno);



};

#endif //ATAQUE_JUEGO_H
