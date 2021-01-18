#include "menu.h"

Menu :: Menu (Lista *list) {
    this -> list = list;
}

void Menu :: cargarArchivo() {
    string linea, nombre, elemento, vida, escudo;
    ifstream archivo("personaje.csv");

    while(!archivo.fail()){
        while(getline(archivo,linea)){
            stringstream split(linea);
            getline(split,elemento,',');
            getline(split,nombre,',');
            getline(split,escudo,',');
            getline(split,vida);
            crearPersonaje(elemento,nombre,stoi(escudo),stoi(vida));
        }
    }
    archivo.close();
}
string Menu :: verificarNombre() {
    bool noEncontrado = false;
    string nombre;
    while(!noEncontrado){
        nombre = vm.ingresarString(" NOMBRE :");
        list -> buscar(nombre);
        if(!(list -> haySiguiente()))
            noEncontrado = true;
        else
            vm.yaExiste();
    }
    return nombre;
}
string Menu :: verificarElemento() {
    bool encontrado = false;
    string elemento;
    while(!encontrado){
        elemento = vm.ingresarString(" ELEMENTO :");
        if((elemento == "agua")  || (elemento == "tierra")  ||  (elemento == "fuego")  ||  (elemento == "aire") )
            encontrado = true;
        else
            vm.noEncontro(" ELEMENTO ");
    }
    return elemento;
}

void Menu :: cargarNuevoPersonaje(){
  int vida;
  string nombre;
  string elemento;
  int escudo;

  nombre = verificarNombre();
  elemento = verificarElemento();
  vida = (rand() % 91) + 10;
  escudo = rand() % 3;
  crearPersonaje(elemento,nombre,escudo,vida);

}

void Menu :: crearPersonaje(string elemento, string nombre, int escudo, int vida ) {

    Personaje *p;
    if (elemento == "agua") {
        p = new Agua(nombre, escudo, vida);
        list->cargarLista(p);
    } else if (elemento == "tierra") {
        p = new Tierra(nombre, escudo, vida);
        list->cargarLista(p);

    } else if (elemento == "aire") {
        p = new Aire(nombre, escudo, vida);
        list->cargarLista(p);

    } else if (elemento == "fuego") {
        p = new Fuego(nombre, escudo, vida);
        list->cargarLista(p);
    }
}

void Menu :: alimentarPersonaje(string nombre) {

       list -> buscar(nombre);
        if(list -> haySiguiente())
            list -> obtenerActual() -> obtenerDato() -> alimentarse();
        else
            vm.noEncontro("NOMBRE ");
}

void Menu :: bajaPersonaje(string nombre) {
    Nodo * aux = list -> buscar(nombre);

    if (list -> haySiguiente()){
        if(aux -> obtenerDato() -> obtenerNombre() == nombre)
            list -> baja();
        else
            list -> baja(aux);
    }else
       vm.noEncontro("NOMBRE ");
}

void Menu :: mostrarEspecifico(string nombre) {

    list -> buscar(nombre);

    if(list -> haySiguiente())
        list -> obtenerActual() -> obtenerDato() -> mostrarPersonajeEspecifico();
    else
       vm.noEncontro("NOMBRE");
}

void Menu :: funcionCasos( int opcion) {

     vm.limpiarPantalla();

    switch(opcion){
        case 1:
            list -> mostrarPersonaje();
            vm.saltarLinea();
            cargarNuevoPersonaje();
            vm.saltarLinea();
            break;
        case 2:
            list -> mostrarPersonaje();
            vm.saltarLinea();
            bajaPersonaje(vm.ingresarString("NOMBRE "));
            vm.saltarLinea();
            break;
        case 3:
            vm.saltarLinea();
            list -> mostrarPersonaje();
            vm.saltarLinea();
            break;
        case 4:
          list -> mostrarPersonaje();
          vm.saltarLinea();
         mostrarEspecifico(vm.ingresarString("NOMBRE "));
         vm.saltarLinea();
            break;
        case 5:
            list -> mostrarPersonaje();
            vm.saltarLinea();
           alimentarPersonaje(vm.ingresarString("NOMBRE "));
           vm.saltarLinea();
            break;
    }

}
void Menu :: opciones(){

   int opcion ;
   cargarArchivo();

    do{
        vm.menu();
       vm.comprobarOpcion(&opcion);
        funcionCasos( opcion);

    }while(opcion != 6);
}
