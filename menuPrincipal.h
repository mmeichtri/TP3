
#ifndef TP3_MENUPRINCIPAL_H
#define TP3_MENUPRINCIPAL_H
#include "juego.h"
#include "grafo.h"
#include "matriz.h"
#include "interfazUsuario.h"
#include "diccionario.h"
#include "archivoPersonaje.h"
#include "personaje.h"

class MenuPrincipal {
private:
    VInterfazUsuario vistaUsuario;
    Diccionario* _diccionario;

    //pre:
    //post:
    void comenzarJuego(Grafo* grafo , Matriz* matriz);

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

    //pre:
    //post:
    Personaje* crearPersonajeUsuario(string elemento , string nombre,int escudo,int vida);

    //pre:
    //post:
    Personaje* crearPersonaje();

    //pre:
    //post:
    string validarNombre();

    //pre:
    //post:
    string validarElemento();

    //pre:
    //post:
    void cargarDiccionario();
public:
    //pre:
    //post:
    MenuPrincipal(Diccionario* diccionario);
    //pre:
    //post:
    void menu(Grafo* grafo , Matriz* matriz);

    //pre:
    //post:
    void empezarPrograma();


};


#endif //TP3_MENUPRINCIPAL_H
