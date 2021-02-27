//
// Created by jose on 8/2/21.
//

#ifndef ATAQUE_JUEGO_H
#define ATAQUE_JUEGO_H


#include "interfazUsuario.h"
#include "agua.h"
#include "fuego.h"
#include "aire.h"
#include "tierra.h"
#include "stdlib.h"
#include "fstream"
#include "diccionario.h"
#include "grafo.h"
#include "matriz.h"

#define MAXPERSONAJES 3
#define SALIR 2
#define PRIMERO 1


class Juego {
private:
    VInterfazUsuario vista;
    Grafo* graf;
    Matriz* matriz;
    Diccionario*  diccionario;
    Personaje* jugadorUno[MAXPERSONAJES];
    Personaje* jugadorDos[MAXPERSONAJES];
    int personajeGuardo = 0;
public:

    //pre: puntero a grafo valido y puntero a matri valido.
    //post: crea un objeto juego correctamente.
    Juego(Grafo* graf, Matriz* matriz, Diccionario* diccionario);

   //pre:
   //post:
   void iniciarJuego(Personaje** &primero, Personaje** &segundo);

  //pre:
  //post: 
  void jugar(Personaje** primero , Personaje** Segundo);

   //pre:
   //post:
   void iniciarJuegoCargado();

   void setPersonajeGuardo(int personajeGuardo);


    //pre:
    //post:
    void leerPersonajesArchivo(Personaje* , int);



    //pre:
    //post:
    Personaje** leerJugadorGuardado(int jugador);

    //PRE:
    //POST: si existe algun personaje en los vectores jugadorUno y jugadorDos, los elimina,¡.
    ~Juego();

private:

    //pre:
    //post:
    void actualizarPantalla();

    //pre:
    //post:
    void chequearTurno(Personaje** turno);

    //pre:
    //post:
    void mostrarGanador(bool equipo1 , bool equipo2);

   //pre:
   //post:
   void ContinuarPartida();


    //pre:
    //post:

    bool guardarPartida(int jugadorQueGuardo);

    //pre:
    //post:
   void ArchivoTexto(int jugadorQueGuardo);



    //pre:
    //post: coloca los dos vectores atributos de la clase en cada una de sus posiciones en null
    void inicializarJugadores();

 //pre: puntero a personaje y vector de punteros a personaje validos.
 //post: si el personajeTurno tiene energia ataca , sino lo indica por pantalla al usuario.
    void ataque(Personaje* personajeTurno, Personaje** victima);

    //pre: vectores de puntero a Personaje* y un puntero a personaje valido
    //post: dependiendo de la opcion que elija el usuario , se atacara, defendera o se pasara opcion.
    void menuJuegoAccion(Personaje** usuario,Personaje** contrario, Personaje* personajeTurno);


    //pre: puntero a personaje* personajeTurno valido.
    //post: dependiendo de lo que elija el usuario, el personaje se movera, alimentara o pasara opcion.
    void menuMoverAlimentarse(Personaje* personajeTurno);

  //pre: puntero a personaje personajeTurno valido.
  /*post: pide una fila y columna al usuario, busca el camino minimo en el grafo y llama a condicion moverse
   * la cual devuelve una variable int mientras esta sea distinta a la constante SALIR, se repetira el ciclo
  */  void moverse( Personaje* personajeTurno);

    //pre: puntero a personaje personajeTurno , variables caminoMinimo , fila , col validas.
    /*post: si el personaje tiene energia y la casilla esta vacia , se mueve el personaje a la fila y col
     * pasadas por parametro, en caso contrario llama a la funcion error moverse e indica al usuario.
    */
    int condicionMoverse(Personaje* personajeTurno , int caminoMinimo, int fila , int col);

    //pre: puntero a personaje valido , fila,columna y caminoMinimo validas.
    //post: muestra el camino que recorrido el personaje, cambia su fila y columna y resta el valor caminoMinimo de energia .
    void moverPersonaje(Personaje* personajeTurno, int fila , int columna, int caminoMinimo);

    //pre:
    //post: recibe una eleccion elegida por el usuario entre 1 y dos y la retorna.
    int errorMoverse();

    //PRE: variable fila y columna validas
    //POST: si ningun personaje esta en la fila y columna pasada por parametro devuelve true, false en caso contario.
    bool casillaVacia(int fila, int columna);

   //PRE: vector de personaje valido.
   //POST: si todas las casillas del vector son null devuelve true, false en caso contrario.
   bool equipoSinVida(Personaje** equipo);

   //PRE: puntero a personaje* personajeTurno
   /*POST: recibe por teclado un posicion pasada por parametro y si ningun personaje la tiene , se la asigna
    * al personaje , realiza este procedimiento mientras la casilla a donde se quiere poner al personaje
    * este ocupada..
   */
   void asignarCasilla(Personaje* personajeTurno);

   //PRE: vectores de punteros aliados y enemigos validos.
   // POST: recorre el vector de aliados, llamando a condicionEspecialPersonajes, menuMoverAlimentarse y menuJuegoAccion.
   void turno(Personaje** aliados, Personaje** enemigos, int jugador);


   //PRE: vector de personaje* jugador y posicion valida.
   /*POST: segun lo que elija el usuario, se mostraran los personajes o se elegira uno.
   */
   void menuElegirPersonaje(Personaje** jugador , int posicion);

   //PRE:
   //POST:
   void elegirPersonaje(Personaje** seleccionJugador , int posicion);

 //pre:
 //post:
   void turnosSeleccion();

   //PRE:
   //POST: si la funcion rand es igual a la constante PRIMERO retorna jugadorUno, sino retorna jugadorDos.
   Personaje** turnoRandom();

   //PRE: vector a puntero a Personaje seleccionado valido.
   /*POST: si jugadoUno en la posicion cero es igual al vector seleccionado en la posicion cero,retorna
    jugadorDos , sino retorna jugadorUno
    */
   Personaje** segundoTurno( Personaje** seleccionado);



   void seleccionarPosiciones();


   //PRE: puntero a personaje* personajeTurno y vector de punteros a personaje aliados valido
   //POST: si el personaje tiene energia condicionDefensa , en caso contrario lo indica al usuario
   void defenderse(Personaje* personajeTurno, Personaje** aliados);

   //PRE:vector a personaje aliados y puntero a personaje personajeTurno validos.
   // POST: dependiendo del getElemento del personaje , realiza una funcion especifica.
   void condicionDefensa(Personaje* personajeTurno, Personaje** aliados);

   //PRE: puntero a personaje* personajeTurno valido.
   //POST: el personaje llama a la funcion modificarTurno.
   void condicionEspecialPersonaje(Personaje* personajeTurno);

   //PRE:puntero a personaje* personajeTurno y vector puntero de personaje aliados validos.
   //POST:aumenta 40 puntos al personaje y 10 puntos a cada un del vector aliados.
   void  defensaAgua(Personaje* personajeTurno, Personaje** aliados);

   //PRE: puntero a personaje* personajeTurno valido.
   //POST: pide una fila y columna hasta que el usuario ingrese alguna que no este ocupada y mueve el personaje a esa fila y col.
   void defensaAire(Personaje* personajeTurno);

   //pre: vector de punteros a personaje validos.
   //post: recorre 3 posiciones ,si el personaje no tiene vida, lo elimina y coloca al vector del personaje en null
  void vidaPersonaje( Personaje** equipoEnturno);

  //pre:
  //post: si el personaje existe, muestra un personaje especifico
  void mostrarPersonajeEspecifico();

  //pre:
  //post:muestra los nombres de los personajes
  void mostrarPersonajes();
  //pre:
  //post:
  void imprimirTablero();
};

#endif //ATAQUE_JUEGO_H
