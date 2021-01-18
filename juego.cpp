#include <iostream>
#include "juego.h"
#include "interfazUsuario.h"
#include "lectorCsv.h"
#include "lista.h"
#include "listaJugador.h"
using namespace std;

Juego::Juego(){
    this->listaJugadores = new ListaJugador();
    this->listaPersonajes = new Lista();
    cout << "***La batalla de los elementos***" << endl;
}

void Juego::inicioJuego(){
    LectorCsv cargaListaCsv;
    string csv = "./personajes.csv";
    cargaListaCsv.lecturaCsv(this->listaPersonajes, csv);
    InterfazUsuario interfaz;
    mostrarOpcionesJuego(interfaz);
}

void Juego::indiqueJugadores(){
    string nombreJugador;
    cout << "Indique el nombre del primer jugador: " << endl; cin >> nombreJugador;
    Jugador* jugador1 = new Jugador(nombreJugador);
    listaJugadores->alta(jugador1, listaJugadores->obtener_cantidad()+1);
    cout << "Indique el nombre del primer jugador: " << endl; cin >> nombreJugador;
    Jugador* jugador2 = new Jugador(nombreJugador);
    listaJugadores->alta(jugador2, listaJugadores->obtener_cantidad()+1);
}

void Juego::mostrarOpcionesJuego(InterfazUsuario interfaz){
    interfaz.menu();
    int eleccion = interfaz.eleccionUsuario();
    try{
        while(eleccion >= 1 && eleccion < 6){
            switch(eleccion){
                case 1:
                    interfaz.nuevoPersonaje(this->listaPersonajes);
                    break;
                case 2:
                    interfaz.eliminarPersonaje(this->listaPersonajes);
                    break;
                case 3:
                    interfaz.mostrarNombrePersonajes(this->listaPersonajes);
                    break;
                case 4:
                    interfaz.solicitarPersonajeYmostrarDatos(this->listaPersonajes);
                    break;
                case 5:
                    interfaz.alimentarPersonaje(this->listaPersonajes);
                    break;
                case 6:
                    break;
                }
                cout << endl; interfaz.menu();
                eleccion = interfaz.eleccionUsuario();
            }
            if(eleccion != 6){
                throw string("La opcion ingresada es invalida");
            }
            interfaz.mostrarEstadoFinalPersonajes(this->listaPersonajes);
            cout << "Gracias por jugar" << endl;
    }
    catch(string &error){
        cout << error << endl;
    }
}

Juego::~Juego(){
    while(this->listaJugadores->hay_siguiente()){
        delete this->listaJugadores->siguiente();
    }
    while(this->listaPersonajes->hay_siguiente()){
        delete this->listaPersonajes->siguiente();
    }

}
