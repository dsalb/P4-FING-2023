#include "../include/ConsultarUsuario.h"
//#include "../include/ControladorUsuario.h"
#include "../include/DTEstudiante.h"
#include "../include/DTFecha.h"
#include "../include/DTProfesor.h"
#include "../include/DTUsuario.h"
#include "../include/Fabrica.h"
#include "../include/Idioma.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

void consultarUsuario() {

    //Titulo
    cout << "------ Consulta Usuario ------" << endl << endl;
    cout << "------ Lista de Usuarios registrados ------" << endl << endl;

    Fabrica* fabe = Fabrica::getInstancia();
    IControladorUsuario* cu = fabe->getInstanciaUsuario();

    map<std::string, DTUsuario*> colUsuario = cu->getcolUsuarios();
    map<std::string, DTUsuario*>::iterator it;
    map<int, string> auxColUsuario;
    string nick;
    int cont = 1; 
    string seleccion;  
    //Lista usuarios
    for(it = colUsuario.begin(); it != colUsuario.end(); it++) {
        cout << cont << ". " << it->first << endl;
        auxColUsuario[cont] = it->first;
        cont++;
    }

    cout << "Por favor, ingrese el usuario que desea consultar: ";
    cin >> seleccion;
    if(cu->existeUsuario(seleccion)){
        DTUsuario *Usuario = colUsuario[seleccion];
        DTEstudiante* dynEst = dynamic_cast<DTEstudiante *>(Usuario);
        DTProfesor* dynProf = dynamic_cast<DTProfesor *>(Usuario);
        cout << endl << "-- Datos --" << endl;
        if (dynEst != NULL) {
            cout << "Nickname: " << dynEst->getNickname() << endl;
            cout << "Nombre: " << dynEst->getNombre() << endl;
            cout << "Fecha de nacimiento: " << dynEst->getFechaNacimiento().getDia() << "/" << dynEst->getFechaNacimiento().getMes() << "/" << dynEst->getFechaNacimiento().getAnio() << endl;
            cout << "Descripcion: " << dynEst->getDesc() << endl;
            cout << "Pais: " << dynEst->getPais() << endl<< endl;
        } else if (dynProf != NULL) {
            cout << "Nickname: " << dynProf->getNickname() << endl;
            cout << "Descripcion: " << dynProf->getDesc() << endl;
            cout << "Instituto: " << dynProf->getInstituto()<< endl;

            vector<DTIdioma*> idiomas = dynProf->getIdiomas();
            vector<DTIdioma*>::iterator iterI;

            cout << "Lista de idiomas:" << endl;
            for(iterI = idiomas.begin(); iterI != idiomas.end(); ++iterI) {
                cout << "  * " << (*iterI)->getNombre() << endl;
            }
            cout << endl;
        } else {
             throw std::invalid_argument("ERROR:: El tipo de usuario no existe");
        }
    
    delete dynEst;
    delete dynProf;
    } else {cout << "ERROR:: El tipo de usuario no existe" << endl;}
}

