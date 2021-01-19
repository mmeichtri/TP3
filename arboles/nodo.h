

#ifndef ARBOLES_NODO_H
#define ARBOLES_NODO_H
#include <iostream>

#include "string.h"
using namespace std;

typedef int DATO;

class nodo {
private:
   DATO clave;
   nodo* derecho;
   nodo* izq;
   nodo* papa;
public:
    /*PRE : VALORES DE TIPO DATO Y PUNTERO A NODO VALIDO.
      POST: CREA UN NODO VALIDO. */
    nodo(DATO clave,nodo* papa);

    /*PRE: VARIABLE DE TIPO DATO VALIDA.
     POST: LE ASIGNA UN VALOR AL ATRIBUTO CLAVE DEL NODO.
     */
    void setClave(DATO clave);

    /*PRE : PUNTERO A NODO VALIDO
     POST: LE ASIGNA UN VALOR AL ATRIBUTO PADRE DEL NODO.
     */
    void setPadre(nodo* papa);

    /* PRE: PUNTERO A NODO VALIDO.
       POST: LE ASIGNA UN VALOR AL HIJO DERECHO DEL NODO.
     */
    void setDerecho(nodo* derecho);

    /* PRE : PUNTERO A NODO VALIDO.
       POST: LE ASIGNA UN VALOR AL HIJO IZQUIERDO DEL NODO.
     */
    void setIzq(nodo* izq);

    /*  PRE :
        POST : DEVUELVE AL PADRE DEL NODO.
     */
    nodo* getPadre();

    /*  PRE :
        POST : DEVUELVE AL HIJO DERECHO DEL NODO.
     */
    nodo* getDerecho();

    /*  PRE :
       POST : DEVUELVE AL HIJO IZQUIERDO DEL NODO.
     */
    nodo* getIzq();

    /* PRE :
      POST : DEVUELVE LA CLAVE DEL NODO.
     */
   DATO getClave();

};


#endif //ARBOLES_NODO_H
