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


   //PRE: PUNTERO A PERSONAJE VALIDO
   //POST: SI EL PERSONAJE A ATACAR ESTA EN UN RANGO MENOR O IGUAL A DOS FILAS , RETORNA EL DANO QUE HACE, SINO RETORNA 0.
   int atacar(Personaje* personajeAtacado);

   //PRE:
   //POST: DEVUELVE EL NOMBRE DEL ELEMENTO DEL PERSONAJE
   string getElemento();

   //PRE:
   //POST:
    bool energiaAtaque();

    //PRE:
    //POST:
    bool energiaDefensa();

    //PRE:
    //POST: SI LA ENERGIA DEL PERSONAJE ES CERO LE QUITA 5 PUNTOS DE VIDA
    void sinEnergia();

    //PRE :
    //POST : DESTRUYE UN OBJETO DE TIPO FUEGO.
    ~Fuego();
private:

    // PRE :
    /* POST : DEVUELVE VERDADERO SI LA vida+15 ES MENOR QUE vmax. FALSO EN CASO CONTRARIO.*/
    bool verificarVida();

    // PRE :
    // POST : IMPRIME EL NOMBRE DEL PERSONAJE, SU ALIMENTO, Y NUMERO DE PUNTOS DE VIDA QUE AUMENTO.
    void imprimirAlimentos();

    // PRE: VARIABLES INT filaAtaque Y filaAtacar CORRECTAMENTE CREADAS
    //POST: DEVUELVE TRUE SI LA DIFERENCIAS DE LAS DOS VARIABLES ESTA EN EL RANGO -2 <= diferencaFilas <= 2

    bool comprobarFilas(int filaAtaque , int filaAtacar);

    // PRE: PUNTERO A PERSONAJE VALIDO
    //POST: DEPENDIENDO DEL ELEMENTO DEL PERSONAJE A ATACAR RETORNA EL VALOR DEL DANO.
    int danoAtaque(Personaje * personajeAtacar);

};



#endif //ATAQUE_FUEGO_H
