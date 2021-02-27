#include "argumentos.h"

static void mensajeArgumentos(){
    cout << "Debe ejecutar el programa de la siguiente manera:" << endl << __TEXT_YLW__\
    << "./<nombre_ejecutable> <personajes_datos> <mapa_datos> " << __TEXT_NC__ << endl \
    << endl << "Aviso: los archivos deben ser de texto en formato CSV y estar correctamente escritos."\
    << endl;
}

bool validarArgs(int argc){
    if (argc != 3){
        mensajeArgumentos();
        return false;
    }
    return true;
}