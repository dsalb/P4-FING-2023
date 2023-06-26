#include "../include/suscribirseANotificaciones.h"
#include "../include/Fabrica.h"
#include "../include/ControladorUsuario.h"
#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>

void suscribirseANotificaciones() {
    cout << endl << "-- Suscribirse a Notificaciones --" << endl << endl;

    Fabrica* fab = Fabrica::getInstancia();
    IControladorUsuario* cu = fab->getInstanciaUsuario();
    string nickname;

    cout << "Ingresar nickname: ";
    cin >> nickname;

    if (cu->existeUsuario(nickname)) {
        vector<string> listaNoSuscriptos = cu->listarIdiomasNoSuscripto(nickname);
        if (listaNoSuscriptos.size() == 0) {
            cout << "No hay idiomas para suscribirse" << endl;
        } else {
            map<int, string> idiomasIngresados;
            
            int idSelec;
            vector<string> listaIdiomas;
            int continuar = 1;

            while (continuar == 1) {
                int pos = 1;
                cout << endl << "-- Seleccione un idioma para suscribirse --" << endl << endl;
                for (size_t i = 0; i < listaNoSuscriptos.size(); ++i){
                    cout << pos << ". " << listaNoSuscriptos[i] << endl;
                    idiomasIngresados[pos] = listaNoSuscriptos[i];
                    pos++;
                }
                cout << "Ingrese la opción deseada: ";
                cin >> idSelec;
                listaIdiomas.push_back(idiomasIngresados[idSelec]);
                cout << endl << "¿Desea agregar mas idiomas?" << endl;
                cout << "1. Si." << endl;
                cout << "2. No" << endl << endl;
                cout << "Ingrese la opción deseada: ";
                cin >> continuar;
            }

            cu->suscribirseNotificaciones(nickname, listaIdiomas);

            cout << endl << "Suscripción a idiomas exitosa" << endl << endl;
        }
    } else {
        cout << "No existe registro en el sistema del nickname " << nickname << endl;
    }
}