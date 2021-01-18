#ifndef INTERFAZUSUARIO_H_INCLUDED
#define INTERFAZUSUARIO_H_INCLUDED
#include "nodo.h"

class InterfazUsuario{
public:
    //constructor
    InterfazUsuario();

    /*
    Pre:
    Post: muestra el menu de acciones en pantalla
    */
    void menu();

    /*
    pre:
    post: devuelve la eleccion elegida por el usuario del menu
    */
    int eleccionUsuario();

    /*
    pre:
    post:
    */
    int pedirElementoNuevoPersonaje();

    /*
    pre:
    post: agrega nuevo personaje, al final de la lista
    */
    void nuevoPersonaje(Lista* );

    /*
    pre:
    post: se le piden los datos del nuevo personaje de tipo Agua, y se agrega al final de la lista
    */
    void cargarNuevoElementoAgua(Lista* );

    /*
    pre:
    post: se le piden los datos del nuevo personaje de tipo Fuego, y se agrega al final de la lista
    */
    void cargarNuevoElementoFuego(Lista* );

    /*
    pre:
    post: se le piden los datos del nuevo personaje de tipo Aire, y se agrega al final de la lista
    */
    void cargarNuevoElementoAire(Lista* );

    /*
    pre:
    post: se le piden los datos del nuevo personaje de tipo Tierra, y se agrega al final de la lista
    */
    void cargarNuevoElementoTierra(Lista* );

    /*
    pre:
    post: elimina el personaje indicado
    */
    void eliminarPersonaje(Lista* );

    /*
    pre:
    post: muestra los datos de los personajes
    */
    void mostrarDatosPersonajes(Lista* );

    /*
    pre:
    post: devuelve el elemento que ingreso el usuario para el nuevo personaje
    */
    std::string solicitarElementoNuevoPersonaje();

    /*
    pre:
    post: devuelve el nombre ingresado por el usuario para el nuevo personaje
    */
    std::string pedirNombreNuevoPersonaje();

    /*
    pre: si el numero ingresado, se encuentra en el rango de [0, 2]
    post: devuelve el escudo ingresado por el usuario
    */
    int pedirEscudoNuevoPersonaje();

    /*
    pre: si la vida ingresada esta en el rango [10, 100]
    post: devuelve la cantidad de vidas ingresadas por el usuario
    */
    int pedirVidaNuevoPersonaje();

    /*
    pre:
    post: muestra los nombres de todos los personajes de la lista
    */
    void mostrarNombrePersonajes(Lista* );

    /*
    pre:
    post: muestra los datos del personaje indicado
    */
    void solicitarPersonajeYmostrarDatos(Lista* );

    /*
    pre: si el personaje se encuentra en la lista...
    post: devuelve la informacion asociada al nombre del personaje indicado
    */
    void mostrarDatosPersonajeBuscado(Lista* ,std::string );

    /*
    pre:
    post: muestra el estado actual del personaje
    */
    void mostrarEstadoActual(Personaje* );

    /*
    pre: recibe un string, el cual indica la fraese a utilizar, ya que reutilizo la funcion para distintos casos
    en que se solicita el nombre
    post: devuelve el nombre del personaje indicado por el usuario, para buscar en la lista
    */
    std::string solicitarNombrePersonajeABuscar(std::string );

    /*
    pre: si el personaje ingresado por el usuario, se encuentra en la lista
    post: alimenta el personaje, e incrementa la energia
    */
    void alimentarPersonaje(Lista* );

    /*
    pre:
    post: una vez finalizado el juego, muestra el estado final de todos los personajes
    */
    void mostrarEstadoFinalPersonajes(Lista* );
};

#endif // INTERFAZUSUARIO_H_INCLUDED

