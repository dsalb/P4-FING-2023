#include "../include/ControladorUsuario.h"
#include "../include/Fabrica.h"
#include "../include/consultaNotificaciones.h"
#include <iostream> 
#include <vector>
#include <unistd.h>

using namespace std;

void consultaNotificaciones() {
    cout << endl << "-- Consulta de Notificaciones --" << endl << endl;

    Fabrica* fab = Fabrica::getInstancia();
    IControladorUsuario* cu = fab->getInstanciaUsuario();
    string nickname;

    cout  << "Ingresar nickname: ";
    cin >> nickname;

    if (cu->existeUsuario(nickname)){

        vector<DTNotificaciones> notificaciones = cu->consultarNotificaciones(nickname);
        if (notificaciones.size() == 0) {
            cout << endl << "No hay notificaciones para mostrar" << endl << endl;
            return;
        }
        vector<DTNotificaciones>::iterator it;
        string curso;
        string idioma;
        cout << endl << "Lista de notificaciones: " << endl << endl;
        int pos = 1;
        for (it = notificaciones.begin(); it != notificaciones.end(); ++it) {
            curso = it->getNombreCurso();
            idioma = it->getNombreIdioma();
            cout << "Notificacion " << pos << ":" << endl;
            cout << curso << endl;
            cout << idioma << endl << endl;
            pos++;
        }

        cout << endl << "Fin de las notificaciones" << endl << endl;
    } else
        cout << "No existe registro en el sistema del nickname " << nickname << endl;
    
}