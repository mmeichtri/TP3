#include "agua.h"

Agua :: Agua(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){
    contarComida = 0;
}
Agua :: Agua(string nombre,int escudo,int vida,int energia, int fila , int columna) : Personaje(nombre,escudo,vida,energia,fila,columna){

}

string Agua :: getElemento() {

    return "agua";
}

void Agua :: alimentarse() {

    if(verificarEnergia() && contarComida < 3){
        contarComida++;
        energia = energia + 10;
        imprimirAlimentos();
    } else if(contarComida < 3)
        vista.noSeAlimento();
    else
        vista.imprimirLinea(" Error el personaje no tiene mas oportunidades para alimentarse");
}

bool Agua ::verificarEnergia() {

    return (energia + 10 <= EMAX );

}

void Agua :: imprimirAlimentos() {

         vista.alimentado(getElemento(),"placton",10);

}

bool Agua ::energiaAtaque() {
    return energia >= 5;
}

bool Agua ::energiaDefensa() {
    bool tieneEnergia = energia >= 12;
    if(tieneEnergia ){
        restarEnergia(12);
    }
    return tieneEnergia;

}

int Agua ::danoAtaque(Personaje* personajeAtacar) {

    if(personajeAtacar -> getElemento() == "fuego")
        return 30;
    else if(personajeAtacar -> getElemento() == "tierra")
        return 10;
    else
        return 20;

}

void Agua :: atacar(Personaje** victima) {
   restarEnergia(5);
    bool encontrado = false;
    do{
        int fila =  vista.leerFilaOColumna(" FILA ");
        int columna = vista.leerFilaOColumna(" COLUMNA ");

        for(int i = 0; i < MAXRIVALES; i++){
            if(victima[i]->tieneVida()){
                if(victima[i]->getFila() == fila && victima[i]->getColumna() == columna){
                    atacarPersonaje(victima[i]);
                    encontrado = true;
                }
            }
            noEncontroPersonaje(encontrado);

        }
    }while(!encontrado);
}

void Agua ::noEncontroPersonaje(bool personaje) {
    if(personaje == false)
        vista.noEncontro("el personaje en esa casilla ");
}

void Agua ::atacarPersonaje(Personaje *personajeAtacar) {
    int dano = danoAtaque(personajeAtacar);
    quitarVidaPersonaje(personajeAtacar , dano);
}

void Agua ::modificarPorTurno() {
    return;
}

Agua::~Agua() {

}