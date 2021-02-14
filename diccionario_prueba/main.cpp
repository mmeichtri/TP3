#include <iostream>
#include <string>
#include <fstream>
#include "parser.h"
#include "personaje.h"
#include "aire.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "diccionario.h"
#include "utils.h"

using namespace std;


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

static Diccionario *procesarArchivo(const char *path){
	size_t cantidadPersonajes = 0;
	string cantidadstr;

	ifstream input(path);
	getline(input, cantidadstr, '\n');
	cantidadPersonajes = stoi(cantidadstr);

	Diccionario *dic = new Diccionario;

	for (size_t i = 1; i <= cantidadPersonajes; i++){
		ParserElementos p(input);
		Personaje *nuevo = crearPersonajeEntrada(p.elemento(), p.nombre(), p.escudo(), p.vida());
		if (nuevo != NULL) dic->agregar(nuevo);
	}

	return dic;
}

bool run_test(Diccionario *dic, string clave){
	Personaje * hallado = dic->buscar(clave);
	if (hallado == NULL){
		cout << clave << " no está en el conjunto." << endl;
		return false;
	}
	cout << hallado->nombre() << " está en el conjunto." << endl;
	return true;
}

void test_loop(Diccionario *dic){
	string clave = "";
	for (size_t i = 0; i < 10; i++){
		cout << "ingresá un nombre: ";
		cin >> clave;
		cout << endl;
		run_test(dic, clave);
	}
	cout << "eliminar personaje: ";
	cin >> clave;
	dic->borrarPersonaje(clave);
	cout << endl;
	for (size_t i = 0; i < 10; i++){
		string clave = "";
		cout << "ingresá un nombre: ";
		cin >> clave;
		cout << endl;
		run_test(dic, clave);	
	}
}



int main(int argc, char const *argv[]){
	if (argc != 2)
		return -1;
	Diccionario *d = procesarArchivo(argv[1]);

	test_loop(d);

	return 0;
}