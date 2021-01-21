#include "personaje.h"
#include <time.h>

typedef enum {AGUA, FUEGO, TIERRA, AIRE} elemento_t;


Personaje::Personaje(string nombre, uint escudo, uint vida){
	_nombre = nombre;
	_escudo = escudo;
	_vida = vida;
	_energia = setEnergiaInicial();	
}

Personaje::Personaje(string nombre){
	srand(time(NULL));
	_nombre = nombre;
	_escudo = rand() % 3;
	_vida = rand() % 91 + 10;
	_energia = setEnergiaInicial();
}

//Getters
string Personaje::nombre() {return _nombre;}

uint Personaje::vida() {return _vida;}

uint Personaje::escudo() {return _escudo;}

uint Personaje::energia() {return _energia;}



bool Personaje::operator <(Personaje *otro){
	return this->_nombre < otro->_nombre;
}

bool Personaje::operator >(Personaje *otro){
	return this->_nombre > otro->_nombre;
}

bool Personaje::operator ==(Personaje *otro){
	return this->_nombre == otro->_nombre;
}

bool Personaje::operator ==(string nombre){
	return _nombre == nombre;
}


int Personaje::compararNombre(Personaje *p, const void *nombre){

	if(p->nombre() == *(string*)nombre)
		return 0;
	if (p->nombre() < *(string*)nombre)
		return 1;
	return -1;
}


//setters
uint Personaje::setEnergiaInicial(){
	srand(time(NULL));
	return rand() % 20; 
}



Personaje::~Personaje(){}