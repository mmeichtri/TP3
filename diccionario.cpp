#include "diccionario.h"


Diccionario::Diccionario(){
	conjunto = new Bst<Personaje*>;
	tamanio = 0;
}


Personaje* Diccionario::buscar(string nombre){
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
	Queue<Personaje*> * list = conjunto->postOrder();
	if (list == NULL){
		cout << "El conjunto está vacío" << endl;
	}
	else{
		cout << "Personajes: \n < ";
		for (size_t i = 0; i < tamanio; i++)
			cout << list->dequeue()->getNombre() << (i != -tamanio - 1 ? "\n" : " >");
		cout << endl;
		delete list;
	}
}


Diccionario::~Diccionario(){
	delete conjunto;
}
