#ifndef TIERRA_H
#define TIERRA_H

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

    //PRE:
    //POST: IMPRIME LOS ATRIBUTOS DE UN PERSONAJE Y DE QUE ELEMENTO ES.
    void mostrarPersonajeEspecifico();

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

};

#endif // TIERRA_H
