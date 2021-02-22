//
// Created by jose on 2/2/21.
//

#ifndef ATAQUE_TIERRA_H
#define ATAQUE_TIERRA_H

#include "personaje.h"


class Tierra : public Personaje {
private:
   int escudoInicial;
public:
    // PRE: NOMBRE VALIDO , VIDA CON VALOR ENTRE 10 Y 100 Y ESCUDO CON VALOR 0 A 2 VALIDOS.
    // POST: CONSTRUYE UN OBJETO Tierra CON DATOS VALIDOS.
    Tierra(string nombre,int escudo,int vida);

    // PRE:
    /* POST:  SI verificarEnergia() ES VERDADERO, AUMENTA LA ENERGIA EN 8 PUNTOS
     * Y LLAMA A imprimirALimentos, SI ES FALSO SE LO INDICA AL USUARIO.*/
    void alimentarse();

   //PRE: vector de personaje* personajeAtacado valido.
   /*POST: recorre el vector de personajeAtacado y en cada posicion si no es nullptr , llama a danoRango
   danoAtaque y quitarVida.
    */
   void atacar(Personaje** personajeAtacado);

   //PRE:
   //POST: retorna true si energia >= 6 , false en caso contrario
    bool energiaAtaque();

    //pre:
    //post: si el escudo es distinto de la constante EscudoInicial , le resta dos al escudo.

    void modificarPorTurno();

    //PRE:
    //POST: retorna true si energia >= 5 false en caso contrario.
    bool energiaDefensa();

    //PRE:
    //POST: DEVUELVE EL NOMBRE DEL ELEMENTO
   string getElemento();


    //PRE:
    //POST: DESTRUYE UN OBJETO Tierra
    ~Tierra();
private:
    //PRE:
    //POST: DEVUELVE VERDADERO SI LA ENERGIA + 8 ES MENOR O IGUAL A 20. FALSO SI NO SE CUMPLE LA CONDICION
    bool  verificarEnergia();
    // PRE:
    // POST:IMPRIME NOMBRE ,DE QUE SE ALIMENTO Y EL TOTAL DE ENERGIA DEL PERSONAJE.
    void imprimirAlimentos();

    //PRE: cuatro valor enteros validos
    /*POST: si la diferencia de filas es dos , retorna condicionRangoDos, si es cuatro, retorna condicionRangoCuatro
     sino retorna 10
    */int danoPorRango(int filaAtacar , int columnaAtacar , int filaAtacado , int columnaAtacado );

    //PRE: valorAtaque y puntero a personaje valido.
    //POST: Dependiendo del getElemento del personaje, modifica a valorAtaque y lo retorna.
    int danoAtaque(int valorAtaque , Personaje* personajeAtacar);

    //pre: variable diferenciaCol valida.
    //post: dependiendo del valor de diferenciaCol retorna un entero.
    int condicionRangoDos(int diferenciaCol);

    //pre: variable diferenciaCol valida.
    //post: dependiendo del valor de diferenciaCol retorna un entero.
    int condicionRangoCuatro(int diferenciaCol);



};



#endif //ATAQUE_TIERRA_H