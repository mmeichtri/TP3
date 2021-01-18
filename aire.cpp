#include "aire.h"

Aire::Aire(string n,int v,int e, int en,string el):Personajes(n,v,e,en)
{
    elemento=el;
}

string Aire::getElemento()
{
    return elemento;
}

void Aire::alimentarse()
{
    cout<<"\nlos personajes de aire no se alimentan.!!"<<endl;
}

