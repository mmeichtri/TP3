#include "agua.h"

Agua :: Agua(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){
    contarComida = 0;
}

string Agua :: getElemento() {

    string element = "agua";
    return element;
}

void Agua :: alimentarse() {

    if(verificarEnergia()){
        contarComida++;
        energia = energia + 10;
        imprimirAlimentos();
    }
    else
        cout << "ERROR NO SE PUDO ALIMENTAR AL PERSONAJE" << endl;
}

bool Agua ::verificarEnergia() {

    return ((energia + 10 <= EMAX ) && (contarComida < 3));

}

void Agua :: imprimirAlimentos() {

    cout << "SE ALIMENTO AL PERSONAJE DE AGUA : " << nombre << " CON PLACTON Y RECUPERO 10 PUNTOS DE ENERGIA AHORA TIENE  "<< energia << endl;
}

bool Agua ::energiaAtaque() {
    if (energia >= 5)
        restarEnergia(5);
    return energia >= 5;
}

bool Agua ::energiaDefensa() {
    return energia >= 12;
}

int Agua ::danoAtaque(Personaje* personajeAtacar) {

    if(personajeAtacar -> getElemento() == "fuego")
        return 30;
    else if(personajeAtacar -> getElemento() == "tierra")
        return 10;
    else
        return 20;

}

int Agua :: atacar(Personaje* victima) {

   return danoAtaque(victima);
}

void Agua :: defenderse() {

   sumarVida(50);

}


Agua::~Agua() {

}