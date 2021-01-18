#include "lista.h"
Lista :: Lista(){
    primero = 0;
    actual = 0;

}

void Lista ::cargarLista(Personaje* personaje) {
    Nodo* nuevo = new Nodo(personaje);
    if(listaVacia())
        primero = nuevo;
    else
        nuevo -> cambiarSiguiente(primero);
primero = nuevo;

}

void Lista :: baja(){
    Nodo* aux;

    aux = primero;
    primero = aux -> obtenerSiguiente();
    delete aux;

}

void Lista :: baja(Nodo *nodo) {
    Nodo* aux ;
    aux = nodo -> obtenerSiguiente();
    nodo -> cambiarSiguiente(aux -> obtenerSiguiente());

        delete aux;
}

void Lista ::mostrarPersonaje() {
    reiniciarActual();
    cout << "ESTA ES LA LISTA DE PERSONAJES : " << endl;
    if(!listaVacia()){
        while(haySiguiente())
            iterar()->obtenerDato()->mostrarNombre();
    }else
        cout << "LA LISTA ESTA VACIA " << endl;
}

bool Lista ::listaVacia() {
    return (primero == nullptr);
}

void Lista :: reiniciarActual() {
    actual = primero;
}

bool Lista :: haySiguiente() {
    return (actual != nullptr);
}


Nodo* Lista ::iterar() {
    Nodo* aux = actual;
    actual = actual->obtenerSiguiente();
    return aux;
}

Nodo* Lista :: buscar(string nombre) {

    bool encontrado = false;
    reiniciarActual();
    Nodo* anterior = actual;

    while(haySiguiente() && !encontrado){

        if(actual -> obtenerDato() -> obtenerNombre() == nombre)
            encontrado = true;
        if(!encontrado)
            anterior = iterar();
    }

    return anterior;
}

Nodo* Lista ::obtenerActual() {
    return actual;
}

Lista ::~Lista() {
    while(!listaVacia())
        baja();
}

