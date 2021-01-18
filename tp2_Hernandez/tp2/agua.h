#ifndef AGUA_H
#define AGUA_H
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

    //PRE :
    /*POST: SI verificarEnergia() DEVUELVE TRUE, INCREMENTA EN UNO contarComida Y EN DIEZ
     * LA energia DEL PERSONAJE. EN FALSEDAD, LLAMA imprimirAlimentos(),INDICANDO
     * AL USUARIO QUE NO PUEDE ALIMENTARSE */
    void alimentarse();

    //PRE :
    //POST : IMPRIME LOS ATRIBUTOS DE AGUA Y EL ELEMENTO AGUA.
    void mostrarPersonajeEspecifico();
    //PRE :
    //POST : DESTRUYE UN PERSONAJE DE TIPO AGUA.
    ~Agua();

private:

    //PRE :
    /*POST :DEVUELVE VERDADERO SI LA energia+10 ES MENOR O IGUAL QUE emax Y EL PERSONAJE SE HA
     * ALIMENTADO MENOS DE 3 VECES, FALSO AL NO CUMPLIRSE POR LO MENOS UNA DE LAS CONDICIONES*/
    bool verificarEnergia();

    // PRE :
    /* POST:IMPRIME EL NOMBRE DEL PERSONAJE, DE QUE SE ALIMENTO Y CUANTO SUBIO SU ENERGIA.*/
    void imprimirAlimentos();

};

#endif // AGUA_H
