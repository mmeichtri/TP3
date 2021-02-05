//
// Created by jose on 2/2/21.
//

#include "archivo.h"

void Archivo :: leerArchivo(Matriz* matriz,grafo* graf){
    Casillero* pointer;
    int cont = 0;
    string linea,tipoCa,fila,columna;
    ifstream arch;
    arch.open("casillero.txt");
    if(!arch.fail()) {
        while (getline(arch, linea)) {
            stringstream split(linea);
            getline(split, tipoCa, ',');
            getline(split, fila, ',');
            getline(split, columna);
            pointer = tipoCasillero(tipoCa, stoi(fila), stoi(columna));
            matriz -> setTablero(pointer,stoi(fila),stoi(columna));
            graf -> ingresarVertice(pointer, cont);
            cont++;
        }
    }
    arch.close();
}
Casillero* Archivo :: tipoCasillero(string tipo , int fila , int columna){
    Casillero* aux;
    if(tipo == "MONTANA")
        aux = new Montana(fila , columna);
    else if(tipo == "LAGO")
        aux = new Lago(fila,columna);
    else if(tipo == "PRECIPICIO")
        aux = new precipicio(fila,columna);
    else if(tipo == "VACIO")
        aux = new vacio(fila, columna);
    else if(tipo == "VOLCAN")
        aux = new volcan (fila,columna);
    else
        aux = new camino(fila,columna);

    return aux;
}