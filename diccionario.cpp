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
	//EstÃ¡ lÃ­nea podrÃ­a omitirse y ejecutarse
	// |  por fuera antes de llamar a agregar()
	// |
	// V
	if (!incluye(p->getNombre())) 
		conjunto->add(p, p->getNombre());
	tamanio++;
}


Personaje* Diccionario::borrarPersonaje(string nombre){
	Personaje *aBorrar;
	conjunto->erase(nombre, aBorrar);
	tamanio--;
	return aBorrar;
}


void Diccionario::mostrar(){
	Queue<Personaje*> * list = conjunto->inOrder();
	if (list == NULL){
		cout << "El conjunto está vacío" << endl;
	}
	else{
		cout << endl;
		for (size_t i = 0; i < tamanio; i++)
			cout << list->dequeue()->getNombre() << (i != -tamanio - 1 ? "\n" : " >");
		cout << endl;
		delete list;
	}
}


Diccionario::~Diccionario(){
	delete conjunto;
}
