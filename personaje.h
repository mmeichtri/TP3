//
// Created by jose on 2/2/21.
//

#ifndef ATAQUE_PERSONAJE_H
#define ATAQUE_PERSONAJE_H


#include <string>
#include <iostream>
#include "random"

using namespace std;

const int EMAX = 20;
const int VMAX = 100;


class Personaje {
protected:
    string nombre;
    int escudo;
    int vida;
    int energia;
    int fila = -1;
    int columna = -1;

public:
    /* PRE : NOMBRE VALIDO DE TIPO ALFANUMERICO, ESCUDO CON VALOR DE TIPO ENTERO ENTRE 0 A 2
     * Y VIDA CON VALOR TIPO ENTERO ENTRE 10 A 100.*/
    /* POST: CONSTRUYE UN OBJETO DE CLASE Personaje, ASIGNANDOLE UN VALOR DE ENERGIA ALEATORIO
     * DENTRO DEL RANGO ESTABLECIDO.*/
    Personaje(string nombre,int escudo,int vida);

    // PRE:
    // POST: METODO VIRTUAL DE LA CLASE PERSONAJE
    virtual void alimentarse() = 0;


    //PRE:
    //POST: IMPRIME EL NOMBRE,ESCUDO,VIDA Y ENERGIA DE UN PERSONAJE.

    void mostrarPersonaje();


    // PRE:
    // POST: DEVUELVE EL VALOR STRING NOMBRE DE UN PERSONAJE.
    string obtenerNombre();

    // PRE :VALOR DE DANO VALIDO.
    // POST:  RETORNA A valorDano CON UN VALOR ESPECIFICO DEPENDIENDO DEL VALOR DEL ESCUDO.

    int defensaEscudo(int valorDano);

    // PRE:
    // POST: DEVUELVE TRUE SI
    virtual bool energiaAtaque()= 0;

    //PRE :
    //POST:
    virtual bool energiaDefensa() = 0;
    //PRE :
    //POST:

    virtual int atacar(Personaje * personajeAtacado) = 0;

    // PRE: VALOR INT FILA Y COLUMNA VALIDOS.
    // POST: LE ASIGNA VALORES A LAS VARIABLES FILA Y COLUMNA
    void cambiarFYC(int fila , int columna);

    //PRE:
    //POST: DEVUELVE LA VARIABLE FILA
    int obtenerFila();

    //PRE:
    //POST:DEVUELVE LA VARIABLE COLUMNA
    int obtenerColumna();

    //PRE: VALOR INT VIDA VALIDO
    //POST: MODIFICA EL ATRIBUTO VIDA
    void modificarVida(int vida);

   //PRE:
   //POST:DEVUELVE EL VALOR DEL ATRIBUTO VIDA
    int obtenerVida();

    //PRE:
    //POST:
    virtual string elemento() = 0;

    //PRE:
    //POST:DEVUELVE TRUE SI VIDA > 0 , FALSE SINO
    bool  comprobarVida();

   //PRE:
   //POST:
    virtual ~Personaje() {;}





};


#endif //ATAQUE_PERSONAJE_H
