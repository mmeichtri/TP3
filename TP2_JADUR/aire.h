#ifndef AIRE_H
#define AIRE_H

#include "personaje.h"

class Aire : public Personaje{
	//Personajes de tipo Aire
	//no necesitan alimentarse
	//no pueden recuperar ni ENERGÍA ni VIDA
	//
private:
	static const alimento_t alimento = NADA;
public:
	Aire(string nombre, uint escudo, uint vida);
	Aire(string nombre);
	~Aire();

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


#endif //AIRE_H