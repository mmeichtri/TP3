#ifndef AIRE_H
#define AIRE_H
#include "personaje.h"

class Aire : public Personaje {
public:
    // PRE : NOMBRE , ESCUDO CON VALOR ENTRE 0 A 2 Y VIDA CON VALOR ENTRE 10 A 100, VALIDOS.
    // POST: CONTRUYE UN OBJETO Aire, QUE HEREDA DE LA CLASE PERSONAJE.
    Aire(string nombre,int escudo,int vida);

    //PRE:
    //POST: IMPRIME QUE ESTE TIPO DE PERSONAJE NO NECESITAN ALIMENTARSE.
    void alimentarse();

    //PRE:
    //POST: MUESTRA LOS ATRIBUTOS DE UN PERSONAJE Y EL ELEMENTO.
    void mostrarPersonajeEspecifico();

    //PRE:
    //POST : DESTRUYE UN PERSONAJE DE TIPO AIRE.
    ~Aire();
};



#endif // AIRE_H
