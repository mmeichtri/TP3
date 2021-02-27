#include "juego.h"


Juego :: Juego(Grafo* graf,Matriz* matriz,Diccionario* diccionario) {
    this -> graf = graf;
    this -> matriz = matriz;
    this -> diccionario = diccionario;
	inicializarJugadores();
}

void Juego ::inicializarJugadores() {
    for(int i = 0; i < MAXPERSONAJES ; i++){
        jugadorDos[i] = nullptr;
        jugadorUno[i] = nullptr;
    }
}

void Juego ::iniciarJuegoCargado() {
    Personaje** primerTurno = leerJugadorGuardado(personajeGuardo);
    Personaje**  turnoDos = segundoTurno(primerTurno);
    jugar(primerTurno, turnoDos);
}

void Juego ::setPersonajeGuardo(int personajeGuardo) {
    this -> personajeGuardo = personajeGuardo;
}



bool Juego ::guardarPartida(int jugadorQueGuardo) {
    vista.imprimirLinea( "¿Desea guardar la partida? \n1) sí \n2) no \n");
    int comprobarOpcion =  vista.comprobarOpcion(1, 2, SI_NO);
    
    if(comprobarOpcion == 1){
        ArchivoTexto(jugadorQueGuardo);
        return true;
    }
    return false;
}

void Juego ::ArchivoTexto(int jugadorQueGuardo) {
    ofstream archivo;
    archivo.open("partida.csv");
    archivo << jugadorQueGuardo;

    for(int i = 0; i < MAXPERSONAJES ; i++){
        archivo << jugadorUno[i]->getElemento()<<","\
        <<jugadorUno[i]->getNombre()<<","\
        <<jugadorUno[i]->getEscudo()<<","\
        <<jugadorUno[i]->getVida()<<","\
        <<jugadorUno[i]->getEnergia()<<","\
        <<jugadorUno[i]->getFila()<<","\
        <<jugadorUno[i]->getColumna()<<","\
        <<jugadorUno[i]->devolverCondicionEspecial()<<endl;
    }
    for(int i = 0; i < MAXPERSONAJES ; i++){
        archivo << jugadorDos[i]->getElemento()<<","\
        <<jugadorDos[i]->getNombre()<<","\
        <<jugadorDos[i]->getEscudo()<<","\
        <<jugadorDos[i]->getVida()<<","\
        <<jugadorDos[i]->getEnergia()<<","\
        <<jugadorDos[i]->getFila()<<","\
        <<jugadorDos[i]->getColumna()<<","\
        <<jugadorDos[i]->devolverCondicionEspecial()<<endl;
    }

}

void Juego::ContinuarPartida() {
    remove("partida.csv");
    Personaje** primerTurno = leerJugadorGuardado(personajeGuardo);
    Personaje** turnoDos = segundoTurno(primerTurno);
    jugar(primerTurno,turnoDos);
}


Personaje** Juego::leerJugadorGuardado(int jugador) {
    if(jugador == 1 )
        return jugadorUno;
    else
        return jugadorDos;
}


void Juego::leerPersonajesArchivo(Personaje * personaje , int contador) {

    if(contador < 3)
        jugadorUno[contador] = personaje;
    else{
        contador = contador - 3;
        jugadorDos[contador] = personaje;
    }

}

void Juego ::iniciarJuego(Personaje** &primero, Personaje** &segundo) {
    vista.imprimirLinea( " \n\nBienvenido al juego ", __TEXT_GRN__);
    turnosSeleccion();
    seleccionarPosiciones();
    primero = turnoRandom();
    segundo = segundoTurno(primero);
}

void Juego::menuElegirPersonaje(Personaje** jugador, int posicion) {

    int opcion;
    do {
        vista.menuJugadores();
        opcion = vista.comprobarOpcion(1,3, JUGADOR);
        switch (opcion) {
            case 1 :
                mostrarPersonajeEspecifico();
                break;
            case 2:
                mostrarPersonajes();
                break;
            case 3:
                elegirPersonaje(jugador,posicion);
                break;

        }
    }while(opcion < 3);
}

void Juego ::mostrarPersonajes() {
    diccionario->mostrar();
}

void Juego ::mostrarPersonajeEspecifico() {

    vista.imprimirLinea("\nEstos son los personajes disponibles: ");
    diccionario->mostrar();
    string nombre = vista.ingresarString("nombre");
    Personaje* personajeMostrar = diccionario->buscar(nombre);
    if(personajeMostrar != nullptr)
        personajeMostrar->mostrarPersonaje();
    else
        vista.noEncontro("nombre");
}

void Juego::turnosSeleccion() {
    //falta pre y post condiciones
    for(int i = 0; i < MAXPERSONAJES;i++){
        vista.imprimirLinea("\nEs el turno del jugador 1", __TEXT_BG_BLU__);
        menuElegirPersonaje(jugadorUno, i);
        vista.imprimirLinea( "\nEs el turno del jugador 2", __TEXT_BG_GRN__);
        menuElegirPersonaje(jugadorDos,i);
    }
}

void Juego::elegirPersonaje(Personaje** seleccionJugador , int posicion) {

	bool nombreCorrecto = false;
	string nombre;
	vista.imprimirLinea("\n");
	diccionario->mostrar();
	 do{
		nombre = vista.ingresarString("nombre");
		Personaje* personajeElegir = diccionario->buscarBorrar(nombre);
		if(personajeElegir != nullptr){
			seleccionJugador[posicion] = personajeElegir;
			nombreCorrecto = true;
		}
		else				
			vista.noEncontro("nombre");
	 }while(!nombreCorrecto);

}

void Juego ::seleccionarPosiciones() {

    Personaje** primerTurno = turnoRandom();
    Personaje** turnoDos = segundoTurno(primerTurno);

    for(int i = 0; i < MAXPERSONAJES; i++){
        vista.imprimirLinea("\nEs el turno del jugador 1 ", __TEXT_BG_BLU__);
        asignarCasilla(primerTurno[i]);
        vista.imprimirLinea( "\nEs el turno del jugador 2", __TEXT_BG_GRN__);
        asignarCasilla(turnoDos[i]);
    }
}

void Juego::asignarCasilla(Personaje *personajeTurno) {
    bool estaVacia = false;
    do{
        vista.imprimirLinea(personajeTurno->getNombre());
        vista.imprimirLinea("\nEscoja la posicion donde quiera que este el personaje: ");
        int fila = vista.leerFilaOColumna("fila");
        int columna = vista.leerFilaOColumna("columna");
        estaVacia = casillaVacia(fila,columna);
        if(estaVacia){
            personajeTurno->cambiarFYC(fila,columna);
            matriz->setHayPersonaje(fila,columna,true);
            estaVacia = true;
        }
        else
            vista.imprimirLinea("\nERROR: esa casilla esta ocupada", __TEXT_YLW__);

    }while(!estaVacia);

}

Personaje** Juego::turnoRandom() {

    int personajeRandom = rand()%2 + 1;

    if(personajeRandom == PRIMERO)
        return jugadorUno;
    else
        return jugadorDos;
}

Personaje** Juego::segundoTurno( Personaje **seleccionado) {
    if(seleccionado[0] == jugadorUno[0])
        return jugadorDos;
    else
        return jugadorUno;
}

void Juego::jugar(Personaje** primero , Personaje** segundo) {
    bool equipo1;
    bool equipo2;
    do{
        if (guardarPartida(1))
        	break;
        turno(primero, segundo, 1);
        matriz->mostrar(primero, segundo);
        if(guardarPartida(2))
        	break;
        turno(segundo, primero, 2);
        matriz->mostrar(primero, segundo);
        equipo1 = equipoSinVida(jugadorUno);
        equipo2 = equipoSinVida(jugadorDos);
    }while(!equipo1  ||  !equipo2);
}


bool Juego::equipoSinVida(Personaje** equipo) {
    int pos = 0;
    bool sinVida = true;
    while(pos < MAXPERSONAJES && sinVida){
        if(equipo[pos] != nullptr)
            sinVida = false;
    	pos++;
    }
    return sinVida;
}

void Juego::turno(Personaje** aliados, Personaje** enemigos, int jugador) {

    for(int i = 0; i < MAXPERSONAJES; i++){
        if(aliados[i]->tieneVida()) {
            condicionEspecialPersonaje(aliados[i]);
            vista.imprimirLinea("\nEs el turno de: \n\t");
            aliados[i]->mostrarPersonaje(jugador);
            vista.saltarLinea();
            menuMoverAlimentarse(aliados[i]);
            menuJuegoAccion(aliados, enemigos, aliados[i]);
            vista.saltarLinea();
        }
    }
}



void Juego ::condicionEspecialPersonaje(Personaje *personajeTurno) {
    personajeTurno->modificarPorTurno();
}

void Juego :: menuJuegoAccion(Personaje** usuario, Personaje** contrario, Personaje* personajeTurno) {
    vista.segundoMenuTurno();
    int opcion = vista.comprobarOpcion(1, 3, JUGADOR);

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
    int opcion = vista.comprobarOpcion(1,3, JUGADOR);

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
    vista.saltarLinea();
    if(atacante -> energiaAtaque()){
        atacante->atacar(victima);
    }else{
        vista.imprimirLinea("El personaje no tiene suficiente energia para atacar.", __TEXT_YLW__);
    }

}


void Juego :: defenderse(Personaje* personajeTurno,Personaje** aliados) {
    vista.saltarLinea();
    if (personajeTurno->energiaDefensa())
        condicionDefensa(personajeTurno, aliados);
    else{
        vista.imprimirLinea("ERROR: el personaje no tiene energia para defenderse.", __TEXT_YLW__);
        vista.saltarLinea();
    }

}

void Juego ::condicionDefensa(Personaje *personajeTurno,Personaje** aliados) {

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
             vista.imprimirLinea("ERROR: ese casillero ya esta ocupado", __TEXT_YLW__);
    }while(!cambioUbicacion);

}

void Juego ::defensaAgua(Personaje *personajeTurno, Personaje** aliados) {

    personajeTurno->sumarVida(40);
    for(int i = 0; i < MAXPERSONAJES ; i++){
        if(personajeTurno->tieneVida())
            aliados[i]->sumarVida(10);
    }
}

void Juego ::moverse(Personaje *personajeTurno) {

    int desicionUsuario;
    do{
        int fila = vista.leerFilaOColumna("fila");
        int columna = vista.leerFilaOColumna("columna");
        int caminoMinimo = graf->caminoMinimo(personajeTurno->getFila(), personajeTurno->getColumna(), fila,
                                               columna, personajeTurno);
        desicionUsuario = condicionMoverse(personajeTurno,caminoMinimo,fila,columna);

    }while(desicionUsuario != SALIR);
}

bool Juego::casillaVacia( int fila, int columna) {
    bool estaVacia = true;
    int pos = 0;
    while(pos < MAXPERSONAJES && estaVacia){
        if(jugadorUno[pos]->getFila() == fila && jugadorUno[pos]->getColumna() == columna)
            estaVacia = false;
        if(jugadorDos[pos]->getFila() == fila && jugadorDos[pos]->getColumna() == columna)
            estaVacia = false;
        pos++;
    }
    return estaVacia;
}

int  Juego ::condicionMoverse(Personaje *personajeTurno, int caminoMinimo, int fila , int col) {

    int opcionUsuario = SALIR;

     if (personajeTurno->tieneEnergia(caminoMinimo) && casillaVacia(fila,col))
         moverPersonaje(personajeTurno,fila,col,caminoMinimo);
     else if(personajeTurno->tieneEnergia(caminoMinimo) && !casillaVacia(fila,col)){
         vista.imprimirLinea("Error: la casilla donde se quiere mover al personaje esta ocupada", __TEXT_YLW__);
         opcionUsuario = errorMoverse();
     }
     else{
         vista.imprimirLinea("Error: el personaje no tiene energia para moverse", __TEXT_YLW__);
         opcionUsuario = errorMoverse();
     }
     return opcionUsuario;
}

void Juego ::moverPersonaje(Personaje *personajeTurno, int fila, int columna, int caminoMinimo) {
    int posicionFinal = graf->buscarPosicion(fila,columna);
    vista.caminoInicialFinal(personajeTurno->getFila(),personajeTurno->getColumna(),fila,columna);
    vista.imprimirLinea("El personaje paso por las siguientes casillas intermedias : ");
    graf->recorridoMinimo(posicionFinal);
    matriz->setHayPersonaje(personajeTurno->getFila(),personajeTurno->getColumna(),false);
    personajeTurno->cambiarFYC(fila, columna);
    matriz->setHayPersonaje(fila,columna,true);
    personajeTurno->restarEnergia(caminoMinimo);
}

int Juego::errorMoverse() {
    int opcionUsuario;
    vista.imprimirLinea("¿Desea intentar mover el personaje nuevamente?\n1) sí \n2) no");
    vista.saltarLinea();
    opcionUsuario = vista.comprobarOpcion(1, 2, SI_NO);
    return opcionUsuario;
}

Juego ::~Juego() {
    for(int i = 0; i < MAXPERSONAJES ; i++){
    	cout << "jugador 1: ";
        if (jugadorUno[i] != NULL) delete jugadorUno[i];
	    cout << "jugador 2: ";
	    if (jugadorDos[i] != NULL) delete jugadorDos[i];
    }
}
