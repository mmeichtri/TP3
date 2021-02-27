
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

    //pre: puntero a grafo y matriz valido
    //post: crea los turnos rand y empieza el juego.
    void comenzarJuego(Grafo* grafo , Matriz* matriz);

    //pre:
    //post:
    void agregarPersonaje();

    //pre:
    //post: pide un nombre al usuario, si el nombre que ingreso esta en el diccionario, elimina al personaje
    void eliminarPersonaje();

    //pre:
    //post: muestra los personajes que estan en el diccionario
    void mostrarNombrePersonajes();

    //pre:
    //post:pide al usuario el nombre de un personaje especifico y si esta en el diccionario lo muestra
    void mostrarPersonajeEspecifico();

    //pre:variables string e int validas
    //post: crea un personaje dependiendo del elemento y lo retorna
    Personaje* crearPersonajeUsuario(string elemento , string nombre,int escudo,int vida);

    //pre:
    //post: llama a crearPersonajeUsuario
    Personaje* crearPersonaje();

    //pre:
    //post: pide al usuario un nombre, hasta que ingrese uno que no este en el diccionaario
    string validarNombre();

    //pre:
    //post: pide un usuario un elemento hasta que ingrese uno que sea valido
    string validarElemento();

    //pre:
    //post:lee los datos del archivo y los coloca en el diccionario
    void cargarDiccionario(const char* path);
public:
    //pre: puntero a diccionario valido
    //post: crea un objeto de menuPrincial
    MenuPrincipal(Diccionario* diccionario);

    //pre: puntero a grafo, puntero a matriz validos
    //post: segun lo ue ingrese el usuario hara una llamada
    void menu(Grafo* grafo , Matriz* matriz, const char *argv);




};


#endif //TP3_MENUPRINCIPAL_H