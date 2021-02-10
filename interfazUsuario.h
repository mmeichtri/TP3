#ifndef INTERFAZUSUARIO_H_INCLUDED
#define INTERFAZUSUARIO_H_INCLUDED

class interfazUsuario{
private:

public:
    /*
    pre:
    post:
    */
    interfazUsuario();

    /*
    pre:
    post imprime en pantalla el menu inicial del juego
    */
    void menuInicial();

    /*
    pre:
    post: muestra al jugador el menu para elegir sus 3 personajes
    */
    void menuComienzoDeJuego();

    /*
    pre:
    post: primer menu donde el jugador debe indicar que desea que realice su personaje
    */
    void opcionesPrimariasPersonaje();

    /*
    pre:
    post: segundo menu donde el jugador debe indicar que desea que realice su personaje
    */
    void opcionesSecundariasPersonaje();
};

#endif // INTERFAZUSUARIO_H_INCLUDED
