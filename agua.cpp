#include "agua.h"

Agua :: Agua(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){
    contarComida = 0;
}

string Agua ::elemento() {
    string element = "AGUA";
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
    return energia >= 5;
}

bool Agua ::energiaDefensa() {
    return energia >= 12;
}

int Agua ::danoAtaque(Personaje* personajeAtacar) {

    if(personajeAtacar -> elemento() == "FUEGO")
        return 30;
    else if(personajeAtacar -> elemento() == "TIERRA")
        return 10;
    else
        return 20;

}

int Agua :: atacar(Personaje *personajeAtacado) {

        return danoAtaque(personajeAtacado);

}

void Agua :: defenderse(Personaje* aliados[3]) {

   energia = energia - 12;

   vidaDefenderse();

    for(int i = 0; i < 3 ; i++)
        aliados[i] -> modificarVida(aliados[i] -> obtenerVida() + 10);
}

void Agua ::vidaDefenderse() {

    if(vida + 50 < 100)
        vida = vida+ 50;
    else
        vida = 100;
}

Agua::~Agua() {

}