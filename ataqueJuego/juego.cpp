//
// Created by jose on 8/2/21.
//

#include "juego.h"

void Juego :: menuJuegoAccion(Personaje* usuario[3], Personaje* contrario[3], Personaje* personajeTurno) {
    vista.segundoMenuTurno();
    int opcion = vista.comprobarOpcion(1,3);

    switch(opcion){
        case 1:

            break;
        case 2:
            ataque(personajeTurno,contrario);
            break;
        case 3:
            break;
    }
}

void Juego :: menuMoverAlimentarse(Personaje *personajeTurno) {
    vista.primerMenuTurno();
    int opcion = vista.comprobarOpcion(1,3);

    switch(opcion){
        case 1:
            personajeTurno -> alimentarse();
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void Juego ::ataque(Personaje* atacante, Personaje* victima[3]) {

    if(atacante -> energiaAtaque()){
        if(atacante -> getElemento() == "agua"){
            ataquePersonajeAgua(atacante , victima);
            atacante->restarEnergia(5);
        }
        else{
            atacante->restarEnergia(restarEnergiaAtaque(atacante));
            for(int i = 0; i < 3; i++)
                ataquePersonajes(atacante,victima[i]);
        }
    }else
        vista.imprimirLinea("El personaje no tiene suficiente energia para atacar ");
}

int Juego ::restarEnergiaAtaque(Personaje *personajeTurno) {
    if(personajeTurno->getElemento() == "tierra")
        return 6;
    else if(personajeTurno->getElemento() == "aire")
        return 8;
    else
        return 5;
}

void Juego :: ataquePersonajes(Personaje* atacante , Personaje* victima) {

    int ataque = atacante->atacar(victima);
    victima->modificarVida(victima->obtenerVida() - victima->defensaEscudo(ataque));
}


void Juego :: ataquePersonajeAgua(Personaje* atacante, Personaje* victimas[3]){
    bool encontrado = false;
    int pos = 0;
    int  fila = vista.leerFilaOColumna("fila");
    int columna = vista.leerFilaOColumna("columna");

    while(pos < 3 && !encontrado){
        if(victimas[pos]->obtenerFila() == fila && victimas[pos]->obtenerColumna() == columna){
            encontrado = true;
            ataquePersonajes(atacante,victimas[pos]);
        }
        pos++;
    }
}

/*void Juego ::moverse(Grafo* graf, Personaje *personajeTurno) {
    vista.imprimirLinea("Ingrese fila o columna a donde quiere mover el personaje : ");
    int fila = vista.leerFilaOColumna("fila");
    int columna = vista.leerFilaOColumna("columna");

}*/

bool Juego :: equipoSinVida(Personaje* equipo[3]) {
    bool sinVida = true;
    for(int i = 0; i < 3 ; i++){
        if(equipo[i]->comprobarVida())
            sinVida = false;
    }
    return sinVida;
}

void Juego :: asignarCasilla(Personaje *personajeTurno) {
    vista.imprimirLinea("Escoja la posicion donde quiera que este el personaje: ");
    int fila = vista.leerFilaOColumna("fila");
    int columna = vista.leerFilaOColumna("columna");
    personajeTurno->cambiarFYC(fila,columna);
}

void Juego ::turno(Personaje *aliados[3], Personaje* enemigos[3]) {
    
      for(int i = 0; i < 3; i++){
          if(aliados[i]->comprobarVida()) {
              vista.imprimirLinea("Es el turno de: ");
              aliados[i]->mostrarPersonaje();
              menuMoverAlimentarse(aliados[i]);
              menuJuegoAccion(aliados, enemigos, aliados[i]);
          }
      }
}

void Juego ::jugar(Personaje* jugadorUno[3], Personaje* jugadorDos[3]) {
//solo una prueba.
bool equipo1;
bool equipo2;
    do{
        turno(jugadorUno,jugadorDos);
        turno(jugadorDos,jugadorUno);
        equipo1 = equipoSinVida(jugadorUno);
        equipo2 = equipoSinVida(jugadorDos);

    }while(!equipo1  &&  !equipo2);

}