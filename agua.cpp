#include "agua.h"

Agua::Agua(string n,int v,int e, int en,int cant,string el,string al):Personajes(n,v,e,en)
{
    cantAlimentacion=cant;
    elemento=el;
    alimento=al;
}

int Agua::verificarEnergia(int e)
{
   if (e>20)
        return 20;
    else if (e<0)
        return 0;
    else
        return e;
}

string Agua::getElemento()
{
    return elemento;
}

string Agua::getAlimento()
{
    return alimento;
}

void Agua::alimentarse()
{
    int e=energia;
    if (cantAlimentacion==4)
        cout<<"\nno se puede alimentar mas a este personaje, ya no hay mas plancton!!"<<endl;
    else if(energia==20)
    {
        cout<<"\nno se puede alimentar mas a este personaje tiene el maximo de energia(20)!!.";
    }
    else
        {
        cout<<getAlimento()<<" +10!!\n";
        cantAlimentacion++;
        e=e+10;
        energia=verificarEnergia(e);
        }
}


