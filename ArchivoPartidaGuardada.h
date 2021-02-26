

#ifndef TP3_ARCHIVOPARTIDAGUARDADA_H
#define TP3_ARCHIVOPARTIDAGUARDADA_H
#include "juego.h"
#include "personaje.h"


class ArchivoPartidaGuardada {
public:
void cargarPartida(Juego* juego);
Personaje* crearPersonaje(string elemento, string nombre, int escudo,int vida, int energia , int fila,int columna, int condicionEspecial);
};


#endif //TP3_ARCHIVOPARTIDAGUARDADA_H
