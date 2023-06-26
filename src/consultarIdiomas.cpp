#include "../include/ControladorUsuario.h"
#include "../include/Fabrica.h"
#include "../include/consultarIdiomas.h"
#include <iostream> 
#include <vector>
#include <unistd.h>

using namespace std;

void consultarIdiomas(){
    cout << endl << "-- Listado de idiomas registrados en el sistema --" << endl << endl;

    Fabrica* fab = Fabrica::getInstancia();
    IControladorUsuario* cu = fab->getInstanciaUsuario();

    vector<string> lista =  cu->listarIdiomaDisp();
    for (size_t i = 0; i < lista.size();++i) {
        cout << i + 1 << ". " << lista[i] << endl;
    }
}