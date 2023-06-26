#include "../include/consultarEstadisticas.h"
#include "../include/Fabrica.h"

#include <iostream>

using namespace std;

void consultarEstadisticas() {

    Fabrica* fab = Fabrica::getInstancia();
    IControladorCurso* ICur = fab->getInstanciaCurso();
    IControladorUsuario* IUsu = fab->getInstanciaUsuario();


    try {
        int usrOp;
        cout << "Por favor indique que tipo de estadísticas quiere consultar: \n 1 - Estudiantes \n 2 - Profesores \n 3 - Cursos \n \n Ingrese su opción: ";
        cin >> usrOp;

        if (usrOp == 1) {
            // Listado de estudiantes
            cout << "Listado de estudiantes ingresados en el sistema: " << endl;
            vector<string> listado = IUsu->listarEstudiantes();
            vector<string>::iterator it;
            for (it = listado.begin(); it != listado.end(); ++it) {
                cout << *it << endl;
            }

            // Selección de estudiente
            cout << "Por favor elija el estudiante del cual quiere obtener las estadísticas: ";
            string estudiante;
            getline(cin >> ws, estudiante);

            if (!IUsu->existeUsuario(estudiante)) {
                cout << "El dato ingresado no tiene registros en el sistema" << endl;
                return;
            }
            
            // Salida
            vector<DTInfoCurso> res = IUsu->consultarEstadisticasEstudiante(estudiante);
            vector<DTInfoCurso>::iterator k;
            if (res.size() == 0) {
                cout << endl << "El estudiante no está inscripto a ningún curso" << endl;
            } else {
                for (k = res.begin(); k != res.end(); ++k) {
                    DTInfoCurso actual = *k;
                    string dif;
                    if (actual.getDificultad() == 0) {
                        dif = "Principiante";
                    } else if (actual.getDificultad() == 1) {
                        dif = "Medio";
                    } else {
                        dif = "Avanzado";
                    }
                    cout << endl;
                    cout << "Nombre del curso: " << actual.getNombreCurso() << endl;
                    cout << "Dificultad del curso: " << dif << endl;
                    cout << "Progreso en el curso: " << actual.getAvance() << endl << endl;
                }
            }
        } else if (usrOp == 2) {
            // Listado de profesores
            cout << "Listado de profesores ingresados en el sistema: " << endl;
            vector<string> listadoP = IUsu->listarProfesores();
            vector<string>::iterator p;
            for (p = listadoP.begin(); p != listadoP.end(); ++p) {
                cout << *p << endl;
            }

            // Selección de profesor
            cout << "Por favor elija el profesor del cual quiere obtener las estadísticas: ";
            string profesor;
            getline(cin >> ws, profesor);

            if (!IUsu->existeUsuario(profesor)) {
                cout << "El dato ingresado no tiene registros en el sistema" << endl;
                return;
            }
            
            // Salida
            vector<DTInfoCursoGeneral> resP = IUsu->consultarEstadisticasCursoOProfesor("profesor", profesor);
            vector<DTInfoCursoGeneral>::iterator m;
            if (resP.size() == 0) {
                cout << endl << "El profesor no ha creado cursos" << endl;
            } else {
                for (m = resP.begin(); m != resP.end(); ++m) {
                    DTInfoCursoGeneral actual = *m;
                    string dif;
                    if (actual.getDificultad() == 0) {
                        dif = "Principiante";
                    } else if (actual.getDificultad() == 1) {
                        dif = "Medio";
                    } else {
                        dif = "Avanzado";
                    }
                    cout << endl;
                    cout << "Nombre del curso: " << actual.getNombreCurso() << endl;
                    cout << "Dificultad del curso: " << dif << endl;
                    cout << "Progreso promedio de inscriptos al curso: " << actual.getAvanceProm() << endl << endl;
                }
            }
              
        } else if (usrOp == 3) {
            // Listado de Cursos
            cout << "Listado de cursos ingresados en el sistema: " << endl;
            vector<string> listadoC = ICur->listarCursos();
            vector<string>::iterator c;
            for (c = listadoC.begin(); c != listadoC.end(); ++c) {
                cout << *c << endl;
            }

            // Selección de curso
            cout << "Por favor elija el curso del cual quiere obtener las estadísticas: ";
            string curso;
            getline(cin >> ws, curso);

            if (!ICur->existeCurso(curso)) {
                cout << "El dato ingresado no tiene registros en el sistema" << endl;
                return;
            }
            
            // Salida
            vector<DTInfoCursoGeneral> resC = IUsu->consultarEstadisticasCursoOProfesor("curso", curso);
            vector<DTInfoCursoGeneral>::iterator x;
            for (x = resC.begin(); x != resC.end(); ++x) {
                DTInfoCursoGeneral actual = *x;
                string dif;
                if (actual.getDificultad() == 0) {
                    dif = "Principiante";
                } else if (actual.getDificultad() == 1) {
                    dif = "Medio";
                } else {
                    dif = "Avanzado";
                }
                cout << endl;
                cout << "Nombre del curso: " << actual.getNombreCurso() << endl;
                cout << "Dificultad del curso: " << dif << endl;
                cout << "Progreso promedio de inscriptos al curso: " << actual.getAvanceProm() << endl << endl;
            } 
        } else {
                cout << "No ha seleccionado una opción válida" << endl;  
        }

    } catch(const exception& e) {
        cerr << e.what() << '\n';
    }
}