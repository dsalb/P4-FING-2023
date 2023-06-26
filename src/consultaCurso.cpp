//#include "../include/ControladorCurso.h"
#include "../include/Fabrica.h"
#include "../include/consultaCurso.h"
#include <iostream> 
#include <ostream>
//#include "../include/DTFecha.h"
using namespace std;
Fabrica* fabc = Fabrica::getInstancia();
IControladorCurso* inCurso = fabc->getInstanciaCurso();
void consultaCurso() { 
//Mostrar Cursos
cout << "-- Lista de cursos en el sistema --" << endl;
vector<string> lCurso=inCurso->listarCursos();
vector<string>::iterator it;
for (it=lCurso.begin();it!=lCurso.end();++it){
    cout << "  * " << (*it) << "\n";
}
//Elegir Curso
cout << "Por favor, elija el curso del que quiere recibir información detallada: ";
string selecCurso;
std::getline(std::cin >> std::ws, selecCurso);
//Buscar curso
if(inCurso->existeCurso(selecCurso)){
    DTConsultaCurso cCurso = inCurso->buscarConsultaCurso(selecCurso);
    cout << endl << "-- Informacion del Curso --" << endl << endl;
    cout << "Nombre del Curso: " << (cCurso.getNombreCurso()) << endl;
    cout << "Descripcion del Curso: " << (cCurso.getDescripcion()) << endl;
    cout << "Dificultad del Curso: " << cCurso.getDificultad() << endl;
    cout << "Idioma del Curso: " << (cCurso.getNombreIdioma()) << endl;
    string habilitado;
    if(cCurso.getHabilitado()){
        habilitado ="Si";
    }else{ habilitado ="No";}
    cout << "Profesor del Curso: " << (cCurso.getNombreProfesor()) << endl;
     cout << "Curso habilitado: " << (habilitado) << endl;
    vector<DTLeccion> colLec=cCurso.getColLecciones();
    vector<DTLeccion>::iterator l;
    if(!colLec.empty()){
        cout << endl << "-- Lecciones del Curso --" << endl << endl;
        for (l=colLec.begin();l!=colLec.end();++l){
        cout << "* Tema de la lección: " << l->getTema() << "\n";
        cout << "* Objetivo de la lección: " << l->getObjetivo() << "\n \n";
        vector<DTEjercicio> colEj=l->getDataEjercicio();
        vector<DTEjercicio>::iterator e;
        for (e=colEj.begin();e!=colEj.end();++e){
            if(!colEj.empty()) {
            cout << "Descripción del ejercicio: " << e->getDescripcion() << "\n";
            cout << "Frase del ejercicio: " << e->getFrase() << "\n \n";
            }
        }
    } 
} else {
    cout << "No hay lecciones del Curso " << endl;
}
vector<DTInscripcion> insCurso=cCurso.getColInscripciones();
vector<DTInscripcion>::iterator i;
if(!insCurso.empty()){
    cout << endl << "Inscriptos al Curso: " << endl << endl;
    for (i=insCurso.begin();i!=insCurso.end();++i){
        cout << "  * Nombre del estudiante: " << (i)->getNombreEstudiante() << " // " << "Fecha de inscripción: " << (i)->getFechaIns().getDia()<<"/"<<(i)->getFechaIns().getMes()<<"/"<<(i)->getFechaIns().getAnio() << endl;
    }
} else {
    cout << "No hay inscriptos al Curso " << endl;}
}
}
