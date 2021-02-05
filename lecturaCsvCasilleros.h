#ifndef LECTURACSVCASILLEROS_H_INCLUDED
#define LECTURACSVCASILLEROS_H_INCLUDED
#include <string>
#include "grafo.h"
#include "casillero.h"
#include "matriz.h"
class LecturaCsvCasilleros{
public:

    /*
    pre:
    post:
    */
    LecturaCsvCasilleros();

    /*
    pre:
    post:
    */
    void lecturaArchivo(Matriz* , Grafo* ,std::string );

    /*
    pre:
    post:
    */
    Casillero* crearCasillero(std::string, int, int);

};

#endif // LECTURACSVCASILLEROS_H_INCLUDED
