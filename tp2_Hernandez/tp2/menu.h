#ifndef MENU_H
#define MENU_H

#include "lista.h"
#include "personaje.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"
#include "vistaMenu.h"
#include <fstream>
#include "sstream"

class Menu{
private:
    VistaMenu vm;
    Lista* list;
public:
     //PRE : RECIBE POR REFERENCIA UNA LISTA VALIDA.
    //POST : CONSTRUYE UN OBJETO CONTROLADOR CON DATOS VALIDOS.
  Menu(Lista* list);


    // PRE:
    // POST:ASIGNA LOS DATOS NOMBRE,ELEMENTO, VIDA, ESCUDO Y LLAMA A crearPersonaje

    void cargarNuevoPersonaje();

    //PRE: ELEMENTO , NOMBRE , ESCUDO ENTRE 0 Y 2 , VIDA ENTRE 10 Y 100 PERFECTAMENTE CREADOS.
    /*POST : SI EL ELEMENTO ES AGUA , TIERRA , FUEGO O AIRE CREA UN OBJETO DINAMICO DEL TIPO QUE SEA ELEMENTO
      Y LO CARGA EN LA LISTA SI ELEMENTO NO ES IGUAL A LOS ANTES MENCIONADOS LLAMA A UNA FUNCION DE VControlador*/
    void crearPersonaje( string elemento , string nombre , int escudo , int vida );


   //PRE: LISTA Y OPCION VALIDAS
   //POST: SWITCH QUE LLAMA A LA FUNCION DEPENDIENDO DE LO QUE EL USUARIO INGRESE.
   void funcionCasos( int opcion);

   //PRE :
   //POST: CICLO DO WHILE QUE LLAMA A LA funcionCasos , vp.menu y comprobarOpcion MIENTRAS LA OPCION SEA ENTRE 1 Y 5.
   void opciones();

   //PRE : EXISTE UN ARCHIVO CREADO PREVIAMENTE.
   /* POST : RECIBE LOS DATOS PROVENIENTES DEL ARCHIVO(LOS ATRIBUTOS VIDA Y ESCUDO LOS
    * TRANSFORMA A ENTEROS), Y LLAMA A LA FUNCION crearPersonaje*/
    void cargarArchivo();

    /*PRE: */
    /*POST: VALIDA EL NOMBRE DEL NUEVO PERSONAJE, SI NO EXISTE RETORNA EL NOMBRE DEL NUEVO PERSONAJE,
     * EN CASO DE EXISTIR EL NOMBRE INGRESADO, SE INVOCA EL METODO DE noEncontro*/
    string verificarNombre();

    //PRE
    /*POST: VALIDA QUE EL ELEMENTO INGRESADO ESTE ESCRITO CORRECTAMENTE, SI ES CORRECTO RETORNA
     * EL ELEMENTO, EN CASO CONTRARIO SE INVOCA EL METODO noEncontro*/
    string verificarElemento();

     //PRE: STRING VALIDO.
    /*POST: LLAMA A buscar, PARA OBTENER EL NODO anterior AL ACTUAL Y SE VALIDA QUE haySiguiente
     * SEA VERDADERO PARA QUE EL PERSONAJE QUE APUNTA actual INVOQUE SU METODO alimentarse.
     * EN CASO QUE haySiguiente SEA FALSO, SE INDICA UN MENSAJE A TRAVES DEL METODO noEncontro*/
    void alimentarPersonaje(string nombre);

    //PRE: DATO STRING VALIDO
    /*POST: LLAMA A buscar. SI ACTUAL ES DISTINTO DE NULL Y EL VALOR BUSCADO ESTA EN LA PRIMERA POSICION LLAMA A baja,
     * DE ESTAR EN LAS SIGUIENTES POSICIONES LLAMA AL METODO baja PASANDOLE POR PARAMETRO EL NODO
     * ANTERIOR. EN CASO DE actual ES NULL, INVOCA AL METODO noEncontro*/
    void bajaPersonaje(string nombre);

    //PRE: STRING VALIDO.
    /*POST: LLAMA A buscar ,SI actual ES DISTINTO DE NULL, A EL NODO QUE APUNTA actual LE LLAMA
     * A PERSONAJE ESPECIFICO, SI ES FALSO LLAMA A noencontro.*/
    void mostrarEspecifico(string nombre);
};


#endif // MENU_H
