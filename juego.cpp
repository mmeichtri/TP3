
#include "juego.h"

Juego :: Juego(Grafo* graf) {
    this -> graf = graf;
inicializarJugadores();
}

void Juego ::inicializarJugadores() {
    for(int i = 0; i < MAXPERSONAJES ; i++){
        jugadorDos[i] = nullptr;
        jugadorUno[i] = nullptr;
    }
}
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

void Juego::turnosSeleccion() {
    //falta pre y post condiciones
    for(int i = 0; i < MAXPERSONAJES;i++){
        menuElegirPersonaje(jugadorUno, i);
        menuElegirPersonaje(jugadorDos,i);
    }
}

void Juego::elegirPersonaje() {
    // falta pre y post condicion
 Personaje* hola = new Fuego("el dodo",0,100);
  Personaje* hello = new  Tierra("la rock", 2, 100);
   hola->cambiarFYC(1,7);
    hello->cambiarFYC(0,0);
    jugadorUno[0] = hola;
    jugadorDos[0] = hello;
}

void Juego ::seleccionarPosiciones() {

    Personaje** primerTurno = turnoRandom();
    Personaje** segundoTurno = perdedorTurno(primerTurno);

    for(int i = 0; i < MAXPERSONAJES; i++){
        asignarCasilla(primerTurno[i]);
        asignarCasilla(segundoTurno[i]);
    }
}

void Juego :: asignarCasilla(Personaje *personajeTurno) {
    bool estaVacia;
    do{
        vista.imprimirLinea("Escoja la posicion donde quiera que este el personaje: ");
        int fila = vista.leerFilaOColumna("fila");
        int columna = vista.leerFilaOColumna("columna");
        personajeTurno->cambiarFYC(fila,columna);
        estaVacia = casillaVacia(fila,columna);
    }while(!estaVacia);

}

Personaje** Juego ::turnoRandom() {

    int personajeRandom = rand()%2 + 1;

    if(personajeRandom == PRIMERO)
        return jugadorUno;
    else
        return jugadorDos;
}

Personaje** Juego ::perdedorTurno( Personaje **seleccionado) {
    if(seleccionado[0] == jugadorUno[0])
        return jugadorDos;
    else
        return jugadorUno;
}

void Juego ::jugar() {
//falta pre y post condicion.
   elegirPersonaje();

    Personaje** primerTurno = turnoRandom();
    Personaje** segundoTurno = perdedorTurno(primerTurno);

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
    int pos = 0;
    bool sinVida = true;
    while(pos < MAXPERSONAJES && sinVida){
        if(equipo[pos] != nullptr)
            sinVida = false;
    pos++;
    }
    return sinVida;
}

void Juego ::turno(Personaje** aliados, Personaje** enemigos) {

    for(int i = 0; i < MAXPERSONAJES; i++){
        vidaPersonaje(aliados[i],i,aliados);
        if(aliados[i] != nullptr) {
            condicionEspecialPersonaje(aliados[i]);
            vista.imprimirLinea("Es el turno de: ");
            aliados[i]->mostrarPersonaje();
            menuMoverAlimentarse(aliados[i]);
            menuJuegoAccion(aliados, enemigos, aliados[i]);
        }
    }
}
void Juego ::vidaPersonaje(Personaje *personajeTurno ,int posicion , Personaje** equipoPersonaje) {
    if(!(personajeTurno->tieneVida())){
        delete personajeTurno;
        equipoPersonaje[posicion] = nullptr;
    }
}

void Juego ::condicionEspecialPersonaje(Personaje *personajeTurno) {
    personajeTurno->modificarPorTurno();
}

void Juego :: menuJuegoAccion(Personaje** usuario, Personaje** contrario, Personaje* personajeTurno) {
    vista.segundoMenuTurno();
    int opcion = vista.comprobarOpcion(1,3);

    switch(opcion){
        case 1:
            defenderse(personajeTurno, usuario);
            break;
        case 2:
            ataque(personajeTurno,contrario);
            break;
        case 3:
            //pasarOpcion
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
           moverse(personajeTurno);
            break;
        case 3:
            //pasar opcion
            break;
    }
}

void Juego ::ataque(Personaje* atacante, Personaje** victima) {

    if(atacante -> energiaAtaque()){
        atacante->atacar(victima);
    }else
        vista.imprimirLinea("El personaje no tiene suficiente energia para atacar ");
}


void Juego :: defenderse(Personaje* personajeTurno,Personaje** aliados) {

    if (personajeTurno->energiaDefensa())
        condicionDefensa(personajeTurno, aliados);
    else
        vista.imprimirLinea("error el personaje no tiene energia para defenderse");
}

void Juego ::condicionDefensa(Personaje *personajeTurno,Personaje** aliados) {

    // va aca o va en metodo especifico de cada clase?
    if(personajeTurno->getElemento() == "agua")
        defensaAgua(personajeTurno,aliados);
    else if(personajeTurno->getElemento() == "aire")
        defensaAire(personajeTurno);
    else if(personajeTurno->getElemento() == "tierra")
        personajeTurno->modificarEscudo(personajeTurno->getEscudo() + 2);
    else
        personajeTurno->sumarEnergia(10);
}

void Juego ::defensaAire(Personaje *personajeTurno) {
    bool cambioUbicacion = false;
    do{
        personajeTurno->mostrarPersonaje();
        int fila = vista.leerFilaOColumna("fila");
        int columna = vista.leerFilaOColumna("columna");
        if(casillaVacia(fila,columna)){
        personajeTurno->cambiarFYC(fila,columna);
        cambioUbicacion = true;
        }
         else
             vista.imprimirLinea(" error ese casillero ya esta ocupado");
    }while(!cambioUbicacion);

}

void Juego ::defensaAgua(Personaje *personajeTurno, Personaje** aliados) {

    personajeTurno->sumarVida(40);
    for(int i = 0; i < MAXPERSONAJES ; i++){
        if(personajeTurno != nullptr)
            aliados[i]->sumarVida(10);
    }
}

void Juego ::moverse(Personaje *personajeTurno) {

    int desicionUsuario;
    do{
        int fila = vista.leerFilaOColumna("fila");
        int columna = vista.leerFilaOColumna("columna");
        int perdidaCamino = graf->caminoMinimo(personajeTurno->obtenerFila(), personajeTurno->obtenerColumna(), fila,
                                               columna, personajeTurno);
        desicionUsuario = condicionMoverse(personajeTurno,perdidaCamino,fila,columna);

    }while(desicionUsuario != SALIR);
}

bool Juego::casillaVacia( int fila, int columna) {
    bool estaVacia = true;
    int pos = 0;
    while(pos < MAXPERSONAJES && estaVacia){
        if(jugadorUno[pos]->obtenerFila() == fila && jugadorUno[pos]->obtenerColumna() == columna)
            estaVacia = false;
        if(jugadorDos[pos]->obtenerFila() == fila && jugadorDos[pos]->obtenerColumna() == columna)
            estaVacia = false;
        pos++;
    }
    return estaVacia;
}

int  Juego ::condicionMoverse(Personaje *personajeTurno, int caminoMinimo, int fila , int col) {

    int opcionUsuario = SALIR;

     if (personajeTurno->tieneEnergia(caminoMinimo) && casillaVacia(fila,col)){
            personajeTurno->cambiarFYC(fila, col);
            personajeTurno->restarEnergia(caminoMinimo);
            vista.imprimirLinea(" se movio el personaje correctamente ");
     }
     else if(personajeTurno->tieneEnergia(caminoMinimo) && !casillaVacia(fila,col)){
         vista.imprimirLinea(" Error la casilla donde se quiere mover al personaje esta ocupada ");
         opcionUsuario = errorMoverse();
     }
     else{
         vista.imprimirLinea(" Error el personaje no tiene energia para atacar ");
         opcionUsuario = errorMoverse();
     }
     return opcionUsuario;
}

int Juego::errorMoverse() {
    int opcionUsuario;
    vista.imprimirLinea("desea intentar mover el personaje nuevamente 1 para si 2 para no ");
    opcionUsuario = vista.comprobarOpcion(1,2);
    return opcionUsuario;
}

Juego ::~Juego() {
    for(int i = 0; i < MAXPERSONAJES ; i++){
        if(jugadorUno[i] != nullptr)
             delete jugadorUno[i];
        if(jugadorDos[i] != nullptr)
            delete jugadorDos[i];
    }
}
