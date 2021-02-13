//
// Created by jose on 2/2/21.
//

#ifndef ATAQUE_TIERRA_H
#define ATAQUE_TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {
public:
    // PRE: NOMBRE VALIDO , VIDA CON VALOR ENTRE 10 Y 100 Y ESCUDO CON VALOR 0 A 2 VALIDOS.
    // POST: CONSTRUYE UN OBJETO Tierra CON DATOS VALIDOS.
    Tierra(string nombre,int escudo,int vida);

    // PRE:
    /* POST:  SI verificarEnergia() ES VERDADERO, AUMENTA LA ENERGIA EN 8 PUNTOS
     * Y LLAMA A imprimirALimentos, SI ES FALSO SE LO INDICA AL USUARIO.*/
    void alimentarse();


   void defenderse();

   //PRE: PUNTERO A PERSONAJE VALIDO.
   //POST: RETORNA EL DANO TOTAL CAUSADO AL PERSONAJE ATACADO, QUE ES LA SUMA DEL DANO POR RANGO Y EL DANO POR ELEMENTO.
   int atacar(Personaje* personajeAtacado);

   //PRE:
   //POST:
    bool energiaAtaque();

    //PRE:
    //POST:
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

    //PRE: VALOR DE FILA Y COLUMNA  A ATACAR , Y FILA Y COLUMNA DEL QUE ATACA VALIDOS.
    //POST: DEPENDIENDO AL VALOR QUE DEN LA DIFERENCIA DE FILAS Y LA DIFERENCIA DE COLUMNAS , RETORNA EL VALOR DEL DANO.
    int danoPorRango(int filaAtacar , int columnaAtacar , int filaAtacado , int columnaAtacado );

    //PRE: VALOR DE ATAQUE Y PUNTERO A PERSONAJE VALIDO
    //POST: DEPENDIENDO DEL ELEMENTO DEL PERSONAJE A ATACAR AUMENTA EL VALOR DEL ATAQUE O LO DEJA IGUAL
    int danoAtaque(int valorAtaque , Personaje* personajeAtacar);



};



#endif //ATAQUE_TIERRA_H
