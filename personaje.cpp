#include "personaje.h"
Personaje :: Personaje(string nombre,int escudo,int vida){

    this -> nombre = nombre;
    this -> escudo = escudo;
    this -> vida =vida;
    energia = rand() % (EMAX+1);
}

Personaje ::Personaje(string nombre, int escudo, int vida, int energia, int fila, int columna, int condicionEspecial) {
    this -> nombre = nombre;
    this -> escudo = escudo;
    this -> vida =vida;
    this -> energia = energia;
    this -> fila = fila;
    this -> columna = columna;
}

void Personaje ::mostrarPersonaje(int jugador) {
    vista.mostrarPersonaje(getNombre(),getElemento(),getEscudo(),getEnergia(),getVida(),getFila(),getColumna(), jugador);
}



int Personaje :: defensaEscudo(int valorDano) {

    if(escudo == 1)
        valorDano = valorDano - ((valorDano *10) / 100 );
    else if(escudo == 2)
        valorDano = valorDano - ((valorDano *20) / 100 );
    else if(escudo > 2 ){
        valorDano = valorDano - ((valorDano *80) / 100 );
        modificarEscudo(getEscudo() - 2);
    }
    return valorDano;
}

void Personaje ::cambiarFYC(int fila, int columna) {
    this -> fila = fila;
    this -> columna = columna;
}

int Personaje ::getFila() {
    return fila;
}
int Personaje ::getColumna() {
    return columna;
}

int Personaje ::getVida() {
    return vida;
}

int Personaje ::getEnergia() {
    return energia;
}

void Personaje ::restarVida(int restar) {
    vida = vida - restar;
}



bool Personaje ::comprobarVida() {
    return vida > 0;
}

bool Personaje ::tieneEnergia(int energiaR) {
    return (energia-energiaR >= 0);
}

void Personaje ::restarEnergia(int eRestar) {
    energia = energia - eRestar;
}

void Personaje ::sumarVida(int sumar) {
    if(vida + sumar < 100)
        vida = vida + sumar;
    else
        vida = 100;
}
void Personaje ::sumarEnergia(int sumar) {
    if(energia + sumar < 20)
        energia = energia + sumar;
    else
        energia = 20;
}

void Personaje ::modificarEscudo(int escudo) {
    this -> escudo = escudo;
}
int Personaje ::getEscudo() {
    return escudo;
}

void Personaje ::quitarVidaPersonaje(Personaje *personaAtacado , int ataque) {

    personaAtacado->restarVida( personaAtacado->defensaEscudo(ataque));
    eliminarPersonajeDelJuego(personaAtacado);
}
void Personaje::eliminarPersonajeDelJuego(Personaje *personajeAtacado) {
    if(!personajeAtacado->tieneVida())
        personajeAtacado->cambiarFYC(-10000,-10000);
}


bool Personaje ::tieneVida() {
    return vida > 0;
}

string Personaje ::getNombre() {
    return nombre;
}
