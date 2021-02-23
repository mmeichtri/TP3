
#ifndef TP3_MENUPRINCIPAL_H
#define TP3_MENUPRINCIPAL_H
#include "juego.h"
#include "grafo.h"
#include"matriz.h"
#include "interfazUsuario.h"
#include "diccionario.h"

class MenuPrincipal {
private:
    VInterfazUsuario vistaUsuario;
    Diccionario diccionario;

    //pre:
    //post:
    void comenzarJuego();

    //pre:
    //post:
    void agregarPersonaje();

    //pre:
    //post:
    void eliminarPersonaje();

    //pre:
    //post:
    void mostrarNombrePersonajes();

    //pre:
    //post:
    void mostrarPersonajeEspecifico();
public:
    MenuPrincipal();
    //pre:
    //post:
    void menu();
};


#endif //TP3_MENUPRINCIPAL_H
