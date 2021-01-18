#ifndef FUEGO_H
#define FUEGO_H
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

    //PRE:
    //POST: IMPRIME EL ELEMENTO Y TODOS LOS ATRIBUTOS DEL PERSONAJE.
    void mostrarPersonajeEspecifico();

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
};




#endif // FUEGO_H
