#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>

using namespace std;

class ParserElementos{
	//Contenedor que procesa y guarda la información fundamental sobre un personaje inicial
	//de La Batalla de Los Elementos, almacenada inicialmente en un archivo CSV con el formato
	//elemento,nombre,escudo,vida
	//correspondientes a cada personaje.
	//

private:
	string _elemento;
	string _nombre;
	int _escudo;
	int _vida;

public:
	ParserElementos(ifstream &);
	~ParserElementos();

	//Getters
	string elemento();
	//POST:
	//Devuelve un elemento almacenado tras lectura .
	//
	string nombre();
	//POST
	//Devuelve el nombre de un personaje almacenado tras lectura.
	//
	int escudo();
	//POST:
	//Devuelve el valor de escudo de un personaje almacenado tras lectura.
	//
	int vida();
	//POST:
	//Devuelve la cantidad de vidas de un personaje almacenadas tras lectura.
	//
};

#endif //PARSER_H
