#include "fuego.h"



Fuego::Fuego(string nombre, uint escudo, uint vida) : Personaje(nombre, escudo, vida){}

Fuego::Fuego(string nombre) : Personaje(nombre){}

string Fuego::elemento(){
	return elementos[alimento];
}

void Fuego::mostrarEstado(){
	cout << "Nombre: " << _nombre << endl\
		 << "Escudo: " << _escudo<< endl\
		 << "Energía: " << _energia << endl\
		 << "Vida: " << _vida << endl\
		 << "Tipo: " << elemento() << endl;
}

int Fuego::alimentar(){
	const uint _vidaInicial = _vida;
	_vida <= 85 ? _vida += 15 : _vida = MAX_VIDA;

	return (_vidaInicial <= 85 ? 15 : MAX_VIDA - _vidaInicial);
}

void Fuego::mensaje(int recuperado){
	cout << _nombre << " fue alimentado con MADERA y recuperó " << recuperado << " puntos de vida." << endl;
}

Fuego::~Fuego(){}