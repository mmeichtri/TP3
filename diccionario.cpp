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
	Personaje** hallado = conjunto->erase(nombre);
//	Personaje *zb = *hallado;
//	cout << "se encontró al personaje " << zb->nombre() << endl;
	return hallado == NULL ? NULL : *hallado;
}


bool Diccionario::incluye(string nombre){
	return (buscar(nombre) != NULL);
}


void Diccionario::agregar(Personaje *p){
	//Está línea podría omitirse y ejecutarse
	// |  por fuera antes de llamar a agregar()
	// |
	// V
	if (!incluye(p->nombre())) 
		conjunto->add(p, p->nombre());
	tamanio++;
}


Personaje* Diccionario::borrarPersonaje(string nombre){
	Personaje **aBorrar = conjunto->erase(nombre);
	tamanio--;
	return aBorrar == NULL ? NULL : *aBorrar;
}


Diccionario::~Diccionario(){
	delete conjunto;
}
