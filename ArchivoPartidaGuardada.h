#ifndef TP3_ARCHIVOPARTIDAGUARDADA_H
#define TP3_ARCHIVOPARTIDAGUARDADA_H
#include "juego.h"
#include "personaje.h"


class ArchivoPartidaGuardada {
public:
    //pre : puntero a juego valido
    //post: lee del archivo, llama a crear personaje y le pasa los personajes al juego
void cargarPartida(Juego* juego, Matriz *&tablero);
   //pre: variables validas
   //post: crea un personaje dependiendo del elemento y lo retorna
Personaje* crearPersonaje(string elemento, string nombre, int escudo,int vida, int energia , int fila,int columna, int condicionEspecial);
};


#endif //TP3_ARCHIVOPARTIDAGUARDADA_H