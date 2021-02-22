//
// Created by jose on 2/2/21.
//

#ifndef ATAQUE_FUEGO_H
#define ATAQUE_FUEGO_H

#include "personaje.h"

class Fuego : public Personaje {
public:
    //PRE : VALORES VALIDOS PARA NOMBRE,ESCUDO CON VALOR ENTRE 0 A 2 Y VIDA CON VALOR ENTRE 10 A 100.
    // POST: CONSTRUYE UN OBJETO Fuego.
    Fuego(string nombre,int escudo,int vida);

    //PRE :
    /* POST: SI verificarVida ES VERDADERO, INCREMENTA 15 PUNTOS LA VIDA DEL PERSONAJE
     * Y LLAMA A imprimirPersonaje. SI ES FALSO, SE INDICA AL USUARIO A TRAVES DE UN MENSAJE.*/
    void alimentarse();


   //PRE: vector de personaje* valido.
   /*POST: resta energia al personaje que ataca , recorre el vector de enemigos , si el enemigo es distinto de null .
    y esta en un rango de una fila o menos , llama a dano ataque y a quitarVidaPersonaje
    */
   void atacar(Personaje** personajeAtacado);

   //PRE:
   //POST: devuelve elemento del personaje
   string getElemento();

   //PRE:
   //POST: retorna true si energia >= 5 , false en caso contrario.
    bool energiaAtaque();

    //PRE:
    //POST: si la energia>= 10 , le quita la energia al personaje y devuelve true , false en caso contrario
    bool energiaDefensa();



    //pre:
    // post: si la energia == 0, le quita 5 puntos de vida al personaje.
    void modificarPorTurno();

    //PRE :
    //POST : destruye a un personaje de juego.
    ~Fuego();
private:

    // PRE :
    /* POST : DEVUELVE VERDADERO SI LA vida+15 ES MENOR QUE vmax. FALSO EN CASO CONTRARIO.*/
    bool verificarVida();

    // PRE :
    // POST : IMPRIME EL NOMBRE DEL PERSONAJE, SU ALIMENTO, Y NUMERO DE PUNTOS DE VIDA QUE AUMENTO.
    void imprimirAlimentos();

    // PRE: variable filaAtaque y filaAtacar validas.
    //POST: devuelve true si -1 <= diferencia de filas <= 1 , false en caso contrario

    bool comprobarFilas(int filaAtaque , int filaAtacar);

    // PRE: puntero a personajeAtacar validps
    //POST: segun el getElemento de personajeAtacar retorna el valor del daño.
    int danoAtaque(Personaje * personajeAtacar);

};



#endif //ATAQUE_FUEGO_H