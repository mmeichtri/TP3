#include "aire.h"

Aire::Aire(string nombre, uint escudo, uint vida) : Personaje(nombre, escudo, vida) {}

Aire::Aire(string nombre) : Personaje(nombre) {}

string Aire::elemento(){
	return elementos[alimento];
}

void Aire::mostrarEstado(){
	cout << "Nombre: " << _nombre << endl\
		 << "Escudo: " << _escudo<< endl\
		 << "Energía: " << _energia << endl\
		 << "Vida: " << _vida << endl\
		 << "Tipo: " << elemento() << endl;
}

int Aire::alimentar(){ return -1;}

void Aire::mensaje(int recuperado = 0){
	cout << _nombre << " no necesita ser aliementado." << endl;
}

Aire::~Aire(){}