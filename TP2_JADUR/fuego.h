#ifndef FUEGO
#define FUEGO

#include "personaje.h"

class Fuego : public Personaje{
	//Personajes de tipo FUEGO se alimentan con MADERA
	//para recuperar 15 puntos de VIDA
	//
private:
	const static alimento_t alimento = MADERA;

public:
	Fuego(string nombre, uint escudo, uint vida);
	Fuego(string nombre);
	~Fuego();

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


#endif //FUEGO_H
