#include "parser.h"


ParserElementos::ParserElementos(ifstream &input){
	string escudo;
	string vida;
	getline(input, _elemento, ',');
	getline(input, _nombre, ',');
	getline(input, escudo, ',');
	getline(input, vida, '\n');
	_escudo = stoi(escudo);
	_vida = stoi(vida);
}

string ParserElementos::elemento(){
	return _elemento;
}

string ParserElementos::nombre(){
	return _nombre;
}
	
uint ParserElementos::escudo(){
	return _escudo;
}

uint ParserElementos::vida(){
	return _vida;
}


ParserElementos::~ParserElementos(){

}