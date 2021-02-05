#include "lecturaCsvCasilleros.h"
#include "grafo.h"
#include <iostream>
#include <string>
using namespace std;

LecturaCsvCasilleros::LecturaCsvCasilleros(){

}

//archivo->mapa.csv
void LecturaCsvCasilleros::lecturaArchivo(Grafo* matrizAdyacencia, string csv){
    ifstream archivo;
    archivo.open(csv);
    if (archivo.fail()){
        cout<< "Error al abrir el archivo"<< endl;
        exit(1);
    }

    string linea, aux, tipoCasillero;
    int fila, columna;

    while(!archivo.eof()){
        if(getline(archivo, aux, ',')){
            elemento = aux;
            getline(archivo, aux, ',');
            tipoCasillero = aux;
            getline(archivo, aux, ',');
            fila = std::stoi(aux);
            getline(archivo, aux, '\n');
            columna = std::stoi(aux);
            cargaCasillerosPersonajes(matrizAdyacencia, tipoCasillero, fila, columna);
        }
    }
    archivo.close();
}

void cargaMatrizAdyacencia(Grafo* matrizAdyacencia, string tipoCasillero, int fila, int columna){
    if(tipoCasillero == "Lago"){
        Casillero* casillero = new Lago();
    }
    if(tipoCasillero == "Precipicio"){
        Casillero* casillero = new Precipicio(fila, columna);
    }
    if(tipoCasillero == "Montania"){
        Casillero* casillero = new Montania(fila, columna);
    }
    if(tipoCasillero == "Volcan"){
        Casillero* casillero = new Volcan(fila, columna);
    }
    if(tipoCasillero == "Camino"){
        Casillero* casillero = new Camino(fila, columna);
    }
    if(tipoCasillero == "Vacio"){
        Casillero* casillero = new Vacio(fila, columna);
    }
}
