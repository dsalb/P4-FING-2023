#include "../include/eliminarCurso.h"
#include "../include/Fabrica.h"
#include <iostream> 

using namespace std;

void eliminarCurso(){
    Fabrica* fab = Fabrica::getInstancia();
    IControladorCurso* iC = fab->getInstanciaCurso();

    //listado de cursos
    vector<string> colCursos = iC->listarCursos();
    vector<string>::iterator itS;
    cout << "Se listan los cursos del sistema." << endl;
    for(itS = colCursos.begin(); itS != colCursos.end(); ++itS)
        cout << *itS << endl;

    //Seleccion del curso
    cout <<"Por favor ingrese el curso que desea eliminar: ";
    string cursoIngresado;
    getline(cin >> ws, cursoIngresado);

    //comprobacion
    bool condCurso = false;
    for(itS = colCursos.begin(); (itS != colCursos.end())&&(!condCurso); ++itS)
        condCurso = (*itS) == cursoIngresado;

    
    if(condCurso){
        iC->eliminarCurso(cursoIngresado);
        cout << "Se ha eliminado correctamente." << endl;
    }
    else
        cout << "El curso ingresado es incorrecto." << endl;
}