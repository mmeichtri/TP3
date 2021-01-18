#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "personajes.h"

using namespace std;

class Menu
{
    //atributos
private:
        int opcion;

    //metodos
public:

        //pre:-
        //pos:muestra un menu con las opciones a seleccionar.
        void mostrarMenu();

        //pre:-
        //post:le pide al usuario ingresar un numero entero y lo devuelve.
        void elegirOpcion();


        //pre:-
        //post:una funcion con un switch el cual realiza diferentes acciones al seleccionar diferentes opciones.

        void eleccion();

        //pre:-
        //post: muestra por pantalla los nombres de todos los personajes que se crearon.
        void mostrarNombres();

        //pre:-
        //post:muestra los datos de un personaje que se desee.
        void mostrarDatos();

        //pre:-
        //post: alimenta a un personaje
        void alimentar();

        //pre:-
        //pos:sale del menu.
        void salir();

        //pre: que el archio del cual se tomen los valores no este vacia.
        //pos: carga la lista con los valores que ofrece el archivo csv.
        void cargar();

        //pre:-
        //post:devuelve un entero entre 0 y 2 incluidos usando una funcion random.
        int cargarEscudo();

        //pre:-
        //post:devuelve un entero entre 10 y 100 incluidos usando una funcion random.
        int cargarVida();

        //pre:-
        //post:devuelve un entero entre 0 y 20 incluidos usando una funcion random.
        int cargarEnergia();

        //pre: no repetir nombres anteriormente cargados y escribir el nombre entero en mayusculas o minusculas.
        //post: devuelve una string que representa el nombre del personaje el cual es ingresado por el usuario.
        string cargarNombre();

        //pre:-
        //post: agrega un personaje a la lista dandole un nombre ingresado por el usuario y el resto de los valores aleatoriamente.

        void agregarPersonaje();

        //pre:-
        //post:crea un objeto de una clase derivada.

        void crearElemento(char);

        //pre:-
        //post: devuelve un caracter que representa el elemetento del cual va a ser el personaje que va a ser creado, 'a'(agua),'v'(aireo o viento),'f'(fuego),'t'(tierra).

        char eleguirElemento();

        //pre:-
        //post: elimina un personaje de la lista segun el nombre que se busque.

        void eliminarPersonaje();

        //pre:-
        //post: recibe como parametro un nombre ingresado por el usuario y devuelve la posicion en la que se encuentra el nombre, si el nombre no se encuentra devuelve -1.
        int encontrarNombre(string);

        //pre:-
        //post: recibe como parametro una posicion de la lista y da de baja al personaje en esa posicion.
        void bajaPersonaje(int);

        //pre:-
        //post: recibe como parametro una posicion de la lista e imprime el nombre, elemento, vida,escudo y energia del personaje.
        void imprimir(int);


};

#endif // MENU_H_INCLUDED
