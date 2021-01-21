#include "agua.h"

const uint ALIMENTAR_MAX = 10;


Agua::Agua(string nombre, uint escudo, uint vida) : Personaje(nombre, escudo, vida){
	_vecesAlimentado = 0;
}

Agua::Agua(string nombre) : Personaje(nombre){
	_vecesAlimentado = 0;
}

string Agua::elemento(){
	return elementos[Agua::alimento];
}

void Agua::mostrarEstado(){
	cout << "Nombre: " << _nombre << endl\
		 << "Escudo: " << _escudo<< endl\
		 << "Energía: " << _energia << endl\
		 << "Vida: " << _vida << endl\
		 << "Tipo: " << elemento() << endl;
}

int Agua::alimentar(){
	if (_vecesAlimentado < 3){
		const uint _energiaInicial = _energia;
		_energia <= 10 ? _energia += 10 : _energia = MAX_ENERGIA;
		_vecesAlimentado++;
		return (_energiaInicial <= 10 ? 10 : MAX_ENERGIA - _energiaInicial);
	}
	return -1;
}

void Agua::mensaje(int recuperado){
	if (recuperado == -1)
		cout << _nombre << " ya no puede volver a alientarse." << endl;
	else
		cout << _nombre << " fue alimentado con PLANCTON y recuperó " << recuperado << " puntos de energía." << endl;
}

uint Agua::vecesAlimentado(){
	return _vecesAlimentado;
}


Agua::~Agua(){}