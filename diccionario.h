#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "bin_search_tree.h"
#include "personaje.h"

using namespace std;


class Diccionario{
private:
	Bst<Personaje*> *conjunto;
	size_t tamanio;

public:
	Diccionario();
	//CONSTRUCTOR
	//
	~Diccionario();
	//DESTRUCTOR
	//
	Personaje* buscar(string nombre);
	//POST: devuelve puntero al personaje buscado por <nombre>. Si no lo encuentra devuelve NULL.
	//
	Personaje* buscarBorrar(string nombre);
	//POST: devuelve puntero al personaje buscado por <nombre> y lo borra del diccionario.
	//Si no lo encuentra devuelve NULL.
	//
	bool incluye(string nombre);
	//POST: devuelve true si el personaje está en el diccionario y false en caso contrario
	//
	bool agregar(Personaje *p);
	//POST: Agrega al personaje apuntado por <p> al diccionario en caso de que no esté ya incluido.
	//
	Personaje* borrarPersonaje(string nombre);
	//POST: Elimina a un personaje del diccionario si su clave coincide con <nombre> y devuelve un
	//puntero al objetivo. 
	//
	void mostrar();
	//POST: Imprime una lista con los nombres de los personajes ordenados alfabéticamente
	//
};

#endif //DICCIONARIO_H