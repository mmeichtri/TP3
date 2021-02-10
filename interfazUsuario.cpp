#include "interfazUsuario.h"
#include <iostream>

using namespace std;

interfazUsuario::interfazUsuario(){
}

void interfazUsuario::menuInicial(){
    cout << "Sus opciones son: " << endl;
    cout << "1- Agregar un nuevo personaje" << endl;
    cout << "2- Eliminar un personaje" << endl;
    cout << "3- Mostrar todos los nombres de los personajes" << endl;
    cout << "4- Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "5- Alimentar un personaje" << endl;
    cout << "6- Salir" << endl;
}

void interfazUsuario::menuComienzoDeJuego(){
    cout << "Es momento de elegir, o ver las caracteristicas de los personajes! Indique que desea realizar: " << endl;
    cout << "1- Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "2- Mostrar todos los nombres de los personajes" << endl;
    cout << "3- Seleccionar personaje" << endl;
    cout << "4- Salir" << endl;
}

 void interfazUsuario::opcionesPrimariasPersonaje(){
    cout << "Indique la accion que desea que realice su personaje: " << endl;
    cout << "1- Alimentarse" << endl;
    cout << "1- Moverse" << endl;
    cout << "1- Pasar opción" << endl;
}

void interfazUsuario::opcionesSecundariasPersonaje(){
    cout << "Ahora debe elegir una de las siguientes opciones: " << endl;
    cout << "Defenderse" << endl;
    cout << "Atacar" << endl;
    cout << "Pasar opción" << endl;
}
