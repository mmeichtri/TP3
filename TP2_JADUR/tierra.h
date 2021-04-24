#ifndef TIERRA_H
#define TIERRA_H

#include "personaje.h"

class Tierra: public Personaje{
	//Personajes de tipo TIERRA se alimentan con HIERBAS
	//para recuperar 15 puntos de ENERGÍA
	//
private:
	const static alimento_t alimento = HIERBAS;
	
public:
	Tierra(string nombre, uint escudo, uint vida);
	Tierra(string nombre);
	~Tierra();

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
};


#endif //TIERRA_H