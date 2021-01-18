#include "personajes.h"

using namespace std;

void Personajes::alimentarse()
{
    cout<<"El personaje se alimento con:";
}

void Personajes::setNombre(string n)
{
    nombre=n;
}

void Personajes::setEnergia(int en)
{
    energia=en;
}

void Personajes::setVida(int vid)
{
    vida=vid;
}

void Personajes::setEscudo(int esc)
{
    escudo=esc;
}

int Personajes::getVida()
{
 return vida;
}

int Personajes::getEscudo()
{
    return escudo;
}

int Personajes::getEnergia()
{
    return energia;
}

string Personajes::getNombre()
{
    return nombre;
}

bool Personajes::validarEnergia()
{
    if (energia>=0 && energia<=20)
        return true;
    return false;
}

Personajes::Personajes(string n,int v,int e,int en)
{
    nombre=n;
    vida=v;
    escudo=e;
    energia=en;
}
