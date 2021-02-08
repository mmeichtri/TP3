#include "diccionario.h"
Diccionario::Diccionario(){
	conjunto = NULL;
	tamanio = 0;
}


Personaje* Diccionario::buscar(string nombre){
	//
	//Bst::search(...) devuelve un puntero al tipo de dato guardado.
	//Como en esta implementación el diccionario guarda como valores
	//PUNTEROS a personaje, al obtener el resultado de searc() es
	//necesario desreferenciar el objeto para no devolver un puntero doble.
	Personaje* hallado = *(conjunto->search(nombre));	//Bst::search()
	return hallado;
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
