#include "tierra.h"

Tierra::Tierra(string nombre, uint escudo, uint vida) : Personaje(nombre, escudo, vida){}

Tierra::Tierra(string nombre) : Personaje(nombre){}

string Tierra::elemento(){
	return elementos[alimento];
}

void Tierra::mostrarEstado(){
	cout << "Nombre: " << _nombre << endl;
	cout << "Escudo: " << _escudo << endl;
	cout << "Energía: " << _energia << endl;
	cout << "Vida: " << _vida << endl;
	cout << "Tipo: " << elemento() << endl;
}

int Tierra::alimentar(){
	const uint _energiaInicial = _energia;
	_energia < 12 ? _energia += 8 : _energia = MAX_ENERGIA;

	return (_energiaInicial <= 12 ? 8 : MAX_ENERGIA - _energiaInicial);
}

void Tierra::mensaje(int recuperado){
	cout << _nombre << " fue alimentado con HIERBAS y recuperó " << recuperado << " puntos de energía." << endl;
}

Tierra::~Tierra(){}