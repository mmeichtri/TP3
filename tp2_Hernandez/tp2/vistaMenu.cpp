#include "vistaMenu.h"

void VistaMenu :: menu(){

    cout <<  "     BATALLA DE LOS ELEMENTOS           " << endl;
    cout << "1) AGREGAR NUEVO PERSONAJE  " << endl;
    cout << "2) ELIMINAR UN PERSONAJE "<< endl;
    cout << "3) MOSTRAR TODOS LOS NOMBRES DE LOS PERSONAJES " << endl;
    cout << "4) MOSTRAR DETALLES DE UN PERSONAJE " << endl;
    cout << "5) ALIMENTAR UN PERSONAJE " << endl;
    cout << "6) SALIR  " << endl;
}

string VistaMenu ::ingresarString(string str) {
    string aux;
    cout <<"INGRESE UN "<< str << endl;
    cin >> aux;
    return aux;
}

void VistaMenu :: comprobarOpcion(int *opcion){

    do{
        cout << "INGRESE UNA OPCION VALIDA DEL MENU: " << endl;
        cin >> *opcion;
    }while( (*opcion < 1) || (*opcion > 6) );
}

void VistaMenu :: noEncontro(string str ) {
    cout << "ERROR ESE " << str << " NO EXISTE EN LA LISTA " << endl;
}
void VistaMenu :: yaExiste() {
    cout << "ERROR EL NOMBRE INGRESADO YA ESTA EN LA LISTA" << endl;
}

void VistaMenu :: limpiarPantalla(){

#ifdef WINDOWS
    std :: system("cls");
#else
   std :: system("clear");
#endif

}
void VistaMenu :: saltarLinea(){
      cout << endl;
}
