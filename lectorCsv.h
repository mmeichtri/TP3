#ifndef LECTORCSV_H_INCLUDED
#define LECTORCSV_H_INCLUDED
#include <string>
#include "lista.h"
class LectorCsv{
public:
    //contructor
    LectorCsv();

    /*
    pre: recibe una lista vacia, y un archivo csv
    post: se realizo la lectura del archivo, y se cargo la lista de personajes, con los que se hallaban en el archivo
    */
    void lecturaCsv(Lista* ,std::string);

    /*
    pre:
    post: carga el personaje recibido, a la lista
    */
    Lista* cargaListaPersonajes(Lista*, std::string, std::string, int, int);
};

#endif // LECTORCSV_H_INCLUDED
