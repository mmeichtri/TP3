#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "bin_search_tree.h"
#include "personaje.h"

using namespace std;


class Diccionario{
private:
	Bst<Personaje*> *conjunto;	//arbol de punteros a par (cada nodo tiene un puntero a par)
	size_t tamanio;

public:
	Diccionario();
	~Diccionario();
	Personaje* buscar(string nombre);
	//Busca por nombre (clave) y, si encuentra, devuelve puntero al personaje
	//
	bool incluye(string nombre);
	//Consulta si el personaje está en el diccionario
	//
	void agregar(Personaje *p);
	//Agrega personaje al diccionario en caso de que no esté
	//

};

#endif //DICCIONARIO_H
