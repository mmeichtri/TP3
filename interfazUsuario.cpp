//
// Created by jose on 8/2/21.
//

#include "vInterfazUsuario.h"

int VInterfazUsuario ::leerFilaOColumna(string dato) {

    int  filaColumna;
    do{
        cout << "Ingrese numero de "<< dato << " (entre 0-7)" <<  endl;
        cin >> filaColumna;
    }while(filaColumna < 0  || filaColumna > 7);

    return filaColumna;
}

void VInterfazUsuario :: menuPrincipal(){

    cout <<  "     Batalla de los elementos        " << endl;
    cout << "1) Agregar nuevo personaje   " << endl;
    cout << "2) Eliminar un personaje  "<< endl;
    cout << "3) Mostrar todos los nombres de los personajes " << endl;
    cout << "4) Mostrar detalles de un personaje " << endl;
    cout << "5) Comenzar juego " << endl;
    cout << "6) Salir  " << endl;
}

void VInterfazUsuario ::menuJugadores() {

    cout << "1) Buscar por nombre los detalles de un personaje en particular : "<< endl;
    cout << "2) Mostrar los nombres de todos los personajes : " << endl;
    cout << "3) Seleccionar personaje : " << endl;

}

void VInterfazUsuario ::primerMenuTurno() {

    cout << "1) Alimentarse : " << endl;
    cout << "2) Moverse : " << endl;
    cout << "3) Pasar Opcion : " << endl;
}

void VInterfazUsuario ::segundoMenuTurno() {

    cout << "1) Defenderse : " << endl;
    cout << "2) Atacar : "<< endl;
    cout << "3) Pasar Opcion : " << endl;
}


string VInterfazUsuario ::ingresarString(string str) {

    string aux;
    cout << "Ingrese un " << str << endl;
    cin >> aux;
    return aux;
}

int VInterfazUsuario :: comprobarOpcion(int rangMinimo , int rangMaximo){

    int opcion;
    do{
        cout << "Ingrese una opcion valida del menu : " << endl;
        cin >> opcion;
    }while( opcion < rangMinimo || opcion > rangMaximo );
   cout << opcion << endl;
    return opcion;

}

void VInterfazUsuario ::noEncontro(string str ) {

    cout << "Error ese " << str << " no existe  " << endl;
}


void VInterfazUsuario :: limpiarPantalla() {

#ifdef WINDOWS
    std :: system("cls");
#else
    std::system("clear");
#endif
}

void VInterfazUsuario ::imprimirLinea(string linea) {
    cout << linea << endl ;
}