#include "../include/altaCurso.h"

#include <iostream>
#include <sstream>

void altaCurso() {

    Fabrica* fab = Fabrica::getInstancia();
    IControladorCurso* ICur = fab->getInstanciaCurso();
    IControladorUsuario* IUsu = fab->getInstanciaUsuario();
    
    try {
        cout << "Listado de profesores ingresados en el sistema: " << endl;
        vector<string> listadoP = IUsu->listarProfesores();
        vector<string>::iterator p;
        for (p = listadoP.begin(); p != listadoP.end(); ++p) {
            cout << "  * " <<*p << endl;
        }

        // Selección de profesor
        cout << "Por favor elija el profesor que dictará el curso: ";
        string profesor;
        getline(cin >> ws, profesor);
        IUsu->seleccionarProfesor(profesor);

        // Datos del curso
        cout << "Por ingrese el nombre del curso: ";
        string nombreCurso;
        getline(cin >> ws, nombreCurso);
        cout << "Por ingrese la descripción del curso: ";
        string descCurso;
        getline(cin >> ws, descCurso);
        cout << "Por ingrese la dificulatad del curso (Principiante/Medio/Avanzado): ";
        string difCurso;
        getline(cin >> ws, difCurso);
        TipoDificultad difCursoFix;
        if (difCurso == "Principiante") {
            difCursoFix = Principiante;
        } else if (difCurso == "Medio") {
            difCursoFix = Medio;
        } else {
            difCursoFix = Avanzado;
        }
        ICur->ingresoDatosCurso(nombreCurso, descCurso, difCursoFix);

        // Idioma del curso
        cout << "Listado de idiomas que conoce el docente seleccionado: " << endl;
        vector<string> listadoI = IUsu->listarIdiomasDocente();
        vector<string>::iterator i;
        for (i = listadoI.begin(); i != listadoI.end(); ++i) {
            cout << "  * " << *i << endl;
        }

        // Selección de idioma
        cout << "Por favor elija el idioma en el cual que dictará el curso: ";
        string idioma;
        getline(cin >> ws, idioma);
        IUsu->seleccionarIdioma(idioma);      
        
        
        // Selección de previa
        vector<string> previaCol;
        cout << "¿El curso a crear tendrá previas? (S/N) ";
        string previasPregunta;
        cin >> previasPregunta;
        if (previasPregunta == "S" || previasPregunta == "s") {

            cout << "Por favor elija el curso que será previa del que estamos creando.";
            string previa;
            string flagSalida = "N";

            // Listado de cursos para previa
            cout << "Listado de cursos habilitados en el sistema: " << endl;
            vector<string> listadoPre = ICur->listarCursosHabilitados();
            vector<string>::iterator pre;
            for (pre = listadoPre.begin(); pre != listadoPre.end(); ++pre) {
                cout << "  * " << *pre << endl;
            }

            do {
                cout << "Ingrese el nombre del curso que será previa: ";
                getline(cin >> ws, previa);
                previaCol.push_back(previa);
                cout << "¿Desea agregar otra previa? (S/N) ";
                cin >> flagSalida;

            } while (flagSalida == "S" || flagSalida == "s");
        }

        ICur->seleccionarCursoPrevia(previaCol);

        // Leccion
        cout << "¿Quiere que el curso a crear ya contenga lecciones? (S/N) ";
        string leccionesPregunta;
        cin >> leccionesPregunta;
        ICur->vaciarMemoriaLeccion();
        if (leccionesPregunta == "S" || leccionesPregunta == "s") {
            string flagSalidaLecc;
            do {
                cout << "Por favor ingrese el tema del que tratará la lección: " ;
                string temaLeccion;
                getline(cin >> ws, temaLeccion);

                cout << "Por favor ingrese el objetivo del que tratará la lección: " ;
                string objLeccion;
                getline(cin >> ws, objLeccion);
                ICur->ingresoDatosLeccion(temaLeccion, objLeccion);
                            
                ICur->crearLeccion(false);

                cout << "¿Desea agregar ejercicios a la lección? (S/N) ";
                string ejerciciosPregunta;
                cin >> ejerciciosPregunta;

                if (ejerciciosPregunta == "S" || ejerciciosPregunta == "s") {
                    string salidaEjDo;
                    do {
                        cout << "Por favor ingrese la descripción del ejercicio" ;
                        string descEj;
                        getline(cin >> ws, descEj);

                        cout << "Por favor ingrese la frase del ejercicio" ;
                        string fraseEj;
                        getline(cin >> ws, fraseEj);

                        cout << "Ingrese 1 para ejercicio de traducción o 2 para ejercicio de completar: ";
                        int tipoEjercicio;
                        cin >> tipoEjercicio;
                        if (tipoEjercicio == 1) {
                            cout << "Por favor ingrese la solución del ejercicio: ";
                            string solEj;
                            getline(cin >> ws, solEj);
                            ICur->altaEjercicioTraduccion(false, descEj, fraseEj, solEj);
                        } else {
                            cout << "Por favor ingrese la solución del ejercicio con las palabras separadas por una coma (,): " ;
                            string entrada;
                            getline(cin >> ws, entrada);
                            vector<string> solEj;
                            stringstream ss(entrada);
                            while (ss.good()) {
                                string k;
                                getline(ss,k,',');
                                solEj.push_back(k);
                            }
                            ICur->altaEjercicioCompletar(false, descEj, fraseEj, solEj);
                        }
                        cout << "¿Desea agregar otro ejercicio? (S/N) ";
                        getline(cin >> ws, salidaEjDo);
                    } while (salidaEjDo == "S" || salidaEjDo == "s");
                }
                cout << "¿Desea agregar otra lección? (S/N) ";
                getline(cin >> ws, flagSalidaLecc);
            } while (flagSalidaLecc == "S" || flagSalidaLecc == "s");
        } 
        ICur->altaCurso();
        
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }
    
}