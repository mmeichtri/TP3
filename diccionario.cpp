#include "diccionario.h"

Diccionario::Diccionario(){
	conjunto = NULL;
	tamanio = 0;
}


Personaje* Diccionario::buscar(string nombre){
	Par *aux = new Par(nombre);
	//
	//primero, Bst::search(string) llama a Bstnodo::search(string)
	//y ésta última compara el argumento con el objeto guardado en el nodo
	//OJO: los search() devuelven puntero al dato guardado en el nodo.
	//Como los nodos guardan PUNTERO A PAR, hay que desreferenciar lo que devuelva search (puntero a puntero a par)
	//
	//Una vez hallado el par, se deuelve el valor (puntero a personaje) que guarda.
	Par* hallado = *(conjunto->search(aux));	//Bst::search()
	delete aux;
	return hallado->obtenerValor();
}


bool Diccionario::incluye(string nombre){
	return (buscar(nombre) != NULL);
}


void Diccionario::agregar(Personaje *p){
	//Está línea podría omitirse y ejecutarse
	// |  por fuera antes de llamar a agregar()
	// |
	// V
	if (!incluye(p->getNombre())) 
		conjunto->add(p);
	tamanio++;
}


Diccionario::~Diccionario(){
	delete conjunto;
}