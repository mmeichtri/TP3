//
// Created by jose on 8/2/21.
//

#include "interfazUsuario.h"
#include <vector>


static int pedirOpcion(instancias_t instancia){
    string entrada;
    cout << "Ingrese una opción: ";
    cin >> entrada;
    cout << endl;
    const size_t cantidadOpciones = opcionesValidas[instancia].size();
    for (size_t i = 0; i < cantidadOpciones; i++){
        if (entrada == opcionesValidas[instancia][i]){
            int opcion = stoi(entrada);
            return opcion;
        }
    }
    cout << __TEXT_RED__ << "Ingrese una opción válida." << __TEXT_NC__ << endl;
    return -1;     
}



int VInterfazUsuario::leerFilaOColumna(string dato) {

    int  filaColumna;
    do{
        cout << "Debe seleccionar una "<< dato << " (entre 0-7). ";
        filaColumna = pedirOpcion(MATRIZ);
    }while(filaColumna < 0  || filaColumna > 7);

    return filaColumna;
}

void VInterfazUsuario::menuPrincipal(){

    cout << endl << __TEXT_YLW__ <<  "     Batalla de los elementos        " << __TEXT_NC__ << endl << endl;
    cout << "1) Agregar nuevo personaje   " << endl;
    cout << "2) Eliminar un personaje  "<< endl;
    cout << "3) Mostrar todos los nombres de los personajes " << endl;
    cout << "4) Mostrar detalles de un personaje " << endl;
    cout << "5) Comenzar juego " << endl;
    cout << "6) Salir  " << endl;
}

void VInterfazUsuario::menuJugadores() {

    cout << endl\
    << "1) Buscar por nombre los detalles de un personaje en particular "<< endl\
    << "2) Mostrar los nombres de todos los personajes " << endl\
    << "3) Seleccionar personaje " << endl;

}

void VInterfazUsuario::primerMenuTurno() {
    cout\
    << "1) Alimentarse" << endl\
    << "2) Moverse" << endl\
    << "3) Pasar Opcion" << endl << endl;
}

void VInterfazUsuario::segundoMenuTurno() {

    cout\
    << "1) Defenderse" << endl\
    << "2) Atacar"<< endl\
    << "3) Pasar Opcion " << endl << endl;
}


string VInterfazUsuario::ingresarString(string str) {

    string aux;
    cout << "Ingrese un " << str << ": ";
    cin >> aux;
    cout << endl;
    return aux;
}

int VInterfazUsuario::comprobarOpcion(int rangMinimo , int rangMaximo, instancias_t instancia){
    int opcion;

    do
        opcion = pedirOpcion(instancia);
    while( opcion < rangMinimo || opcion > rangMaximo );

    return opcion;
}

void VInterfazUsuario::noEncontro(string str ) {

    cout << __TEXT_RED__ << "ERROR: ese " << str << " no existe..." << __TEXT_NC__ << endl << endl;
}


void VInterfazUsuario::limpiarPantalla() {

#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}

void VInterfazUsuario::imprimirLinea(string linea, string formato) {
    cout << formato << linea << __TEXT_NC__ << endl;
}

void VInterfazUsuario ::saltarLinea() {
    cout << endl;
}

void VInterfazUsuario::mostrarPersonaje(
    string nombre, 
    string elemento,
    int escudo,
    int energia,
    int vida,
    int fila,
    int col,
    int jugador) 
{
    string colorNom;
    switch(jugador){
        case 0: colorNom = __TEXT_NC__; break;
        case 1: colorNom = __TEXT_BLU_TWINK__; break;
        case 2: colorNom = __TEXT_GRN_TWINK__; break;
        default: colorNom = __TEXT_NC__; break;
    }
	cout << "Nombre: " << colorNom << nombre << __TEXT_NC__ << endl;
	cout << "Elemento: " << elemento << endl;
	cout << "Escudo : " << escudo << endl;
	cout << "Vida : " << vida << endl;
	cout << "Energia: " << energia << endl;
	cout << "Posición: [" << fila << " , " << col  << ']'<< endl;
}

void VInterfazUsuario ::noSeAlimento() {
    cout << __TEXT_YLW__ << "ERROR: " << "el personaje ya tiene energia suficiente."\
    << __TEXT_NC__ << endl << endl << endl;
}

void VInterfazUsuario ::alimentado(string elemento, string comida, int energiaRecuperada) {
    cout << " Se alimentó al personaje de " << elemento << " con "<< comida <<\
    " y recupero " << energiaRecuperada << " de energia " << endl << endl;
}

void VInterfazUsuario ::caminoInicialFinal(int filaI, int colI, int filaF, int colF) {
    cout << " Desde ("<<filaI << " , "<<colI<<") hasta ("<<filaF<<" , "<<colF<<") " << endl << endl;
}