
#include "menuPrincipal.h"

MenuPrincipal ::MenuPrincipal(Diccionario *diccionario) {
    this->_diccionario = diccionario;
}

void MenuPrincipal ::menu(Grafo* grafo , Matriz* matriz) {

    cargarDiccionario();
    int decisionUsuario;

    do{
        vistaUsuario.menuPrincipal();
        decisionUsuario = vistaUsuario.comprobarOpcion(1, 6, MENU);

        switch(decisionUsuario){
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
                return;
        }

    }while(decisionUsuario < 6);
}

void MenuPrincipal::cargarDiccionario() {
   ArchivoPersonaje archivo;
   string csv = "personaje.csv";
   archivo.lecturaCsv(_diccionario,csv);
}

void MenuPrincipal::comenzarJuego(Grafo* grafo , Matriz* matriz) {
   Juego *j = new Juego(grafo, matriz, _diccionario);
   Personaje **primerTurno;
   Personaje **segundoTurno;
   j->iniciarJuego(primerTurno, segundoTurno);
   j->jugar(primerTurno, segundoTurno);
   delete j;
   _diccionario = NULL;
}

void MenuPrincipal :: mostrarNombrePersonajes() {
    _diccionario->mostrar();
}

void MenuPrincipal ::mostrarPersonajeEspecifico() {

   vistaUsuario.imprimirLinea(" Estos son los personajes :");
   _diccionario->mostrar();
   string nombreSeleccionado = vistaUsuario.ingresarString("nombre");
   Personaje* personajeBuscado = _diccionario->buscar(nombreSeleccionado);

   if (personajeBuscado != nullptr)
       personajeBuscado->mostrarPersonaje(0);
   else
       vistaUsuario.noEncontro("nombre");
}

void MenuPrincipal ::eliminarPersonaje() {

    vistaUsuario.imprimirLinea(" Estos son los personajes :");
    _diccionario->mostrar();
    string nombreSeleccionado = vistaUsuario.ingresarString("nombre");

    if (_diccionario->buscar(nombreSeleccionado) != nullptr)
        _diccionario->borrarPersonaje(nombreSeleccionado);
    else
        vistaUsuario.noEncontro("nombre");

}

string MenuPrincipal::validarNombre() {
    bool nuevoNombre = false;
    string nombre;
    vistaUsuario.imprimirLinea(" Estos son los nombres de los personajes que existen,ingrese uno distinto ");
    _diccionario->mostrar();
    do{
        nombre = vistaUsuario.ingresarString("nombre");
        if(!_diccionario->incluye(nombre))
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
    _diccionario->agregar(crearPersonaje());
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

