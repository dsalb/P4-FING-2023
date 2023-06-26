#include "../include/inscribirseCurso.h"
#include "../include/Fabrica.h"
#include <iostream> 

using namespace std;

void imprimirDT(DTInfoCursoExtendido dt){
    cout <<"Nombre: "<< dt.getNombre()<< endl;
    switch (dt.getDificultad())
    {
    case Principiante:
        cout <<"Dificultad: Principiante"<< endl;
        break;
    case Medio:
        cout <<"Dificultad: Medio"<< endl;
        break;
    case Avanzado:
        cout <<"Dificultad: Avanzado"<< endl;
        break;
    default:
        break;
    }
    cout <<"Cantidad de Lecciones: "<< dt.getCantidadLecciones() << endl;
    cout <<"Cantidad de Ejercicios: "<< dt.getCantidadEjercicios() << endl;

    cout<< endl;
    
}

void inscribirseCurso(){
    Fabrica* fabx = Fabrica::getInstancia();
    IControladorCurso* iC = fabx->getInstanciaCurso();
    IControladorUsuario* iU = fabx->getInstanciaUsuario();

    
    vector<string> listaEst = iU->listarEstudiantes();

    cout << "Listado de profesores ingresados en el sistema: " << endl;
    vector<string>::iterator p;
    for (p = listaEst.begin(); p != listaEst.end(); ++p) {
        cout << "  * " <<*p << endl;
    }

    //ingreso del estudiante
    cout << "Por favor ingrese el nickname de un estudiante: ";
    string nicknameEst;
    cin >> nicknameEst;

    //comprobacion
    vector<string>::iterator itS;
    bool condEst = false;
    for(itS = listaEst.begin(); (itS != listaEst.end())&&(!condEst); ++itS)
        condEst = *itS == nicknameEst;
    
    if(condEst){
        vector<DTInfoCursoExtendido> cursosParaInsEst = iC->listarCursosParaInscripcionEstudiante(nicknameEst);

        //listado de cursos que pueden ser habilitados
        cout << "Se listan los cursos a los que se puede inscribir el estudiante "<<nicknameEst<< ":" << endl << endl;
        vector<DTInfoCursoExtendido>::iterator it;
        for(it = cursosParaInsEst.begin(); it != cursosParaInsEst.end(); ++it){
            imprimirDT((*it));
        }

        //se ingresa el curso al cual quiere inscribirse
        cout <<"Por favor ingrese el curso al cual quiere inscribirse: ";
        string cursoIngresado;
        getline(cin >> ws, cursoIngresado);

        //comprobacion
        bool condCurso = false;
        for(it = cursosParaInsEst.begin(); (it != cursosParaInsEst.end())&&(!condCurso); ++it)
            condCurso = (*it).getNombre() == cursoIngresado;
        if(condCurso){
            iC->inscribirseACurso(nicknameEst, cursoIngresado);
        }
        else
            cout <<"El curso que se ingreso es incorrecto."<< endl;
    }
    else
        cout <<"El estudiante que se ingreso es incorrecto."<< endl;


}   