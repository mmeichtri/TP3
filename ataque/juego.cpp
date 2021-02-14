
#include "juego.h"


void Juego::menuElegirPersonaje(Personaje** jugador, int posicion) {
    vista.menuJugadores();
    int opcion = vista.comprobarOpcion(1,3);
    do {
        switch (opcion) {
            case 1 :
                //especificacion de personaje
                break;
            case 2:
                //mostrar nombres personaje
                break;
            case 3:
                //elegir personaje
                break;

        }
    }while(opcion < 3);
}

void Juego::turnosSeleccion(Personaje** jugadorUno, Personaje** jugadorDos) {
    for(int i = 0; i < MAXJUGADORES;i++){
        menuElegirPersonaje(jugadorUno, i);
        menuElegirPersonaje(jugadorDos,i);
    }
}

void Juego::elegirPersonaje(Personaje** jugador, int posicion) {
    string nombre = vista.ingresarString("nombre del personaje: ");
    //buscar en el diccionario y traer el puntero a personaje.
    //jugador[posicion] = lo traido del diccionario.
}

void Juego ::seleccionarPosiciones(Personaje **jugadorUno, Personaje **jugadorDos) {

    Personaje** primerTurno = turnoRandom(jugadorUno,jugadorDos);
    Personaje** segundoTurno = perdedorTurno(jugadorUno,jugadorDos,primerTurno);

    for(int i = 0; i < MAXJUGADORES; i++){
        asignarCasilla(primerTurno[i]);
        asignarCasilla(segundoTurno[i]);
    }
}

void Juego :: asignarCasilla(Personaje *personajeTurno) {

    vista.imprimirLinea("Escoja la posicion donde quiera que este el personaje: ");
    int fila = vista.leerFilaOColumna("fila");
    int columna = vista.leerFilaOColumna("columna");
    personajeTurno->cambiarFYC(fila,columna);
}

Personaje** Juego ::turnoRandom(Personaje** jugadorUno, Personaje** jugadorDos) {

    int personajeRandom = rand()%2 + 1;

    if(personajeRandom == PRIMERO)
        return jugadorUno;
    else
        return jugadorDos;
}

Personaje** Juego ::perdedorTurno(Personaje **jugadorUno, Personaje **jugadorDos, Personaje **seleccionado) {
    if(seleccionado[0] == jugadorUno[0])
        return jugadorDos;
    else
        return jugadorUno;
}

void Juego ::jugar(Personaje** jugadorUno, Personaje** jugadorDos) {

    Personaje** primerTurno = turnoRandom(jugadorUno,jugadorDos);
    Personaje** segundoTurno = perdedorTurno(jugadorUno,jugadorDos,primerTurno);
    bool equipo1;
    bool equipo2;

    do{
        turno(primerTurno,segundoTurno);
        turno(segundoTurno,primerTurno);
        equipo1 = equipoSinVida(jugadorUno);
        equipo2 = equipoSinVida(jugadorDos);
    }while(!equipo1  &&  !equipo2);
}

bool Juego :: equipoSinVida(Personaje** equipo) {
    bool sinVida = true;
    for(int i = 0; i < MAXJUGADORES ; i++){
        if(equipo[i]->comprobarVida())
            sinVida = false;
    }
    return sinVida;
}

void Juego ::turno(Personaje** aliados, Personaje** enemigos) {

    for(int i = 0; i < MAXJUGADORES; i++){
        if(aliados[i]->comprobarVida()) {
            vista.imprimirLinea("Es el turno de: ");
            aliados[i]->mostrarPersonaje();
            menuMoverAlimentarse(aliados[i]);
            menuJuegoAccion(aliados, enemigos, aliados[i]);
            condicionEspecialPersonaje(aliados[i]);
        }
    }
}

void Juego ::condicionEspecialPersonaje(Personaje *personajeTurno) {

    if(personajeTurno->getElemento() == "aire")
        personajeTurno->sumarEnergia(5);
    else if(personajeTurno->getElemento() == "tierra"){
        if(personajeTurno->sinEnergia())
            personajeTurno->restarVida(5);
    }

}

void Juego :: menuJuegoAccion(Personaje** usuario, Personaje** contrario, Personaje* personajeTurno) {
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
         //moverse
            break;
        case 3:
            //pasar opcion
            break;
    }
}


void Juego ::ataque(Personaje* atacante, Personaje** victima) {

    if(atacante -> energiaAtaque()){
        if(atacante -> getElemento() == "agua")
            ataquePersonajeAgua(atacante , victima);
        else
            recorrerRivalAtaque(victima,atacante);

    }else
        vista.imprimirLinea("El personaje no tiene suficiente energia para atacar ");
}

void Juego ::recorrerRivalAtaque(Personaje **rival ,Personaje* atacante) {

    for (int i = 0; i < MAXJUGADORES; i++) {
        if (rival[i]->comprobarVida())
            ataquePersonajes(atacante, rival[i]);
    }
}

void Juego :: ataquePersonajes(Personaje* atacante , Personaje* victima) {

    int ataque = atacante->atacar(victima);
    victima->restarVida( victima->defensaEscudo(ataque));
}


void Juego :: ataquePersonajeAgua(Personaje* atacante, Personaje** victimas){
    bool encontrado = false;
    int pos = 0;
    int  fila = vista.leerFilaOColumna("fila");
    int columna = vista.leerFilaOColumna("columna");

    while(pos < MAXJUGADORES && !encontrado){
        if(victimas[pos]->obtenerFila() == fila && victimas[pos]->obtenerColumna() == columna){
            encontrado = true;
            ataquePersonajes(atacante,victimas[pos]);
        }
        pos++;
    }
}

void Juego :: defenderse(Personaje* personajeTurno) {

    if (personajeTurno->energiaDefensa())
        condicionDefensa(personajeTurno);
    else
        vista.imprimirLinea("error el personaje no tiene energia para defenderse");
}

void Juego ::condicionDefensa(Personaje *personajeTurno) {

    // va aca o va en metodo especifico de cada clase?
    if(personajeTurno->getElemento() == "agua")
        defensaAgua(personajeTurno);
    else if(personajeTurno->getElemento() == "aire")
        defensaAire(personajeTurno);
    else if(personajeTurno->getElemento() == "tierra")
        personajeTurno->modificarEscudo(personajeTurno->getEscudo() + 2);
    else
        personajeTurno->sumarEnergia(10);
}

void Juego ::defensaAire(Personaje *personajeTurno) {
    //tengo que hacer que se mueva con camino minimo
}

void Juego ::defensaAgua(Personaje *personajeTurno ) {
    personajeTurno->sumarVida(50);
    //for(int i = 0; i < MAXJUGADORES ; i++)
    // le suma vida a los aliados +10
}


void Juego ::moverse(grafo* graf, Personaje *personajeTurno) {
    //falta mostratle al usuario que o no se movio por energia o porque hay un personaje en ese casillero
    int desicionUsuario;
    bool seMovio;
    do{
        personajeTurno->mostrarPersonaje();
        int fila = vista.leerFilaOColumna("fila");
        int columna = vista.leerFilaOColumna("columna");
        int perdidaCamino = graf->caminoMinimo(personajeTurno->obtenerFila(), personajeTurno->obtenerColumna(), fila,
                                               columna, personajeTurno->getElemento());
        seMovio = condicionMoverse(personajeTurno,perdidaCamino,fila,columna);
        desicionUsuario = errorMoverse(seMovio);
    }while(desicionUsuario != SALIR);
}

bool Juego ::condicionMoverse(Personaje *personajeTurno, int caminoMinimo, int fila , int col) {
    //falta funcion si existe personaje en una casilla o no
    bool seMovio = false;
     if (personajeTurno->tieneEnergia(caminoMinimo)){
            personajeTurno->cambiarFYC(fila, col);
            personajeTurno->restarEnergia(caminoMinimo);
            seMovio = true;
        }
     return seMovio;
}

int Juego::errorMoverse(bool seMovio) {

    int desicion;
    if(seMovio == false){
        vista.imprimirLinea("error no se pudo mover al personaje ");
        vista.imprimirLinea("desea intentarlo nuevamente 1 para si 2 para no ");
        desicion = vista.comprobarOpcion(1,2);
    }else{
        vista.imprimirLinea("se movio el personaje correctamnte ");
        desicion = SALIR;
    }
    return desicion;
}




