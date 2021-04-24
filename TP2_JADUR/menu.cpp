#include <iostream>
#include <string>
#include <cctype>
#include "menu.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"

const string opcionesValidas[] = {"1","2","3","4","5","6"};
const size_t cantidadOpciones = sizeof(opcionesValidas) /sizeof(string);

typedef void (*accion_t)(List<Personaje*>&, string);



static string leerConsola(){
	string entrada;
	cin >> entrada;
	for (size_t c = 0; c < entrada.length(); c++)
		entrada[c] = tolower(entrada[c]);
	return entrada;
}

static Personaje* crearPersonajeUsuario(string elemento, string nombre){
	Personaje *nuevo = NULL;

	if (elemento == "aire")
		nuevo = new Aire(nombre);
	else if (elemento == "agua")
		nuevo = new Agua(nombre);
	else if (elemento == "fuego")
		nuevo = new Fuego(nombre);
	else if (elemento == "tierra")
		nuevo = new Tierra(nombre);
	else{
		cout << "elemento no válido" << endl;
		return NULL;
	}
	return nuevo;
}

static void _salir(List<Personaje*> &listaPersonajes,string nombre = ""){
	listaPersonajes.clear();
}


static void _agregarPersonaje(List<Personaje*> &listaPersonajes, string nombre){
	cout << "--- AGREGAR PERSONAJE ---" << endl << endl;
	
	string elemento;
	cout << "Ingrese el elemento del personaje: ";
	elemento = leerConsola();

	Personaje *nuevo = crearPersonajeUsuario(elemento, nombre);
	if (nuevo != NULL)
		listaPersonajes.append(nuevo);
}


static void _eliminarPersonaje(List<Personaje*> &listaPersonajes, string nombre){
	cout << "--- ELIMINAR PERSONAJE ---" << endl << endl;
	
	if (listaPersonajes.empty()){
		cout << "La lista está vacía." << endl;
		return;
	}
	if(listaPersonajes.search(nombre, Personaje::compararNombre) != NULL)
		listaPersonajes.remove();
	else
		cout << "El personaje buscado no está en la lista." << endl;
}


static void _mostrarNombresPersonajes(List<Personaje*> &listaPersonajes, string nombre = ""){
	cout << "--- LISTA DE PERSONAJES ---" << endl << endl;
	
	size_t i = 1;
	while (i <= listaPersonajes.length()){
		cout << '('<< i << ')' << listaPersonajes.get(i)->nombre() << endl;
		i++;
	}
}


static void _buscarPersonajeNombre(List<Personaje*> &listaPersonajes, string nombre){
	cout << "--- BUSCAR PERSONAJE --- " << endl << endl;
	Personaje **encontrado = listaPersonajes.search(nombre, Personaje::compararNombre);
	if (encontrado == NULL)
		cout << "No se halló el personaje." << endl;	
	else{
		Personaje * aux = (*encontrado);
		aux->mostrarEstado();
	}
}


static void _alimentar(List<Personaje*> &listaPersonajes, string nombre){
	cout << "--- ALIMENTAR ---" << endl << endl;
	Personaje **encontrado = listaPersonajes.search(nombre, Personaje::compararNombre);
	if (encontrado != NULL){
		Personaje * aux = (*encontrado);
		int recuperado = aux->alimentar();
		aux->mensaje(recuperado);
	}
	else
		cout << "El personaje buscado no está en la lista." << endl;
}


static void mensajeSalida(){
	cout << "Saliendo del juego... " <<
	endl << "Gracias por jugar!" << endl;
}



static const accion_t acciones[] = {
	_salir,
	_agregarPersonaje,
	_eliminarPersonaje,
	_mostrarNombresPersonajes,
	_buscarPersonajeNombre,
	_alimentar
};



//MÉTODOS MENÚ

Menu::Menu(List<Personaje*> *lista){
	listaPersonajes = lista;
	opcion = 0;
}


bool Menu::jugar(){
	string nombre = "";
	if (opcion == 6){
		mensajeSalida();
		acciones[0](*listaPersonajes, nombre);
		return false;
	}
	else if (opcion == 0)
		return true;
	else if (opcion == 1 || opcion == 2 || opcion == 4 || opcion == 5){
		cout << "ingrese un nombre: ";
		nombre = leerConsola();
	}
	acciones[opcion](*listaPersonajes, nombre);
	return true;
}


void Menu::pedirOpcion(){
	string entrada;
	cin >> entrada;

	for (size_t i = 0; i < cantidadOpciones; i++){
		if (entrada == opcionesValidas[i]){
			opcion = stoi(entrada);
			return;
		}
	}
	cout << "Ingrese una opción válida." << endl;
	opcion = 0;		
}


void Menu::mostrarMenu(){
	cout << endl << endl << "### MENÚ ###" << endl << endl;
	
	cout << "1. Agregar nuevo personaje" << endl\
		 << "2. Eliminar personaje"		 << endl\
		 << "3. Mostrar nombres de personajes" << endl\
		 << "4. Mostrar personaje" 		 << endl\
		 << "5. Alimentar personaje"	 << endl\
		 << "6. Salir" << endl << endl;

	cout << "Seleccione una opcion:  ";
}