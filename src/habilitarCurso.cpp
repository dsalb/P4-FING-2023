#include "../include/altaIdioma.h"
#include "../include/Fabrica.h"
#include <iostream> 

using namespace std;

void habilitarCurso(){
    Fabrica* fabz = Fabrica::getInstancia();
    IControladorCurso* iC = fabz->getInstanciaCurso();

    vector<string> cursosDispParaHab = iC->listarCursosDisponiblesParaHabilitar();
    vector<string>::iterator itS;

    if (cursosDispParaHab.size() == 0) {
        cout << "No hay cursos en el sistema en condiciones de ser habilitados" << endl;
        return;
    }
    
    //listado de cursos que pueden ser habilitados
    cout << "Se listan los cursos disponibles para habilitar: " << endl;
    for(itS = cursosDispParaHab.begin(); itS != cursosDispParaHab.end(); ++itS)
        cout << "  * " << *itS << endl;

    //Seleccion curso
    cout << "Por favor ingrese el curso que quiere habilitar: ";
    string curso;
    getline(cin >> ws, curso); 

    //comprobacion de dato ingresado
    bool cond = false;
    for(itS = cursosDispParaHab.begin(); (itS != cursosDispParaHab.end())&&(!cond); ++itS)
        cond = *itS == curso;
    
    //habilitacion
    if(cond)
        iC->habilitarCurso(curso);
    else
        cout << "El curso que se ingreso es incorrecto." << endl;

}