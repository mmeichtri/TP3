#include "lecturaCsvCasilleros.h"
#include "grafo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "lago.h"
#include "montania.h"
#include "precipicio.h"
#include "vacio.h"
#include "camino.h"
#include "volcan.h"
#include "matriz.h"

using namespace std;

LecturaCsvCasilleros::LecturaCsvCasilleros(){

}

//archivo->mapa.csv
void LecturaCsvCasilleros::lecturaArchivo(Matriz* tablero, Grafo* grafo, string csv){
    int contador = 0;
    ifstream archivo;
    archivo.open(csv);
    if (archivo.fail()){
        cout<< "Error al abrir el archivo"<< endl;
        exit(1);
    }

    string linea, aux, tipoCasillero, elemento;
    int fila, columna;

    while(!archivo.eof()){
        if(getline(archivo, aux, ',')){
            fila = std::stoi(aux);
            getline(archivo, aux, ',');
            columna = std::stoi(aux);
            getline(archivo, aux, '\n');
            tipoCasillero = aux;
            Casillero* tipo = crearCasillero(tipoCasillero, fila, columna);
            grafo->ingresarVertice(tipo, contador);
            tablero->setTablero(tipo, fila, columna);
            contador++;
        }
    }
    archivo.close();
}

Casillero* LecturaCsvCasilleros::crearCasillero(string tipoCasillero, int fila, int columna){
    if(tipoCasillero == "Lago"){
        Casillero* casillero = new Lago(fila, columna);
        return casillero;
    }
    else if(tipoCasillero == "Precipicio"){
        Casillero* casillero = new Precipicio(fila, columna);
        return casillero;
    }
    else if(tipoCasillero == "Montania"){
        Casillero* casillero = new Montania(fila, columna);
        return casillero;
    }
    else if(tipoCasillero == "Volcan"){
        Casillero* casillero = new Volcan(fila, columna);
        return casillero;
    }
    else if(tipoCasillero == "Camino"){
        Casillero* casillero = new Camino(fila, columna);
        return casillero;
    }
    else if(tipoCasillero == "Vacio"){
        Casillero* casillero = new Vacio(fila, columna);
        return casillero;
    }
    return nullptr;
}
