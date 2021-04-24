#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include "utils.h"


typedef enum {NADA, PLANCTON, HIERBAS, MADERA} alimento_t;

const string elementos[] = {"Aire", "Agua", "Tierra", "Fuego"};


class Personaje{

protected:
	string _nombre;
	uint _vida;
	uint _escudo;
	uint _energia;
	

public:
	static const uint MAX_ENERGIA = 20;
	static const uint MAX_VIDA = 100;

	Personaje(string nombre, uint escudo, uint vida);
	//POST:
	//Crea un personaje con los parámetros determinados y un valor aleatorio de energía entre 0 y 20.
	//
	//
	Personaje(string nombre);
	//POST:
	//Crea un personaje con el nombre elegido y sus demás atributos con valores aleatorios validos.
	//
	//
	virtual ~Personaje();
	//
	//
	
	//Getters
	string nombre();
	//PRE:
	//El personaje existe.
	//
	//POST:
	//Devuelve el nombre del personaje.
	//
	//
	uint vida();
	//PRE:
	//El personaje existe.
	//
	//POST:
	//Devuelve la cantidad de vidas del personaje.
	//
	//
	uint escudo();
	//PRE:
	//El personaje existe.
	//
	//POST:
	//Devuelve el valor de escudo del personaje.
	//
	//
	uint energia();
	//PRE:
	//El personaje existe.
	//
	//POST:
	//Devuelve la energía del personaje.
	//
	//
	virtual string elemento() = 0;
	//PRE:
	//El personaje es una instancia heredera de la clase Personaje
	//
	//POST:
	//devuelve una cadena indicando a qué clase heredera (elemento) pertenece.
	//
	//
	virtual void mostrarEstado() = 0;
	//PRE:
	//El personaje es una instancia heredera de la clase Personaje
	//
	//POST:
	//Muestra por la terminal el estado actual del personaje.
	//

	//Operadores
	virtual bool operator <(Personaje *otro);
	//
	//
	virtual bool operator >(Personaje *otro);
	//
	virtual bool operator ==(Personaje *otro);
	//
	virtual bool operator ==(string nombre);
	//
	//
	static int compararNombre(Personaje *p, const void *nombre);
	//Compara si una clave <nombre> coincide con el nombre de un personaje apuntado por <p>
	//PRE:
	//p no es nulo.
	//POST:
	//Devuelve un número negativo, nulo (0) o positivo si el nombre del personaje es
	//lexicográficamente menor, igual o mayor que la clave respectivamente.
	//
	//
	virtual int alimentar() = 0;
	//POST:
	//alimenta al personaje y devuelve la cantidad de energía que sumó
	//
	//
	virtual void mensaje(int recuperado) = 0;
	//POST:
	//imprime un mensaje indicando cuánta energía recuperó el personaje
	//
	//
	static uint setEnergiaInicial();
	//POST:
	//Devuelve un valor aleatorio entre 0 y 20.
	//
	//
};




#endif //PERSONAJE_H