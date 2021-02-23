
#include "menuPrincipal.h"

void MenuPrincipal ::menu() {
    int desicionUsuario;
    vistaUsuario.menuPrincipal();
    do{
        desicionUsuario = vistaUsuario.comprobarOpcion(1,6);

        switch(desicionUsuario){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }

    }while(desicionUsuario < 6);
}
void MenuPrincipal::comenzarJuego() {

}