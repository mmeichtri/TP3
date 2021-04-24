#include <iostream>
#include <string>
#include <fstream>
#include "list.h"
#include "menu.h"
#include "parser.h"
#include "personaje.h"
#include "agua.h"
#include "tierra.h"
#include "fuego.h"
#include "aire.h"
#include "utils.h"


static bool validarArgumentos(int argc);
//Verifica que la cantidad de argumentos ingresados por línea de
//comandos sea correcta.
//Devuelve true o false en caso de éxito o falla respectivamente
//
static List<Personaje*> * procesarArchivo(const char * argv);
//Recibe la ruta o nombre de un archivo CSV con los parámetros principales de los
//personajes iniciales y los procesa para dar inicio al juego.
//PRE:
//EL archivo está bien formado.
//POST:
//Devuelve una lista con los personajes creados en función de la información
//contenida en el archivo.
//
static Personaje* crearPersonajeEntrada(string elemento, string nombre, uint escudo, uint vida);
//Devuelve un puntero a un personaje creado dados su elemento, su nombre,
//el valor de su escudo y su cantidad de vidas.
//



int main(int argc, const char *argv[]){

	if (!validarArgumentos(argc))
		return -1;

	List<Personaje*> *lista = procesarArchivo(argv[1]);

	bool ok = true;
	Menu menu(lista);
	while (ok){	
		Menu::mostrarMenu();
		menu.pedirOpcion();
		ok = menu.jugar();
	} 

	delete lista;
	return 0;
}



static bool validarArgumentos(int argc){
	if (argc == 2)
		return true;
	cout << "Ingrese como único argumento el nombre o ruta "\
			"de un archivo CSV con la información y "\
			"la cantidad de los personajes." << endl;
	return false;
}

static List<Personaje*> * procesarArchivo(const char * path){
	size_t cantidadPersonajes = 0;
	string cantidadstr;

	ifstream input(path);
	getline(input, cantidadstr, '\n');
	cantidadPersonajes = stoi(cantidadstr);

	List<Personaje*> *lista = new List<Personaje*>;

	for (size_t i = 1; i <= cantidadPersonajes; i++){
		ParserElementos p(input);
		Personaje *nuevo = crearPersonajeEntrada(p.elemento(), p.nombre(), p.escudo(), p.vida());
		if (nuevo != NULL) lista->append(nuevo);
	}

	return lista;
}


static Personaje* crearPersonajeEntrada(string elemento, string nombre, uint escudo, uint vida){
	Personaje *nuevo = NULL;

	if (elemento == "aire")
		nuevo = new Aire(nombre, escudo, vida);
	else if (elemento == "agua")
		nuevo = new Agua(nombre, escudo, vida);
	else if (elemento == "fuego")
		nuevo = new Fuego(nombre, escudo, vida);
	else if (elemento == "tierra")
		nuevo = new Tierra(nombre, escudo, vida);
	else{
		cout << "elemento no válido: " << elemento <<endl;
		return NULL;
	}
	return nuevo;
}