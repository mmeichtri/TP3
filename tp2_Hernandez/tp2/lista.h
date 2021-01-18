#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
class Lista {
private:
    Nodo* primero;
    Nodo* actual;

public:
    // PRE:
    // POST: CREA UNA LISTA CON PUNTEROS primero Y actual APUNTADO A NULL
    Lista();

    //PRE: PUNTERO PERSONAJE VALIDO.
    //POST: CREA UN NODO Y LO COLOCA EN LA PRIMERA POSICION.
    void cargarLista(Personaje* personaje);


    // PRE : LA LISTA NO PUEDE ESTAR VACIA
    // POST : ELIMINA EL PERSONAJE QUE ESTA EN LA PRIMERA POSICION
    void baja();

    //PRE : LA LISTA NO PUEDE ESTAR VACIA , RECIBE UNA DIRECCION DE UN NODO VALIDO.
    //POST : ELIMINA DE LA LISTA AL SIGUIENTE NODO DEL NODO PASADO POR PARAMETRO.
    static void baja(Nodo* nodo);

    // PRE:
    /* POST: MIENTRAS NO ESTE VACIA, RECORRE LA LISTA Y MUESTRA EL NOMBRE DE CADA PERSONAJE.
     * SI ESTA VACIA LO INDICA MEDIANTE UN MENSAJE*/
    void mostrarPersonaje();

    //PRE :
    //POST: DEVUELVE VERDADERO SI EL PUNTERO primero APUNTA A NULL, FALSO EN CASO CONTRARIO.
    bool listaVacia();

    //PRE: haySiguiente ES TRUE
    /*POST: HACE A actual APUNTAR AL SIGUIENTE NODO EN LA LISTA Y DEVUEVE EL NODO QUE
     * actual APUNTABA ANTERIORMENTE.*/
    Nodo* iterar();

    // PRE : STRING VALIDO.
    /* POST :RECORRE CADA UNO DE LOS NODOS DE LA LISTA HASTA QUE actual SEA IGUAL AL nombre
     * O HASTA QUE haySiguiente SEA FALSO. DEVUELVE LA DIRECCION DEL NODO anterior A ACTUAL */
   Nodo* buscar(string nombre);


   // PRE :
   //POST : DEVUELVE EL NODO AL QUE ACTUAL APUNTA.
   Nodo*  obtenerActual();

    // PRE:
    //POST: DEVUELVE VERDADERO SI actual NO APUNTA A NULL Y FALSO EN CASO CONTRARIO.
    bool haySiguiente();

    //PRE:
    //POST: DESTRUYE CADA UNO NODOS DE LA LISTA.
    ~Lista();

  private:


    // PRE:
    // POST: HACE APUNTAR LA VARIABLE actual A LA MISMA DIRECCION QUE APUNTA EL PUNTERO primero.
    void reiniciarActual();

};
#endif // LISTA_H
