#include <iostream>
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"
#include "interfazUsuario.h"

using namespace std;

InterfazUsuario::InterfazUsuario(){
}

void InterfazUsuario::menu(){
    cout << "Sus opciones son: " << endl;
    cout << "1- Agregar un nuevo personaje" << endl;
    cout << "2- Eliminar un personaje" << endl;
    cout << "3- Mostrar todos los nombres de los personajes" << endl;
    cout << "4- Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "5- Alimentar un personaje" << endl;
    cout << "6- Salir" << endl;
}

int InterfazUsuario::eleccionUsuario(){
    int eleccion;
    cout << "Indique su eleccion: " << endl;
    cin >> eleccion;
    return eleccion;
}

int InterfazUsuario::pedirElementoNuevoPersonaje(){
    int elementoNuevoPersonaje;
    cout << "El personaje puede ser de alguno de los siguientes elementos";
    cout << "\n1-Agua \n2-Fuego \n3-Tierra \n4-Aire \nIndique el numero de su eleccion: " << endl;
    cin >> elementoNuevoPersonaje;
    return elementoNuevoPersonaje;
}

void InterfazUsuario::nuevoPersonaje(Lista* listaPersonajes){
    int elementoNuevoPersonaje = pedirElementoNuevoPersonaje();
    switch(elementoNuevoPersonaje){
        case 1:
            cargarNuevoElementoAgua(listaPersonajes);
            break;
        case 2:
            cargarNuevoElementoFuego(listaPersonajes);
            break;
        case 3:
            cargarNuevoElementoTierra(listaPersonajes);
            break;
        case 4:
            cargarNuevoElementoAire(listaPersonajes);
            break;
        default:
            cout << "El numero ingresado no es valido, intente nuevamente " << endl;
            nuevoPersonaje(listaPersonajes);
    }
}

void InterfazUsuario::cargarNuevoElementoAgua(Lista* listaPersonajes){
    Personaje* personajeNuevo = new Aire(pedirNombreNuevoPersonaje(), pedirEscudoNuevoPersonaje(), pedirVidaNuevoPersonaje());
    listaPersonajes->alta(personajeNuevo, listaPersonajes->obtener_cantidad() + 1);
}

void InterfazUsuario::cargarNuevoElementoFuego(Lista* listaPersonajes){
    Personaje* personajeNuevo = new Aire(pedirNombreNuevoPersonaje(), pedirEscudoNuevoPersonaje(), pedirVidaNuevoPersonaje());
    listaPersonajes->alta(personajeNuevo, listaPersonajes->obtener_cantidad() + 1);
}

void InterfazUsuario::cargarNuevoElementoAire(Lista* listaPersonajes){
    Personaje* personajeNuevo = new Aire(pedirNombreNuevoPersonaje(), pedirEscudoNuevoPersonaje(), pedirVidaNuevoPersonaje());
    listaPersonajes->alta(personajeNuevo, listaPersonajes->obtener_cantidad() + 1);
}

void InterfazUsuario::cargarNuevoElementoTierra(Lista* listaPersonajes){
    Personaje* personajeNuevo = new Tierra(pedirNombreNuevoPersonaje(), pedirEscudoNuevoPersonaje(), pedirVidaNuevoPersonaje());
    listaPersonajes->alta(personajeNuevo, listaPersonajes->obtener_cantidad() + 1);
}

string InterfazUsuario::pedirNombreNuevoPersonaje(){
    string nombre;
    cout << "Indique el nombre del nuevo personaje: " << endl; cin >> nombre;
    return nombre;
}

int InterfazUsuario::pedirVidaNuevoPersonaje(){
    int vida;
    cout << "Indique la cantidad de vidas del personaje (pueden ser entre 10, y 100 inclusives): " << endl; cin >> vida;
    if(vida < 10 || vida > 100){
        throw std::string("La cantidad de vidas, debe estar en el rango [10, 100], inclusives");
    }
    else{
      return vida;
    }
}

int InterfazUsuario::pedirEscudoNuevoPersonaje(){
    int escudo;
    cout << "Indique la opcion numerica, del escudo correspondiente, al nuevo personaje, el mismo puede ser \n1) 0 \n2) 1 \n3) 2" << endl; cin >> escudo;
    if(escudo < 0 || escudo > 2){
        throw std::string("El escudo, puede ser 0, 1 o 2");
    }
    else{
      return escudo;
    }
}

void InterfazUsuario::eliminarPersonaje(Lista* listaPersonajes){
    mostrarNombrePersonajes(listaPersonajes);
    string nombrePersonajeABorrar = solicitarNombrePersonajeABuscar("Ingrese el nombre del personaje a eliminar: ");
    int i = 1;
    listaPersonajes->reiniciar();
    /*cuando avanza, va preguntando si hay siguiente, con lo cual, no hace falta validar si la lista se encuentra vacia,
    o no, ya que, va a recorrer hasta que existe un siguiente*/
    while(listaPersonajes->hay_siguiente()){
        Personaje* personajeActual = listaPersonajes->siguiente();
        if(personajeActual->validarCoincidencia(personajeActual->getNombre(), nombrePersonajeABorrar)){
            listaPersonajes->bajaPorNombre(listaPersonajes, i);
            cout << "\nLuego de eliminar el personaje indicado, la lista queda de la siguiente forma: " << endl;
            mostrarNombrePersonajes(listaPersonajes);
        }
        i++;
    }
}

void InterfazUsuario::mostrarDatosPersonajes(Lista* listaPersonajes){
    int i = 1;
    listaPersonajes->reiniciar();
    while(listaPersonajes->hay_siguiente()){
        Personaje* personajeActual = listaPersonajes->siguiente();
        cout << "\nEl personaje numero " << i << ", es " << personajeActual->getNombre() << ", tiene una cantidad de energia actual de " << personajeActual->mostrarEnergiaActual();
        cout << ", le quedan " << personajeActual->getVida() << " vidas, y su escudo es " << personajeActual->getEscudo() << endl;
    }
     i++;
}

string InterfazUsuario::solicitarElementoNuevoPersonaje(){
    string elemento;
    cout << "Indique de que elemento desea que sea el nuevo personaje, sus opciones son: " << endl;
    cout << "\n1-Agua \n2-Tierra \n3-Aire \n4-Fuego" << endl;
    cin >> elemento;
    return elemento;
}

void InterfazUsuario::mostrarNombrePersonajes(Lista* listaPersonajes){
    int i = 1;
    listaPersonajes->reiniciar();
    while(listaPersonajes->hay_siguiente()){
        Personaje* personajeActual = listaPersonajes->siguiente();
        cout << "El personaje: " << i << ", se llama: " << personajeActual->getNombre() << endl;
        i++;
    }
}

void InterfazUsuario::solicitarPersonajeYmostrarDatos(Lista* listaPersonajes){
    mostrarNombrePersonajes(listaPersonajes);
    string personajeBuscado = solicitarNombrePersonajeABuscar("Ingrese nombre del personaje a buscar: ");
    mostrarDatosPersonajeBuscado(listaPersonajes ,personajeBuscado);
}

void InterfazUsuario::mostrarDatosPersonajeBuscado(Lista* listaPersonajes, string personajeBuscado){
    listaPersonajes->reiniciar();
    while(listaPersonajes->hay_siguiente()){
        Personaje* personajeActual = listaPersonajes->siguiente();
        if(personajeActual->validarCoincidencia(personajeActual->getNombre(), personajeBuscado)){
            cout << "El personaje " << personajeActual->getNombre() << ", tiene " << personajeActual->getVida();
            cout << " vidas, y una energia de "<< personajeActual->mostrarEnergiaActual() << endl;
        }
    }
}

string InterfazUsuario::solicitarNombrePersonajeABuscar(string frase){
    string nombrePersonaje;
    cout << frase << endl;
    cin >> nombrePersonaje;
    return nombrePersonaje;
}

void InterfazUsuario::alimentarPersonaje(Lista* listaPersonajes){
    mostrarNombrePersonajes(listaPersonajes);
    string nombrePersonaje = solicitarNombrePersonajeABuscar("Ingrese el nombre del personaje a alimentar: ");
    listaPersonajes->reiniciar();
    while(listaPersonajes->hay_siguiente()){
        Personaje* personajeActual = listaPersonajes->siguiente();
        if(personajeActual->validarCoincidencia(personajeActual->getNombre(), nombrePersonaje)){
                personajeActual->alimentar(nombrePersonaje);
                mostrarEstadoActual(personajeActual);
        }
    }
}

void InterfazUsuario::mostrarEstadoActual(Personaje* personajeActual){
    cout << "El personaje " << personajeActual->getNombre() << ", ahora tiene una energia de " << personajeActual->mostrarEnergiaActual();
    cout << ", quedandole " << personajeActual->getVida() << " vidas" << endl;
}

void InterfazUsuario::mostrarEstadoFinalPersonajes(Lista* listaPersonajes){
    listaPersonajes->reiniciar();
    while(listaPersonajes->hay_siguiente()){
        Personaje* personajeActual = listaPersonajes->siguiente();
        cout << "El personaje, " << personajeActual->getNombre() << ", finalizo el juego con una energia de: " << personajeActual->mostrarEnergiaActual();
        cout << ", y con " << personajeActual->getVida() << " vidas" << endl;
    }
}
