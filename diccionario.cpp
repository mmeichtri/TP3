#include "diccionario.h"


Diccionario::Diccionario(){
	conjunto = new Bst<Personaje*>;
	tamanio = 0;
}

Personaje* Diccionario::buscar(string nombre){
	if (conjunto->empty())
		return NULL;
	//
	//Bst::search(...) devuelve un puntero al tipo de dato guardado.
	//Como en esta implementación el diccionario guarda como valores
	//PUNTEROS a personaje, al obtener el resultado de search() es
	//necesario desreferenciar el objeto para no devolver un puntero doble.
	Personaje** hallado = conjunto->search(nombre);
	return hallado == NULL ? NULL : *hallado;
}


Personaje* Diccionario::buscarBorrar(string nombre){
	if (conjunto->empty())
		return NULL;
	return borrarPersonaje(nombre);
}


bool Diccionario::incluye(string nombre){
	return (buscar(nombre) != NULL);
}


void Diccionario::agregar(Personaje *p){
	if (!incluye(p->getNombre())) 
		conjunto->add(p, p->getNombre());
	tamanio++;
}


Personaje* Diccionario::borrarPersonaje(string nombre){
	if (tamanio == 0)
		return NULL;

	Personaje *aBorrar;
	if (tamanio == 1){
		Personaje** aux = conjunto->getData();
		aBorrar = *aux;
		delete conjunto;
		conjunto = NULL;
	}
	else
		conjunto->erase(nombre, aBorrar);
	tamanio--;
	return aBorrar;
}


void Diccionario::mostrar(){
	Queue<Personaje*> * list = conjunto->preOrder();
	if (list == NULL){
		cout << "No hay personajes..." << endl;
	}
	else{
		cout << "Personajes: " << endl << endl;
		for (size_t i = 0; i < tamanio; i++)
			cout <<  __TEXT_YLW__ << list->dequeue()->getNombre() << (i != -tamanio - 1 ? "\n" : " ") << __TEXT_NC__;
		cout << endl;
		delete list;
	}
}


Diccionario::~Diccionario(){
	delete conjunto;
}
