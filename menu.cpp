#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>

#include "menu.h"
#include "personajes.h"

#include "lista.h"
#include "cola.h"

#include "agua.h"
#include "aire.h"
#include "fuego.h"
#include "tierra.h"



using namespace std;

Lista l;

void Menu::cargar()
{
    ifstream archivo;
    string linea,nombre,elemento,v,e,c;
    int cant,i=1,vida,escudo;

    archivo.open("info.csv");

    if(!archivo.is_open())
        cout<<"ERROR"<<endl;

        getline(archivo,c,'\n');
        istringstream(c) >> cant;

    while (archivo.good())
    {
        getline(archivo,elemento,',');
        getline(archivo,nombre,',');
        getline(archivo,e,',');
        getline(archivo,v,'\n');

        istringstream(e) >> escudo;
        istringstream(v) >> vida;

        if (elemento=="agua")
        {
            Personajes* personajeNuevo=new Agua(nombre,vida,escudo,cargarEnergia(),0,elemento,"Plancton");
            l.alta(personajeNuevo,i);
            i++;
        }
        else if (elemento=="aire")
        {
            Personajes* personajeNuevo=new Aire(nombre,vida,escudo,cargarEnergia(),elemento);
            l.alta(personajeNuevo,i);
            i++;
        }
        else if (elemento=="fuego")
        {
            Personajes* personajeNuevo=new Fuego(nombre,vida,escudo,cargarEnergia(),elemento,"Madera");
            l.alta(personajeNuevo,i);
            i++;
        }
        else if (elemento=="tierra")
        {
            Personajes* personajeNuevo=new Tierra(nombre,vida,escudo,cargarEnergia(),elemento,"Hierbas");
            l.alta(personajeNuevo,i);
            i++;
        }

    }
    archivo.close();
}

void Menu::imprimir(int i)
{
    cout<<"ELEMENTO: "<<l.consulta(i)->getElemento()<<endl;
    cout<<"NOMBRE: "<<l.consulta(i)->getNombre()<<endl;
    cout<<"VIDA: "<<l.consulta(i)->getVida()<<endl;
    cout<<"ESCUDO: "<<l.consulta(i)->getEscudo()<<endl;
    cout<<"ENERGIA: "<<l.consulta(i)->getEnergia()<<endl;
}

int Menu::encontrarNombre(string n)
{
    int i=1;
    l.reiniciar();
    while (i<=l.obtenerCantidad())
    {
        if (n==l.consulta(i)->getNombre())
            {
            return i;
            }
        i++;
    }
    return -1;
}

void Menu::bajaPersonaje(int i)
{
    l.baja(i);
}

char Menu::eleguirElemento()
{
    char e;
    cout<<"\ningrese el elemento del personaje 'a'(agua),'v'(aire o viento),'f'(fuego) o 't'(tierra):";
    cin>>e;
    return e;
}

void Menu::crearElemento(char e)
{
    int i=1;

    Personajes *personajeNuevo;

    string nom=cargarNombre();
    int vid=cargarVida();
    int esc=cargarEscudo();
    int en=cargarEnergia();


    switch (e)
    {
        case 'a':
            {

            personajeNuevo = new Agua(nom,vid,esc,en,0,"AGUA","Plancton");
            }break;
        case 'v':
            {

            personajeNuevo = new Aire(nom,vid,esc,en,"AIRE");

            }break;
        case 'f':
            {

            personajeNuevo = new Fuego(nom,vid,esc,en,"FUEGO","Madera");
            }break;
        case 't':
            {

            personajeNuevo = new Tierra(nom,vid,esc,en,"TIERRA","Hierbas");
            }break;
        default:
            {
               cout<<"\nopcion no valida intente de nuevo"<<endl;
               e=eleguirElemento();
               crearElemento(e);
            }break;
    }
    l.alta(personajeNuevo,i);
            i++;
}

void Menu::eliminarPersonaje()
{
    cout<<"si quiere eliminar un personaje ";
    string s=cargarNombre();
    int pos=encontrarNombre(s);

    if (pos==-1)
        cout<<"no se encontro el personaje..."<<endl;
    else
        {
        bajaPersonaje(pos);
        cout<<"\nel personaje fue eliminado correctamente seleccione otra opcion"<<endl;
        }
}

void Menu::mostrarNombres()
{
    int i=1;
    l.reiniciar();
    cout<<"\nPersonajes:"<<endl;
    while (i<=l.obtenerCantidad())
    {
        cout<<l.consulta(i)->getNombre()<<endl;
        i++;
    }
    cout<<endl;
}

void Menu::mostrarDatos()
{
    cout<<"\nSi quiere conocer los datos de un personaje";
    string s=cargarNombre();
    int pos=encontrarNombre(s);

        if (pos==-1)
        {
        cout<<"\nno se encontro personaje..."<<endl;
        }
        else

            imprimir(pos);
}

void Menu::alimentar()
{
    cout<<"si desea alimentar";
    int pos=encontrarNombre(cargarNombre());
    l.consulta(pos)->alimentarse();

}

int Menu::cargarEscudo()
{
    srand(time(0));
    return rand() % 3;
}

int Menu::cargarEnergia()
{
    srand(time(0));
    return rand() % 21;
}

int Menu::cargarVida()
{
    srand(time(0));
    return rand() % (101-10) + 10;
}

string Menu::cargarNombre()
{
    string n;
    cout<<"\ningrese el nombre del personaje: ";
    cin>>n;
    return n;
}

void Menu::salir()
{
    cout<<"Adios"<<endl;
}

void Menu::mostrarMenu()
{
    cout<<"\t\tMENU"<<endl;
    cout<<"1-Agregar personaje.\n2-Eliminar personaje.\n3-Mostrar los nombres de todos los personajes.\n4-Buscar detalles de personaje por nombre.\n5-Alimentar a un personaje.\n6-Salir"<<endl;
}

void Menu::elegirOpcion()
{
    cout<<"ingrese la opcion que desea(entre 1 y 6):";
    cin>>opcion;
}


void Menu::agregarPersonaje()
{
    crearElemento(eleguirElemento());
}

void Menu::eleccion()
{
    switch(opcion)
    {
    case 1: //Agregar personaje
        {
            agregarPersonaje();
            cout<<"\nel personaje fue creado correctamete seleccione otra opcion.\n"<<endl;
            mostrarMenu();
            elegirOpcion();
            eleccion();

        }break;
    case 2: //Eliminar personaje
        {
            eliminarPersonaje();
            mostrarMenu();
            elegirOpcion();
            eleccion();

        }break;
    case 3: //Mostrar los nombres de todos los personajes.
        {
            mostrarNombres();
            cout<<"ya se mostraron todos los nombres de los personajes seleccione otra opcion."<<endl;
            mostrarMenu();
            elegirOpcion();
            eleccion();

        }break;
    case 4: //Buscar detalles de personaje por nombre.
        {
            mostrarDatos();
            cout<<"ya se mostraron todos los detalles del personaje seleccione otra opcion."<<endl;
            mostrarMenu();
            elegirOpcion();
            eleccion();

        }break;
    case 5: //alimentar personaje
        {
            alimentar();
            cout<<"el personaje fue alimentado correctamente seleccione otra opcion."<<endl;
            mostrarMenu();
            elegirOpcion();
            eleccion();

        }break;
    case 6: //salir
        {
            salir();
        }break;
    default:
        {
            cout<<"opcion no valida intente de nuevo"<<endl;
            mostrarMenu();
            elegirOpcion();
            eleccion();
        }break;
    }
}
