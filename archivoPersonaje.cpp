//
// Created by jose on 24/2/21.
//

#include "archivoPersonaje.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

ArchivoPersonaje ::ArchivoPersonaje(){
}

void ArchivoPersonaje::lecturaCsv(Diccionario* diccionario, std::string csv) {
    ifstream archivo;
    archivo.open(csv);
    if (archivo.fail()){
        cout<< "Error al abrir el archivo"<< endl;
        exit(1);
    }

    string linea, aux, elemento, nombre;
    int vida, escudo;

    while(!archivo.eof()){
        if(getline(archivo, aux, ',')){
            elemento = aux;
            getline(archivo, aux, ',');
            nombre = aux;
            getline(archivo, aux, ',');
            escudo = std::stoi(aux);
            getline(archivo, aux, '\n');
            vida = std::stoi(aux);
         cargarDiccionario(diccionario,crearPersonajes(elemento,nombre,escudo,vida));
        }
    }
    archivo.close();
}

Personaje* ArchivoPersonaje::crearPersonajes( string elemento, string nombre, int escudo, int vida){
    Personaje* p;
    if(elemento == "agua")
         p = new Agua(nombre, escudo, vida);
    else if(elemento == "tierra")
         p = new Tierra(nombre, escudo, vida);
    else if(elemento == "aire")
         p = new Aire(nombre, escudo, vida);
    else
         p = new Fuego(nombre, escudo, vida);

    return p;
}
void ArchivoPersonaje ::cargarDiccionario(Diccionario * diccionario, Personaje* personaje) {
    diccionario->agregar(personaje);
}