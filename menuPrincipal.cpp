
#include "menuPrincipal.h"

MenuPrincipal ::MenuPrincipal(Diccionario *diccionario) {
    this -> diccionario = diccionario;
}

void MenuPrincipal ::menu(Grafo* grafo , Matriz* matriz) {

    cargarDiccionario();
    int desicionUsuario;

    do{
        vistaUsuario.menuPrincipal();
        desicionUsuario = vistaUsuario.comprobarOpcion(1,6);

        switch(desicionUsuario){
            case 1:
                agregarPersonaje();
                break;
            case 2:
                eliminarPersonaje();
                break;
            case 3:
                mostrarNombrePersonajes();
                break;
            case 4:
                mostrarPersonajeEspecifico();
                break;
            case 5:
                comenzarJuego(grafo,matriz);
                break;
        }

    }while(desicionUsuario < 6);
}

void MenuPrincipal::cargarDiccionario() {
   ArchivoPersonaje archivo;
   string csv = "personaje.csv";
   archivo.lecturaCsv(diccionario,csv);
}

void MenuPrincipal::comenzarJuego(Grafo* grafo , Matriz* matriz) {
   Juego jugar(grafo,matriz,diccionario);
   jugar.iniciarJuego();
}

void MenuPrincipal :: mostrarNombrePersonajes() {
    diccionario->mostrar();
}

void MenuPrincipal ::mostrarPersonajeEspecifico() {

   vistaUsuario.imprimirLinea(" Estos son los personajes :");
   diccionario->mostrar();
   string nombreSeleccionado = vistaUsuario.ingresarString("nombre");
   Personaje* personajeBuscado = diccionario->buscar(nombreSeleccionado);

   if (personajeBuscado != nullptr)
       personajeBuscado->mostrarPersonaje();
   else
       vistaUsuario.noEncontro("nombre");
}

void MenuPrincipal ::eliminarPersonaje() {

    vistaUsuario.imprimirLinea(" Estos son los personajes :");
    diccionario->mostrar();
    string nombreSeleccionado = vistaUsuario.ingresarString("nombre");

    if (diccionario->buscar(nombreSeleccionado) != nullptr)
        diccionario->borrarPersonaje(nombreSeleccionado);
    else
        vistaUsuario.noEncontro("nombre");

}

string MenuPrincipal::validarNombre() {
    bool nuevoNombre = false;
    string nombre;
    vistaUsuario.imprimirLinea(" Estos son los nombres de los personajes que existen,ingrese uno distinto ");
    diccionario->mostrar();
    do{
        nombre = vistaUsuario.ingresarString("nombre");
        if(diccionario->buscar(nombre) != nullptr)
            nuevoNombre = true;
        else
            vistaUsuario.imprimirLinea(" Ese nombre que ingreso ya existe ");
    }while(!nuevoNombre);

    return nombre;
}

string MenuPrincipal :: validarElemento() {
    bool nuevoElemento = false;
    string elemento;
    vistaUsuario.imprimirLinea(" Elementos validos: agua , tierra , aire , fuego ");
    elemento = vistaUsuario.ingresarString("elemento");

    do{
        if(elemento == "aire" || elemento == "agua" || elemento == "tierra" || elemento == "fuego")
            nuevoElemento = true;
        else
            vistaUsuario.imprimirLinea(" error ingrese un elemento valido ");
    }while(!nuevoElemento);
    return elemento;
}

Personaje* MenuPrincipal ::crearPersonaje() {

    string nombre = validarNombre();
    string elemento = vistaUsuario.ingresarString("elemento");
    int vida = (rand() % 91) + 10;
    int escudo = rand() % 3;
    return crearPersonajeUsuario(elemento,nombre,escudo,vida);

}

void MenuPrincipal ::agregarPersonaje() {
    diccionario->agregar(crearPersonaje());
}

Personaje* MenuPrincipal ::crearPersonajeUsuario(string elemento, string nombre,int escudo, int vida) {
        Personaje *nuevo = NULL;

        if (elemento == "aire")
            nuevo = new Aire(nombre,escudo,vida);
        else if (elemento == "agua")
            nuevo = new Agua(nombre,escudo,vida);
        else if (elemento == "fuego")
            nuevo = new Fuego(nombre,escudo,vida);
        else if (elemento == "tierra")
            nuevo = new Tierra(nombre,escudo,vida);
        else{
            cout << "elemento no válido" << endl;
            return NULL;
        }
        return nuevo;
}

