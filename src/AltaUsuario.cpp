#include "../include/AltaUsuario.h"
#include "../include/ControladorUsuario.h"
#include "../include/DTUsuario.h"
#include "../include/DTEstudiante.h"
#include "../include/DTProfesor.h"
#include "../include/DTFecha.h"
#include "../include/Fabrica.h"

#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>

void altaUsuario() {
    //Titulo
    cout << "------ Nuevo Usuario ------" << endl << endl;

    Fabrica* fab = Fabrica::getInstancia();
    IControladorUsuario* cu = fab->getInstanciaUsuario();

    string nickname;
    string nombre;
    string pass;
    string desc;

    cout << "Por favor, ingrese a continuación el nickname del nuevo usuario: ";
    getline(cin >> ws, nickname);

    if(!cu->existeUsuario(nickname)){

    cout << "Por favor, ingrese a continuación el nombre del nuevo usuario: ";
    getline(cin >> ws, nombre);

    cout << "Por favor, ingrese a continuación la contraseña del nuevo usuario: ";
    cin >> pass;
    while (pass.length() < 6) {
        cout << endl << "ERROR: La contraseña debe tener al menos 6 caracteres" << endl << endl;
        cout << "Ingrese nuevamente una contraseña: ";
        cin >> pass;
    }

        cout << "Por favor, ingrese a continuación la descripción del nuevo usuario: ";
        getline(cin >> ws, desc);

        int seleccion;
        cout << endl << "Seleccione el tipo de usuario:" << endl;
        cout << "1. Estudiante." << endl;
        cout << "2. Profesor." << endl;
        cout << "Ingrese la opción deseada: ";

        while (true) {
            if (cin >> seleccion) {
                if (seleccion == 1 || seleccion == 2) {
                    break;
                } else {
                    cout << endl << "Por favor, ingrese una opción aceptable." << endl;
                }
            } else {
                cout << endl << "Por favor, ingrese un número." << endl;
                cin.clear();
                cin.ignore();
            }
        }
        DTUsuario* res;

        if (seleccion == 1) {
            string pais;
            int dia;
            int mes;
            int anio;

            cout << "Por favor, ingrese a continuación el pais del nuevo estudiante: ";
            cin >> pais;

            cout << endl << "A continuacion ingrese la fecha de nacimiento dato por dato:" << endl << endl;

            cout << "Por favor, ingrese el dia: ";
            cin >> dia;
            cout << "Por favor, ingrese el mes: ";
            cin >> mes;
            cout << "Por favor, ingrese el año: ";
            cin >> anio;

            DTFecha fechaNacimiento = DTFecha(dia, mes, anio, 0, 0);
            DTEstudiante* resEst = new DTEstudiante(nickname, nombre, pass, desc , pais,fechaNacimiento);   
            res = resEst;

    
    }else if (seleccion == 2) {
            string instituto;
            vector<DTIdioma*> idiomas;
            vector<Curso*> cursos;

            cout << "Por favor, ingrese a continuación el instituto del nuevo profesor: ";
            cin >> instituto;

            std::vector<string> idiomasDispo = cu->listarIdiomaDisp();
            std::vector<string>::iterator iterIdi;
            map<int, string> AuxcolIdiomas;
            int pos = 1;
            cout << "A continuacion se listan los idiomas disponibles:" << endl;
            for(iterIdi = idiomasDispo.begin(); iterIdi != idiomasDispo.end(); ++iterIdi){
                cout << pos << "." << " " << *iterIdi << "." << endl;
                AuxcolIdiomas[pos] = *iterIdi;
                pos++;
            }
            int selIdi;

            cout << "Por favor, seleccione la opción nemérica del idioma a ingresar: ";
            cin >> selIdi;
            string idiomastr = AuxcolIdiomas[selIdi];
            DTIdioma* IdiomaSel = new DTIdioma(idiomastr);
            
            idiomas.push_back(IdiomaSel);
            
            int continuo;
            cout << endl << "Desea agregar mas idiomas?" << endl;
            cout << "1. Si." << endl;
            cout << "2. No." << endl;
            cout << "Ingrese la opción deseada: ";

            while (true) {
                if (cin >> continuo) {
                    if (continuo == 1 || continuo == 2) {
                        break;
                    } else {
                        cout << endl << "Por favor, ingrese una opción aceptable." << endl;
                    }
                } else {
                    cout << endl << "Por favor, ingrese un número." << endl;
                    cin.clear();
                    cin.ignore();
                }
            }

            if (continuo == 1) {
                while (continuo == 1) {
                    cout << "Por favor, seleccione un idioma: ";
                    cin >> selIdi;
                    string idiomastr = AuxcolIdiomas[selIdi];
                    DTIdioma* IdiomaSel = new DTIdioma(idiomastr);
                    idiomas.push_back(IdiomaSel);
                    cout << endl << "Desa agregar mas idiomas?" << endl;
                    cout << "1. Si." << endl;
                    cout << "2. No." << endl;
                    cout << "Ingrese la opción deseada: ";
                    cin >> continuo;
                }
            }
            DTProfesor* prof = new DTProfesor(nickname, nombre, pass, desc, instituto, idiomas);
            res = prof;
    }
        else{
            throw invalid_argument("ERROR_CDU1: Opción ingresada no válida.");
        }

        cout << endl << "Desea confirmar el nuevo usuario?" << endl;
        cout << "1. Si." << endl;
        cout << "2. No." << endl;
        cout << "Ingrese la opción deseada: ";

        while (true) {
            if (cin >> seleccion) {
                if (seleccion == 1 || seleccion == 2) {
                    break;
                } else {
                    cout << endl << "Por favor, ingrese una opción aceptable." << endl;
                }
            } else {
                cout << endl << "Por favor, ingrese un número." << endl;
                cin.clear();
                cin.ignore();
            }
        }

        if (seleccion == 1) {
            try {
                cu->confirmarAltaUsuario(res);
                cout << endl << "Usuario confirmado." << endl;
                return;
            } 
            catch (exception &e) {
                throw std::invalid_argument(e.what());
            }
        } else if (seleccion == 2) {
            delete res;
            cout << endl << "Operación cancelada con éxito." << endl;
            return;
        } else {
                throw invalid_argument("ERROR_CDU2: Opción ingresada no válida.");
            }
    } cout << "Usuario ya existente" << endl;    
}
