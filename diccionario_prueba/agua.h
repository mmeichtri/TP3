#ifndef AGUA_H
#define AGUA_H

#include "personaje.h"

class Agua : public Personaje{
	//Personajes de tipo AGUA se alimentan con Plancton
	//para recuperar 10 puntos de ENERGÍA y
	//sólo pueden alimentarse 3 veces.
	//
private:
	const static alimento_t alimento = PLANCTON;
	uint _vecesAlimentado;

public:
	Agua(string nombre, uint escudo, uint vida);
	Agua(string nombre);
	~Agua();

	string elemento();
	//
	//
	void mostrarEstado();
	//
	//
	int alimentar();
	//
	//
	void mensaje(int recuperado);
	//
	//
	uint vecesAlimentado();
	//PRE:
	//El valor inicial es 0
	//
	//POST:
	//Devuelve la cantidad de veces que fue alimentado el personaje
	//
	//
};


#endif //AGUA_H
