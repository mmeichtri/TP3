/*
#include "logFile.h"
#include "personaje.h"
#include <iostream>
#include <fstream>

using namespace std;

LogFile::LogFile(){
}

void LogFile::actualizarLog(Personaje* personaje){
    fstream file;
    file.open("partida.csv");
    
    file << personaje->getElemento() +","<< personaje->getNombre() +","<< personaje->getEscudo() +","<< pesonaje->getVida() +","<< personaje->mostrarEnergiaActual() +","<< personaje->getFila() +","<< persoanje->getColumna() << endl;
    
    file.close();
}
*/