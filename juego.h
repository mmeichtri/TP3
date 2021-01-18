#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "lista.h"
#include "interfazUsuario.h"
#include "listaJugador.h"
class Juego{
private:
    ListaJugador* listaJugadores;
    Lista* listaPersonajes;
public:
    //constructor de Juego
    Juego();

    /*
    pre:
    post: instancia los objetos iniciales de las clases, e inicia el juego
    */
    void inicioJuego();

    /*
    pre:
    post: se ingresan los usuarios a this->listaJugadores
    */
    void indiqueJugadores();

    /*
    pre:
    post: muestra las opciones del menu, una vez iniciado el juego
    */
    void mostrarOpcionesJuego(InterfazUsuario );

    ~Juego();
};

#endif // JUEGO_H_INCLUDED
