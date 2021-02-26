#include <stdio.h>
#include <fstream>

using namespace std;

class Log{
private:
	int _jugador;
	Personaje* jug1[3];
	Personaje* jug2[3];

public:
	Log(int jugador, Juego &partida){
		_jugador = jugador;
		for (size_t i = 0; i < 3 < i++){
			jug1[i] = partida/*.método que devuelva un personaje del jugador 1()*/;
			jug2[i] = partida/*.método que devuelva un personaje del jugador 2()*/;
		}
	}

	ostream *guardar(){
		ofstream *file;

		file->open("partida_guardada");
		file << _jugador << endl;
		for (size_t i = 0; i < 3; i++){

			file << jug1[i]->getElemento() << ","\
			<< jug1[i]->getNombre() << ","\
			<< jug1[i]->getEscudo() << ","\
			<< jug1[i]->getVida() << ","\
			<< jug1[i]->getEnergia() << ","\
			<< jug1[i]->getFila() << ","\
			<< jug1[i]->getColumna() << "," << endl;
		}
		for (size_t i = 0; i < 3; i++){
			file << jug2[i]->getElemento() << ","\
			<< jug2[i]->getNombre() << ","\
			<< jug2[i]->getEscudo() << ","\
			<< jug2[i]->getVida() << ","\
			<< jug2[i]->getEnergia() << ","\
			<< jug2[i]->getFila() << ","\
			<< jug2[i]->getColumna() << "," << endl;
		}
		return file;
	}

	~Log(){/*no hay que liberar nada porque no se crea ningún objeto en el heap*/}
	
};

