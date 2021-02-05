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

    }
    if(tipoCasillero == "Precipicio"){

    }
    if(tipoCasillero == "Montania"){

    }
    if(tipoCasillero == "Volcan"){

    }
    if(tipoCasillero == "Camino"){

    }
    if(tipoCasillero == "Vacio"){

    }
}
