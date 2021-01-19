

#include "arbol.h"

arbol ::arbol() {

    raiz = nullptr;
}

void arbol ::cargarArbol(DATO clave) {

    this -> raiz = setArbol(raiz, nullptr , clave);
}

nodo* arbol ::setArbol(nodo *Nodo, nodo *papa, DATO clave) {

    if(Nodo == nullptr){
        nodo* nuevo = new nodo(clave,papa);
       Nodo = nuevo;
    }
    else{
        if(clave > Nodo -> getClave())
            Nodo -> setDerecho(setArbol(Nodo -> getDerecho(),Nodo,clave));
        else
            Nodo -> setIzq(setArbol(Nodo -> getIzq(),Nodo,clave));
    }

    return Nodo;
}

void arbol ::inOrden(nodo *Nodo) {
    if(Nodo == nullptr){
        return;
    }
    else{

        inOrden(Nodo -> getIzq());
        cout << Nodo -> getClave() << endl;
        inOrden(Nodo -> getDerecho());

    }

}

nodo* arbol::busqueda(nodo *Nodo, DATO clave) {

    if(Nodo == nullptr)
        return Nodo;

    else if(Nodo -> getClave() == clave)
        return Nodo;

    else {
            if(clave > Nodo -> getClave())
             return  busqueda(Nodo -> getDerecho(),clave);
            else
            return busqueda(Nodo -> getIzq(),clave);
        }

}

void arbol::eliminarNodo(DATO clave) {

    nodo* buscar = busqueda(raiz , clave);
    if( buscar != nullptr)
          eliminarNodo(buscar);
    else
        cout << "NODO NO EXISTE " << endl;
}

void arbol::eliminarNodo(nodo *Nodo) {

    if(Nodo -> getIzq() == nullptr && Nodo -> getDerecho() == nullptr) {
        eliminarHoja(Nodo);
        deleteNodo(Nodo);
    }
    else if( Nodo -> getIzq() == nullptr && Nodo -> getDerecho()){
        eliminarUnHijo(Nodo,Nodo -> getDerecho());
        deleteNodo(Nodo);
    }
    else if(Nodo -> getIzq() && Nodo -> getDerecho() == nullptr){
        eliminarUnHijo(Nodo,Nodo -> getIzq());
        deleteNodo(Nodo);
    }
    else{
        nodo* aux = eliminarDosHijos(Nodo);
        eliminarNodo(aux);
    }
}

nodo* arbol::eliminarDosHijos(nodo *Nodo) {

   nodo* aux = nodoMasIzquierda(Nodo -> getDerecho());
   Nodo -> setClave(aux -> getClave());
    return aux;
}

nodo* arbol::nodoMasIzquierda(nodo *Nodo) {

    if(Nodo -> getIzq() == nullptr)
        return Nodo;
    else
        return nodoMasIzquierda(Nodo -> getIzq());

}

void arbol ::eliminarUnHijo(nodo* Nodo, nodo* hijo) {

    if(Nodo -> getPadre() -> getDerecho() != nullptr)
        Nodo -> getPadre() -> setDerecho(hijo);
    else
        Nodo -> getPadre() -> setIzq(hijo);

 hijo -> setPadre(Nodo -> getPadre());

}

void arbol::eliminarHoja(nodo *Nodo) {


    if(Nodo -> getPadre() -> getDerecho()  != nullptr){
        if(Nodo -> getPadre() -> getDerecho() -> getClave() == Nodo -> getClave())
            Nodo -> getPadre() -> setDerecho(nullptr);
    }
    if(Nodo -> getPadre() -> getIzq() != nullptr){
        if(Nodo -> getPadre() -> getIzq() -> getClave() == Nodo -> getClave ())
            Nodo -> getPadre() -> setIzq(nullptr);
    }

}

void arbol::deleteNodo(nodo *Nodo) {

    Nodo -> setIzq(nullptr);
    Nodo -> setDerecho(nullptr);
    delete Nodo;
}

nodo* arbol ::getRaiz() {
    return raiz;
}

void arbol::eliminarTodo(nodo *Nodo) {
    if(Nodo == nullptr)
        return;
    else{
        eliminarTodo(Nodo -> getIzq());
        eliminarTodo(Nodo -> getDerecho());
        delete Nodo;
    }
}

arbol ::~arbol() {
    eliminarTodo(raiz);
}