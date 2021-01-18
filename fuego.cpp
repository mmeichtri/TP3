#include "fuego.h"

int Fuego::verificarVida(int v)
{
    if (v>100)
        return 100;
    else if (v<10)
        return 10;
    else
        return v;
}

Fuego::Fuego(string n,int v,int e, int en,string el,string al):Personajes(n,v,e,en)
{
    elemento=el;
    alimento=al;
}

string Fuego::getElemento()
{
    return elemento;
}

string Fuego::getAlimento()
{
    return alimento;
}

void Fuego::alimentarse()
{
    int v=vida;
    if (vida==100)
        cout<<"\nno se puede alimentar mas a este personaje tiene la vida maxima (100)!!"<<endl;
    else
        {
        cout<<getAlimento()<<" +15!!\n";
        v=v+15;
        vida=verificarVida(v);
        }
}
