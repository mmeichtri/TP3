//
// Created by jose on 22/12/20.
//

#ifndef ARBOLES_ARBOL_H
#define ARBOLES_ARBOL_H
#include "nodo.h"
#include <iostream>
using namespace std;

class arbol {
private:
    nodo* raiz = nullptr;
public:
    /*PRE:
     POST: CREA UN OBJETO ARBOL VALIDO.
     */
    arbol();

    /* PRE : VALOR DE DATO VALIDO , ARBOL PREVIAMENTE CREADO
       POST: REALIZA UN LLAMADO A LA FUNCION setArbol Y LE ASIGNA UN VALOR A RAIZ;
     */
    void cargarArbol(DATO clave);

    /* PRE : ARBOL NO VACIO
      POST : IMPRIME EL ARBOL EN ORDEN
    */
     void inOrden(nodo* Nodo);

     /* PRE : PUNTERO A NODO VALIDO Y DATO  CLAVE VALIDO.
        POST: RECORRE EL ARBOL RECURSIVAMENTE BUSCANDO EL VALOR DE LA CLAVE POR CADA UNO DE LOS NODOS DEL ARBOL,
        SI LO ENCUENTRA DEVUELVE EL NODO , SINO DEVUELVE PUNTERO NULO.
      */
     nodo* busqueda(nodo* Nodo, DATO clave);

     /* PRE :
        POST : DEVUELVE EL ATRIBUTO RAIZ DEL ARBOL.
      */
     nodo* getRaiz();

     /* PRE : DATO CLAVE VALIDO.
        POST : LLAMA A FUNCION BUSCAR, LA CUAL DEVUELVE EL NODO QUE TIENE LA CLAVE PASADA POR PARAMETRO , SI ESE
        NODO EXISTE LLAMA A LA FUNCION eliminarNodo()
      */
     void eliminarNodo(DATO clave);

     /* PRE :
        POST : LLAMA A LA FUNCION eliminarTodo Y DESTRUYE EL ARBOL.
      */
     ~arbol();

private:
    /* PRE : PUNTERO NODO VALIDO , PUNTERO A NODO PADRE VALIDO , CLAVE DE TIPO DATO VALIDA.
       POST : RECORRE RECURSIVAMENTE EL ARBOL HASTA QUE ENCUENTRA EL LUGAR CORRECTO , Y CREA UN NODO DEL ARBOL.
     */
    nodo* setArbol(nodo* Nodo,nodo* papa , DATO clave);

    /* PRE : PUNTERO A NODO VALIDO.
      POST : POST : SI EL NODO PASADO POR PARAMETRO TIENE SUS DOS HIJOS NULOS LLAMA A eliminarHoja , SI TIENE UN SOLO
      NODO NULO LLAMA A eliminarUnHijo Y SI TIENE DOS HIJOS LLAMA A eliminarDosHijos Y SE LLAMA A ELLA MISMA
      RECURSIVAMENTE.
    */
    void eliminarNodo(nodo* Nodo);

    /* PRE : PUNTERO A UN NODO VALIDO.
      POST : SI EL NODO PASADO POR PARAMETRO ES UN HIJO IZQUIERDO , LE CAMBIA AL PADRE EL HIJO IZQUIERDO A NULL,
      SI ES HIJO DERECHO LE CAMBIA AL PADRE HIJO DERECHO A NULL.
     */

     void eliminarHoja(nodo* Nodo);

     /* PRE : PUNTERO A PADRE VALIDO Y PUNTERO A HIJO VALIDO.
       POST : SI EL PADRE DEL NODO PASADO POR PARAMETRO TIENE HIJO DERECHO , ENTONCES SE LE ASIGNA COMO NUEVO HIJO
       DERECHO DEL PADRE AL HIJO DEL NODO PASADO POR PARAMETRO Y AL HIJO DEL NODO PASADO POR PARAMETRO SE LE ASIGNA
       COMO PADRE AL PADRE DEL NODO , SI EN VEZ DE TENER HIJO DERECHO , EL PADRE TIENE HIJO IZQUIERDO ES EL MISMO PROCEDIMIENTO.
      */
     void eliminarUnHijo(nodo* padre , nodo* hijo);

     /* PRE: PUNTERO A NODO VALIDO
        POST :POST : LLAMA A LA FUNCION nodoMasIzquierda PASANDOLE COMO PARAMETRO EL HIJO DERECHO DEL NODO
        PASADO POR PARAMENTO, CAMBIA LA CLAVE DEL NODO PASADO POR PARAMETRO POR LA CLAVE DEL NODO QUE
        DEVUELVE LA FUNCION nodoMasIzquierda Y DEVUELVE ESTE ULTIMO NODO.
      */
    nodo* eliminarDosHijos(nodo* Nodo);

     /* PRE : PUNTERO A NODO VALIDO
       POST : BUSCA RECURSIVAMENTE EL NODO MAS A LA IZQUIERDA Y DEVUELVE EL NODO ENCONTRADO.
      */
     nodo* nodoMasIzquierda(nodo* Nodo);

     /* PRE : PUNTERO A NODO VALIDO
        POST : NODO PASADO POR PARAMETRO CAMBIA EL VALOR DE SUS HIJOS A NULL Y ELIMINA ESE NODO.
      */
     void deleteNodo(nodo* Nodo);

     /* PRE : NODO VALIDO
        POST : SE LLAMA RECURSIVAMENTE LA FUNCION POR EL LADO IZQUIERDO, LUEGO POR EL LADO DERECHO Y LUEGO ELIMINA
        AL NODO.
      */
     void eliminarTodo(nodo *Nodo);

};


#endif //ARBOLES_ARBOL_H