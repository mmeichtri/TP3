#include "par_diccionario.h"



Par::Par(Personaje *&p){
	_clave = p.getNombre();
	_valor = p;
}


Par::Par(string clave){
	_clave = clave;
	_valor = NULL;
}


Personaje *Par::obtenerValor(){
	return _valor;
}


bool Par::operator ==(Par &otro){
	return this->_clave == otro->_clave;
}


bool Par::operator ==(string clave){
	return clave == _clave;
}


Par::~Par(){
	delete _valor;
}