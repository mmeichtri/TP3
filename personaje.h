#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include <string>
#include "lista.h"

class Lista;

class Personaje{
protected:
    std::string nombre;
    int escudo = 0;
    int vida = 0;
    int energia = 0;
<<<<<<< HEAD
    int fila = 0;
    int columna = 0;
=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
public:
    /*
    pre:
    post:
    */
    Personaje(std::string, int, int );

    /*
    pre:
    post: crea un nuevo personaje, agregandolo a la lista polimorfica
    */
    void agregarNuevoPersonaje();

    /*
    pre:
<<<<<<< HEAD
    post: devuelve la fila
    */
    int getFila();

    /*
    pre:
    post: devuelve la columna
    */
    int getColumna();

    /*
    pre:
=======
>>>>>>> 1caeb074f25c3c71d5b828b32943dc1b3e57fbf6
    post: devuelve el nombre del personaje
    */
    std::string getNombre();

    /*
    pre:
    post: devuelve el escudo del personaje
    */
    int getEscudo();

    /*
    pre:
    post: devuelve la cantidad de vidas del personaje
    */
    int getVida();

    /*
    pre: si nombre se encuentra en la lista
    post: devuelve los datos del personaje solicitado
    */
    Personaje* obtenerDatos(std::string );

    /*
    pre:
    post: devuelve si coincide el personaje con alguno de la lista
    */
    bool validarCoincidencia(std::string ,std::string);

    /*
    pre: si existePersonaje()
    post: ->alimenta el personaje indicado
    */
    virtual void alimentar(std::string ) = 0;

    /*
    Pre:
    Post: devuelve la energia actual del personaje
    */
    virtual int mostrarEnergiaActual() = 0;

    /*
    pre:
    post: devuelve el elemento del personaje
    */
    virtual std::string getElemento() = 0;

    /*
    pre:
    post: destruye el objeto Pesonaje, hasta que la lista este vacia, liberando memoria
    */
    virtual ~Personaje();

};

#endif // PERSONAJE_H_INCLUDED
