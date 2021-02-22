//
// Created by jose on 22/2/21.
//

#ifndef TP3_PERSONAJE_H
#define TP3_PERSONAJE_H

#include <string>
#include <iostream>
#include "random"
#include "interfazUsuario.h"
using namespace std;
const int MAXRIVALES = 1;
const int EMAX = 20;
const int VMAX = 100;


class Personaje {
protected:
    VInterfazUsuario vista;
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


    // PRE :valorDano valido
    // POST:  retorna el valorDano dependiendo el valor del escudo que tenga el personaje.

    int defensaEscudo(int valorDano);

    // PRE:
    // POST:
    virtual bool energiaAtaque()= 0;

    //PRE :
    //POST:
    virtual bool energiaDefensa() = 0;
    //PRE :
    //POST:

    virtual void atacar(Personaje** personajeAtacado) = 0;

    // PRE: valor int fila y columna validas
    // POST: le asigna el valor fila y columna validas al personaje
    void cambiarFYC(int fila , int columna);

    //PRE:
    //POST: devuelve el atributo fila
    int obtenerFila();

    //PRE:
    //POST: devuelve el atributo columna
    int obtenerColumna();

    //PRE: valor int restar valido
    //POST: le resta al atributo vida el valor restar pasado por parametro

    void restarVida(int restar);


    //PRE:
    //POST:
    virtual string getElemento() = 0;

    //PRE:
    //POST: devuelve true si la vida > 0 , false en caso contrario
    bool  comprobarVida();

    //PRE: variable int eRestar valido
    //POST: le resta lo pasado en parametro a la energia
    void  restarEnergia(int eRestar);

    //PRE: variable energiaR valida
    //POST: devuelve true si la energia- energiaR >= 0, false en caso contrario
    bool tieneEnergia(int energiaR);

    //PRE: variable int sumar valida
    //POST:SI energia+sumar < 20, entonces se le sumara a energia sumar, sino energia = 20.
    void sumarEnergia(int sumar);

    //PRE: variable int sumar valida.
    //POST: SI vida+sumar < 100 , entonces se le sumara a vida sumar , sino vida = 100.
    void sumarVida(int sumar);

    //PRE: variable int escudo valido
    //POST: cambia el valor atributo escudo por el pasado por parametro.
    void modificarEscudo(int escudo);

    virtual void modificarPorTurno() = 0;

    //PRE:
    //POST: devuelve el valor del escudo.
    int getEscudo();

    //pre:
    //post: retorna true si vida >0 , false en caso contrario
    bool tieneVida();

    //pre: puntero a personaje personajeAtacado y variable ataque validas
    //post: a personajeAtacado se le resta la vida , del valor del ataque menos lo defendido por su escudo.
    void quitarVidaPersonaje(Personaje* personaAtacado , int ataque);

    string getNombre();

    //PRE:
    //POST:
    virtual ~Personaje() {;}

};

#endif //TP3_PERSONAJE_H
