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
    //POST: retorna el nombre del elemento
    string getElemento();

    //PRE:
    //POST: IMPRIME QUE ESTE TIPO DE PERSONAJE NO NECESITAN ALIMENTARSE.
    void alimentarse();


  //PRE: vector a personaje valido.
  /*POST: le resta 8 de eergia , recorre las posciones de personajeAtacado y si es dintinta de null , llama a
  danoAtaque y quitarVida.*/
 void atacar(Personaje** personajeAtacado);

  //PRE:
  //POST: retorna true si energia >= 8 , false en caso contrario.
    bool energiaAtaque();

    //PRE:
    //POST: si energia >= 15 le quita la energia y retorna true , false en contrario.
    bool energiaDefensa();

    //pre:
    //post: le suma 5 de energia.
    void modificarPorTurno();

    //PRE:
    //POST : DESTRUYE UN PERSONAJE DE TIPO AIRE.
    ~Aire();
};

#endif //ATAQUE_AIRE_H