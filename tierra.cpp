#include "tierra.h"

Tierra::Tierra(string n,int v,int e, int en,string el,string al):Personajes(n,v,e,en)
{
    elemento=el;
    alimento=al;
}

int Tierra::verificarEnergia(int e)
{
       if (e>20)
        return 20;
    else if (e<0)
        return 0;
    else
        return e;
}

string Tierra::getElemento()
{
    return elemento;
}

string Tierra::getAlimento()
{
    return alimento;
}

void Tierra::alimentarse()
{
    int e=energia;

    if(energia==20)
            cout<<"\nel personaje tiene el maximo de energia(20) no puede ser alimentado!!"<<endl;
    else
        {
        cout<<getAlimento()<< "+8!!\n";
        e=e+8;
        energia=verificarEnergia(e);
        }
}
