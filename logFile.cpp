#include "logFile.h"
#include "personaje.h"
#include <iostream>
#include <fstream>

using namespace std;

LogFile::LogFile(){
}

void LogFile::crearLog(){
    fstream file;
    file.open("partida.csv");

    file.close();
}

void LogFile::actualizarLog(Personaje* elemento){

}
