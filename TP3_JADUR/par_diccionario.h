#ifndef PAR_PERSONAJE_H
#define PAR_PERSONAJE_H
/*
Par clave-valor correspondiente a los personajes del juego.
La clave es una cadena que se coresponde con el nombre del personaje
y el valor es un puntero al personaje en sí.

Dado que hay un único personaje para cada clave y viceversa, los pares
pueden ser comparados con cadenas mediante sus claves (ver operador de igualdad)
*/

#include <string>
#include "personaje.h"

using namespace std;


class Par{
private:
	string _clave;
	Personaje* _valor;

public:
	Par(Personaje *&p);
	Par(string clave);
	~Par();
	bool operator ==(Par &otro);
	bool operator ==(string clave);
};


#endif //PAR_PERSONAJE_H