
#ifndef TP3_ARCHIVOPERSONAJE_H
#define TP3_ARCHIVOPERSONAJE_H
#include "diccionario.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"
#include "personaje.h"

class ArchivoPersonaje{
private:
    /*
     pre:
     post: crea un personaje del tipo leido en el archivo
     */
    Personaje* crearPersonajes(std::string, std::string, int, int);

    //pre: puntero a diccionario y personaje validos.
    //post:coloca el puntero a personaje en el diccionario
    void cargarDiccionario(Diccionario* ,Personaje*);

public:
    //contructor
    ArchivoPersonaje();

    /*
    pre: recibe una lista vacia, y un archivo csv
    post: se realizo la lectura del archivo, y se cargo el diccionario de personajes, con los que se hallaban en el archivo
    */
    void lecturaCsv(Diccionario* ,std::string);

};

#endif //TP3_ARCHIVOPERSONAJE_H
