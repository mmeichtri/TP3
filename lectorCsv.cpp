#include "lectorCsv.h"
#include "lista.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"
#include "interfazUsuario.h"
using namespace std;

LectorCsv::LectorCsv(){
}

void LectorCsv::lecturaCsv(Lista* listaPersonajes, string csv){
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
            cargaListaPersonajes(listaPersonajes, elemento, nombre, escudo, vida);
        }
    }
    archivo.close();
}

Lista* LectorCsv::cargaListaPersonajes(Lista* listaPersonajes, string elemento, string nombre, int escudo, int vida){
    int i = 1;
    if(elemento == "agua"){
        Personaje* p = new Agua(nombre, escudo, vida);
        listaPersonajes->alta(p, i);
    }
    else if(elemento == "tierra"){
        Personaje* p = new Tierra(nombre, escudo, vida);
        listaPersonajes->alta(p, i);
    }
    else if(elemento == "aire"){
        Personaje* p = new Aire(nombre, escudo, vida);
        listaPersonajes->alta(p, i);
    }
    else{
        Personaje* p = new Fuego(nombre, escudo, vida);
        listaPersonajes->alta(p, i);
    }
    i++;
    return listaPersonajes;
}
