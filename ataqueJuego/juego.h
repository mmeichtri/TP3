//
// Created by jose on 8/2/21.
//

#ifndef ATAQUE_JUEGO_H
#define ATAQUE_JUEGO_H


#include "vInterfazUsuario.h"
#include "personaje.h"
#include "agua.h"
#include "fuego.h"
#include "aire.h"
#include "tierra.h"

class Juego {
private:
    VInterfazUsuario vista;
public:
    //PRE : PUNTERO Y VECTOR A PUNTEROS DE PERSONAJE VALIDOS, PUNTERO A PERSONAJE VALIDO.
    //POST: DEPENDIENDO DEL PERSONAJE RELIZARA UN ATAQUE
    void ataque(Personaje* personajeTurno, Personaje* victima[3]);

    //PRE : VECTORES DE ATACANTE Y VICTIMA VALIDOS
    //POST : SEGUN LA OPCION PASADA POR TECLADO REALIZA UNA ACCION.
    void menuJuegoAccion(Personaje* usuario[3],Personaje* contrario[3], Personaje* );

    //PRE: VECTOR DE PUNTERO PERSONAJE VALIDOS
    //POST: DEVUELVE EL PERSONAJE SELECCIONADO POR TECLADO
    Personaje* buscarPersonaje(Personaje* vPersonaje[3]);

    //PRE:PUNTERO PERSONAJE Y VECTOR DE PERSONAJE VALIDOS
    //POST: REALIZA UN ATAQUE DEPENDIENDO DEL ELEMNTO QUE SEA LA VICTIMA
    void ataquePersonajes(Personaje* atacante , Personaje* victima);

    //PRE:
    //POST:
    void ataquePersonajeAgua(Personaje* atacante, Personaje* victimas[3]);

    void defenderse(Personaje* personajeTurno,Personaje* aliados[3]);

    void menuMoverAlimentarse(Personaje* personajeTurno);

   // void moverse(Grafo* graf , Personaje* personajeTurno);

   bool equipoSinVida(Personaje* equipo[3]);

   void asignarCasilla(Personaje* personajeTurno);

   void turno(Personaje* aliados[3], Personaje* enemigos[3]);

   void jugar(Personaje* jugadorUno[3],Personaje* jugadorDos[3]);

 int restarEnergiaAtaque(Personaje* personajeTurno);

};

#endif //ATAQUE_JUEGO_H
