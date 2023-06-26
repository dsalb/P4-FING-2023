#include "../include/eliminarSuscripciones.h"
#include "../include/Fabrica.h"
#include "../include/ControladorUsuario.h"
#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>

using namespace std;

void eliminarSuscripciones() {
    cout << endl << "-- Eliminar Suscripciones --" << endl << endl;

    Fabrica* fab = Fabrica::getInstancia();
    IControladorUsuario* cu = fab->getInstanciaUsuario();
    string nickname;

    cout << "Ingresar nickname :";
    cin >> nickname;

    if (cu->existeUsuario(nickname)) {    
        vector<string> listaSuscriptos = cu->listarIdiomasSuscripto(nickname);
        if (listaSuscriptos.size() == 0)
            cout << "No hay suscripciones disponibles para eliminar" << endl << endl;
        else {
            map<int, string> idiomasIngresados;

            int idSelec;
            vector<string> listaIdiomas;
            int continuar = 1;

            while (continuar == 1) {
                int pos = 1;
                cout << endl << "Seleccione un idioma para eliminar" << endl << endl;
                for (size_t i = 0; i < listaSuscriptos.size(); ++i){
                    cout << pos << ". " << listaSuscriptos[i] << endl;
                    idiomasIngresados[pos] = listaSuscriptos[i];
                    pos++;
                }
                cout << "Ingrese la opción deseada: ";
                cin >> idSelec;
                listaIdiomas.push_back(idiomasIngresados[idSelec]);
                cout << endl << "¿Desea eliminar suscripcion de mas idiomas?" << endl << endl;
                cout << "1. Si." << endl;
                cout << "2. No" << endl << endl;
                cout << "Ingrese la opción deseada: ";
                cin >> continuar;
            }

            cu->eliminarSuscripcion(nickname, listaIdiomas);

            cout << "Eliminacion a suscripcion de idiomas exitosa" << endl;
        }
    } else
        cout << "No existe registro en el sistema del nickname " << nickname << endl;
}