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
#define MAXPERSONAJES 1
#define SALIR 2
#define PRIMERO 1


class Juego {
private:
    VInterfazUsuario vista;
    grafo* graf;
    Personaje* jugadorUno[MAXPERSONAJES];
    Personaje* jugadorDos[MAXPERSONAJES];
public:
    Juego(grafo* graf);

    void inicializarJugadores();

    //PRE : PUNTERO Y VECTOR A PUNTEROS DE PERSONAJE VALIDOS.
    /* POST: SI EL PERSONAJE TIENE ENERGIA PARA ATACAR, SI EL PERSONAJE ES AGUA LLAMA A ATAQUE DE AGUA, SINO,
     LLAMA A recorrerRivalAtaque , SI NO TIENE ENERGIA LO INDICA.*/
    void ataque(Personaje* personajeTurno, Personaje** victima);

    //PRE : VECTORES A PERSONAJE Y PUNTERO A PERSONAJE VALIDOS
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

    //PRE: PUNTERO A PERSONAJE VALIDO.
    /*POST: DEPENDIENDO DE LO INGRESADO POR TECLADO POR EL USUARIO, SI UN PERSONAJE TIENE ENERGIA SE MUEVE
     * A OTRA CASILLA DEL TABLERO.
    */
    void moverse( Personaje* personajeTurno);

    //PRE :PUNTERO A PERSONAJE , 3 VARIABLES INT VALIDAS
    /*POST: SI EL PERSONAJE TIENE ENERGIA Y LA CASILLA NO ESTA OCUPADA, DEVUELVE TRUE Y CAMBIA AL PERSONAJE
    DE POSICION, FALSE EN CASO CONTRARIO */
    bool condicionMoverse(Personaje* personajeTurno , int caminoMinimo, int fila , int col);

    //PRE:VARIABLE BOOLEANA VALIDA
    /*POST: SI LA VARIABLE seMovio ES FALSE , LE INDICA AL USUARIO QUE NO SE PUDO MOVER Y QUE INGRESE UNA
    NUEVA OPCION , SI ES TRUE DEVUELVE SALIR */
    int errorMoverse(bool seMovio);

    //PRE: VARIABLE FILA Y COLUMNA VALIDAS
    //POST: SI LA FILA Y COLUMNA PASADA POR PARAMETRO NO LA TIENEN NINGUN PERSONAJE DEVUELVE TRUE, FALSE EN CONTRARIO
    bool casillaVacia(int fila, int columna);

   //PRE: VECTOR DE PERSONAJES VALIDO
   //POST: DEVUELVE TRUE SI TODOS LOS PERSONAJES DE ESE EQUIPO SE QUEDARON SI VIDA, FALSE EN CASO CONTRARIO.
   bool equipoSinVida(Personaje** equipo);

   //PRE: PUNTERO A PERSONAJE VALIDO.
   //POST: RECIBE POR TECLADO UNA POSICION DEL TABLERO Y SE LE ASIGNA AL PERSONAJE PASADO POR PARAMETRO.
   void asignarCasilla(Personaje* personajeTurno);

   //PRE:VECTORES DE PUNTEROS A PERSONAJE VALIDOS.
   // POST: RECORRE LA LISTA DE LOS PERSONAJE DE ALIADOS, LLAMANDO A menuMoverAlimentarse y menuJuegoAccion.
   void turno(Personaje** aliados, Personaje** enemigos);

   //PRE:
   /*POST:LLAMA A TURNO RANDOM Y PERDEDOR TURNO PARA SABER ALEATORIAMENTE QUE JUAGDOR SALDRA PRIMERO,
    LUEGO HASTA QUE ALGUNO DE LOS DOS EQUIPOS SE QUEDE SIN VIDA, LLAMARA A LA FUNCION DE turnos.
    */
   void jugar();

   //PRE: VECTOR DE PERSONAJE VALIDO Y POSICION VALIDA.
   //POST: DEPENDIENDO DE LO QUE EL USUARIO ESCOJA POR PANTALLA, MOSTRARA LOS PERSONAJE O EL USUARIO ELEGIRA UN PERSONAJE.
   void menuElegirPersonaje(Personaje** jugador, int posicion);

   //PRE:
   //POST:
   void elegirPersonaje();

   //PRE:VECTOR DE PUNTEROS DE PERSONAJE VALIDO.
   //POST: LLAMA A elegirPersonaje PARA CADA UNO DE LOS VECTORES PASADOS POR PARAMETRO.
   void turnosSeleccion();

   //PRE:
   //POST: SI LA FUNCION RAND ES UNO RETORNA EL VECTOR jugadorUno, SINO jugadorDos
   Personaje** turnoRandom();

   //PRE: VECTOR A PUNTERO VALIDO
   /*POST: SI EL VECTOR jugadorUno EN LA POSICION CERO ES IGUAL AL VECTOR seleccionado EN LA MISMA POSICION
    * RETORNA EL VECTO jugadorDos, SINO RETORNA jugadorUno.
    */
   Personaje** perdedorTurno( Personaje** seleccionado);

   //PRE: DOS VECTORES DE PUNTEROS DE PERSONAJE VALIDOS.
   /*POST: ASIGNA CON LA FUNCION turnoRandom Y perdedorTurno QUIEN VA A SER EL PRIMERO EN SELECCIONAR POSICION,
      Y LUEGO LLAMA A LA FUNCION asignarCasilla */
   void seleccionarPosiciones();


   //PRE:PUNTERO DE PERSONAJE Y VECTOR DE PUNTERO DE PERSONAJE VALIDO.
   //POST: RECORRE UN FOR DE TRES ITERACIONES DONDE EL ATACANTE ATACARA A CADA UNO DE LOS PERSONAJES DEL VECTOR.
   void recorrerRivalAtaque(Personaje** rival, Personaje* atacante);

   //PRE: PUNTERO A PERSONAJE Y VECTOR A PUNTERO DE PERSONAJE VALIDOS.
   //POST: SI EL PERSONAJE TIENE ENERGIA LLAMA A condicionDefensa , EN CASO CONTRARIO IMPRIME QUE NO TIENE ENERGIA
   void defenderse(Personaje* personajeTurno, Personaje** aliados);

   //PRE:VECTOR A PERSONAJE VALIDO Y PUNTERO A PERSONAJE VALIDO
   // POST: DEPENDIENDO DEL ELEMENTO DE PERSONAJE LLAMA A UNA FUNCION ESPECIFICA
   void condicionDefensa(Personaje* personajeTurno, Personaje** aliados);

   //PRE: PUNTERO A PERSONAJE VALIDO
   //POST: SI EL PERSONAJE ES AIRE , AUMENTA 5 PUNTOS DE ENERGIA , SI ES FUEGO Y LA ENERGIA ES CERO, LE QUITA 5 DE VIDA.
   void condicionEspecialPersonaje(Personaje* personajeTurno);

   //PRE:PUNTERO A PERSONAJE VALIDO Y VECTOR DE PUNTEROS A PERSONAJE
   //POST: AUMENTA 50 PUNTOS DE VIDA AL PERSONAJE Y 10 PUNTOS A LOS ALIADOS
   void  defensaAgua(Personaje* personajeTurno, Personaje** aliados);

   //PRE:PUNTERO A PERSONAJE VALIDO
   //POST: PIDE UNA FILA Y COLUMNA Y SI NO HAY UN PERSONAJE EN ESA FILA Y COLUMNA MUEVE AL PERSONAJE DE AIRE
   void defensaAire(Personaje* personajeTurno);

  void vidaPersonaje(Personaje* personajeTurno, int posicion , Personaje** equipoPersonaje);

  //PRE:
  //POST:
    ~Juego();
};

#endif //ATAQUE_JUEGO_H
