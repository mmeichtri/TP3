//
// Created by jose on 2/2/21.
//

#ifndef GRAFO_ARCHIVO_H
#define GRAFO_ARCHIVO_H


#include "matriz.h"
#include "sstream"
#include <fstream>
#include <string>
using namespace std;


class Archivo {

private:
    //PRE: STRING TIPO Y VARIABLES INT FILA Y COLUMNA VALIDAS
    //POST: CREA UN PUNTERO A UN CASILLERO DEL TIPO PASADO POR PARAMETRO STRING Y LO DEVUELVE.
    Casillero* tipoCasillero(string tipo , int fila , int columna);
public:
    //PRE: PUNTERO A MATRIZ Y PUNTERO A GRAFO VALIDOS.
    //POST: LEE LAS LINEAS DEL ARCHIVO, LE PASA LOS DATOS A LA CLASE MATRIZ , Y LE PASA LOS DATOS A LA FUNCION VERTICE DEL  GRAFO
void leerArchivo(Matriz* matriz,grafo* graf);

};


#endif //GRAFO_ARCHIVO_H
