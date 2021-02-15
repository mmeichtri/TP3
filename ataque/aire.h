//
// Created by jose on 2/2/21.
//

#ifndef ATAQUE_AIRE_H
#define ATAQUE_AIRE_H

#include "personaje.h"

class Aire : public Personaje {
private:

    //PRE: PUNTERO A PERSONAJE VALIDO
    //POST: DEPENDIENDO DEL ELEMENTO DEL PERSONAJE A ATACAR, RETORNA CUANTO DANO LE HACE A ESE PERSONAJE.
    int danoAtaque(Personaje* personajeAtacar);

public:
    // PRE : NOMBRE , ESCUDO CON VALOR ENTRE 0 A 2 Y VIDA CON VALOR ENTRE 10 A 100, VALIDOS.
    // POST: CONTRUYE UN OBJETO Aire, QUE HEREDA DE LA CLASE PERSONAJE.
    Aire(string nombre,int escudo,int vida);

    //PRE:
    //POST: RETORNA EL NOMBRE DEL ELEMENTO.
    string getElemento();

    //PRE:
    //POST: IMPRIME QUE ESTE TIPO DE PERSONAJE NO NECESITAN ALIMENTARSE.
    void alimentarse();

     void defenderse(int fila , int columna);

  //PRE: PUNTERO A PERSONAJE VALIDO
  //POST:RETORNA EL VALOR DEL DANO AL PERSONAJE ATACADO PROVENIENTE DE LA FUNCION danoAtaque.
 int atacar(Personaje* personajeAtacado);

  //PRE:
  //POST:
    bool energiaAtaque();

    //PRE:
    //POST:
    bool energiaDefensa();


    //PRE:
    //POST : DESTRUYE UN PERSONAJE DE TIPO AIRE.
    ~Aire();
};

#endif //ATAQUE_AIRE_H
