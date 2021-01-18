#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Personajes {
	protected:
	//atributos
		string nombre;
		int vida;
		int escudo;
		int energia;

	public:
	//metodos

		//contructor
        Personajes(string n,int v,int e,int en);

        //pre:-
        //post:devuelve el elemento en las clases derivadas.
        virtual string getElemento()=0;

		//pre: -
		//pos: alimenta al personaje de diferente manera en las  clases derivadas.

		virtual void alimentarse();

        //pre: ingresar un nombre valido es decir aceptar unicamente letras del abecedario, no ingresar caracteres especiales ni numeros.
        //post: le da un nombre a un nuevo objeto personajes.
		void setNombre(string n);

		//pre: ingresar un valor de tipo entero que represente la vida, este valor se encuentra vida>10 && vida<100.
		//post: le otorga un valor de tipo entero al objeto personaje que representa su cantidad de vida.
		void setVida(int vid);

		//pre: ingresar un valor de tipo entero valido que represente el escudo, este valor se encuentra escudo>0 && escudo<2.
		//post: le otorga un valor de tipo entero al objeto personaje que representa su cantidad de escudo.
		void setEscudo(int esc);

		//pre: ingresar un valor de tipo entero valido que represente el escudo, este valor se encuentra escudo>0 && escudo<2.
		//post: le otorga un valor de tipo entero al objeto personaje que representa su cantidad de energia.
		void setEnergia(int en);

		//pre: la vida del personaje tiene que ser >10 y <100.
		//post: devuelve el valor de tipo entero de la vida del personaje.
		int getVida();

		//pre: escudo tiene que valer 0,1 o 2.
		//post: devuelve el valor de tipo entero del escudo del personaje.
		int getEscudo();

		//pre:validar energia tiene que ser true.
		//post:me devuelve la cantidad de energia del personaje de tipo entero.
		int getEnergia();

		//pre:-
		//post: devuele el nombre del personaje.
		string getNombre();

		//pre:-
		//post: valida si la cantidad de energia del personaje es valida, es decir si su cantidad.
		//de energia es >=20 y 0=< entonces devuelve false sino devuelve true.
		bool validarEnergia();

};


#endif // PERSONAJES_H_INCLUDED
