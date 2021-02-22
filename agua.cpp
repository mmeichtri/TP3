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

void Agua :: atacar(Personaje** victima) {

    bool encontrado = false;
    do{
        int fila =  vista.leerFilaOColumna(" FILA ");
        int columna = vista.leerFilaOColumna(" COLUMNA ");

        for(int i = 0; i < MAXRIVALES; i++){
            if(victima[i] != nullptr){
                if(victima[i]->obtenerFila() == fila && victima[i]->obtenerColumna() == columna){
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