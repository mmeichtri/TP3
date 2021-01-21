#ifndef MENU_H
#define MENU_H

#include "list.h"
#include "personaje.h"
#include "utils.h"


class Menu{
	//Menú de opciones del juego La Batalla de Los Elementos
	//Contiene un acceso a la lista de personajes y su estado está dado por
	//la última opción elegida por el usuario.
	//Inicialmente, es creado con opción = 0;
	//
private:
	List<Personaje*> *listaPersonajes;
	uint opcion;
	//Valores válidos: del 1 al 6.

public:
	Menu(List<Personaje*> *lista);

	bool jugar();
	//PRE:
	//El menú existe.
	//
	//POST:
	//Ejecuta la opción seleccionada y devuelve true salvo si se elije salir (6), 
	//cuyo caso devuelve false y finaliza el juego.
	//
	void pedirOpcion();
	//Post:
	//Setea la opción actual según el valor ingresado por el usuario.
	//
	static void mostrarMenu();
	//POST:
	//Imprime las opciones del menú.
	//
	
};


#endif //MENU_H