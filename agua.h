//
// Created by jose on 22/2/21.
//

#ifndef TP3_AGUA_H
#define TP3_AGUA_H


#include"personaje.h"

class Agua : public Personaje {
private:
    int contarComida;
public:
    /*PRE :VARIABLES NOMBRE,ESCUDO CON VALOR ENTRE 0 Y 2,VIDA CON VALOR ENTRE 10 Y 100 TIENEN
     * QUE SER VALIDOS.*/
    /*POST : CONSTRUYE UN OBJETO Agua QUE HEREDA DE LA CLASE PERSONAJE, INICIALIZANDO EL
     * ATRIBUTO contarComida EN CERO*/
    Agua(string nombre,int escudo,int vida);

    Agua(string nombre,int escudo,int vida,int energia,int fila,int columna);

    //PRE :
    /*POST: SI verificarEnergia() && contarComida < 3 DEVUELVE TRUE, INCREMENTA EN UNO contarComida Y EN DIEZ
     * LA energia DEL PERSONAJE. EN FALSEDAD, SI CONTAR COMIDA < 3 INDICA AL USUARIO QUE NO HAY ENERGIA
     Y SINO INDICA AL USUARIO QUE YA SE ALIMENTO 3 VECES*/
    void alimentarse();

    //PRE: vector a puntero de personajes  victim valido
    /*POST: pide una fila y columna y si hay un personaje en esa casilla, llama a atacarPersonaje,
     sino sigue hasta que ingrese una fila valida.
    */void atacar(Personaje** victima);

    //PRE:
    //POST: retorna el nombre del elemto del personje
    string getElemento();

    //PRE:
    //POST: retorna true si energia >= 5, false en caso contrario
    bool energiaAtaque();

    //PRE:
    //POST: retorna true si energia >= 12 , false en caso contrario
    bool energiaDefensa();

    //pre: puntero a personaje valido
    //post: llama a la funcion dano ataque y quitarVida.
    void atacarPersonaje(Personaje* personajeAtacar);

    //PRE :
    //POST : DESTRUYE UN PERSONAJE DE TIPO AGUA.
    ~Agua();

private:
    //PRE :
    /*POST :DEVUELVE VERDADERO SI LA energia+10 ES MENOR O IGUAL QUE emax Y
     * FALSO AL NO CUMPLIRSE LA CONDICION*/
    bool verificarEnergia();

    // PRE :
    /* POST:SI CANTIDAD ES MENOR A 3 ,IMPRIME EL NOMBRE DEL PERSONAJE, DE QUE SE ALIMENTO Y CUANTO SUBIO SU ENERGIA.*/
    void imprimirAlimentos();

    //PRE: puntero a personaje personajeAtacar valido.
    //POST:dependiendo del getElemento() , retorna el dano que le hace a personajeAtacar.
    int danoAtaque(Personaje* personajeAtacar);

    //pre:
    //post:
    void modificarPorTurno();

    //pre: variable bool personaje valida,
    //post: si personaje bool es false , lo indica por pantalla
    void noEncontroPersonaje(bool personaje);


};


#endif //TP3_AGUA_H
