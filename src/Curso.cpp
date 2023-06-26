#include "../include/Curso.h"
#include "../include/Estudiante.h"
#include "../include/DTConsultaCurso.h"
#include "../include/Profesor.h"
#include <vector>
#include <algorithm>

using namespace std;
//CONSTRUCTOR
Curso::Curso(string nombre,string desc, TipoDificultad dif,bool hab, Profesor* profe, vector<Inscripcion*> colI, map<int, Leccion *> colL, vector<Curso*> previas, Idioma *idioma){
    this->nombre = nombre;
    this->desc = desc;
    this->dificultad = dif;
    this->profesor = profe;
    this->colInscripciones = colI;
    this->colLecciones = colL;
    this->previas = previas;
    this->habilitado = hab;
    this->idiomaCurso = idioma;

}
//SETTERS
void Curso::setNombre(string nombre){
    this->nombre = nombre;
}

void Curso::setDificultad(TipoDificultad nivel){
    this->dificultad = nivel;
}

void Curso::habilitarCurso(){
    this->habilitado = true;
}

void Curso::agregarInscripcion(Inscripcion* ins){
    this->colInscripciones.push_back(ins);
}

void Curso::agregarLeccion(string tema, string objetivo, map<int, Ejercicio*> colEj){
    Leccion* nuevaL = new Leccion(tema, objetivo, this->colLecciones.size(), colEj);
    this->colLecciones[this->colLecciones.size()] = nuevaL;

}

void Curso::agregarPrevia(Curso* previa){
    this->previas.push_back(previa);
}

void Curso::setIdioma(Idioma* idioma){
    this->idiomaCurso = idioma;
}

/*DTConsultaCurso Curso::getDTConsultaCurso(){
    map<int, Leccion*>::iterator iL;
    vector<DTLeccion> colDTLec;
    for(iL = this->colLecciones.begin(); iL != this->colLecciones.end(); ++iL){
        colDTLec.push_back(iL->second->getDataLeccion());
        }
        vector<Inscripcion*>::iterator iIns;
        vector<DTInscripcion> colDTIns;
        for(iIns = this->colInscripciones.begin(); iIns != this->colInscripciones.end(); ++iIns){
            colDTIns.push_back((*iIns)->getDTInscripcion());
        } 
    
    return DTConsultaCurso(this->nombre, this->desc, this->dificultad, this->idiomaCurso->getNombre(), this->profesor->getNombre(), this->habilitado, colDTLec, colDTIns);
}*/
//GETTERS
string Curso::getNombre(){
    return this->nombre;
}
string Curso::getDescripcion(){
    return this->desc;
}
TipoDificultad Curso::getDificultad(){
    return this->dificultad;
}

vector<Inscripcion*> Curso::getInscripciones(){
    return this->colInscripciones;
}

map<int, Leccion*> Curso::getLecciones(){
    return this->colLecciones;
}


vector<Curso*> Curso::getPrevias(){
    return this->previas;
}

/*Devolver el puntero o solo el nombre del idioma?? Que es mas correcto?*/
Idioma* Curso::getIdioma(){
    return this->idiomaCurso;
}
Profesor* Curso::getProfesor(){
    return this->profesor;
}

//OP. DCD
DTInfoCursoGeneral Curso::getInfoCursoGeneral(){
    vector<Inscripcion*>::iterator it;
    float prom = 0;
    float acum = 0;
    int tamaño = this->colInscripciones.size();
    if(tamaño != 0){
        for(it = this->colInscripciones.begin(); it != this->colInscripciones.end(); ++it)
            acum = acum + (*it)->getAvance();
        prom = acum/tamaño;
    }

    DTInfoCursoGeneral miDT = DTInfoCursoGeneral(this->nombre, prom, this->dificultad);
    return miDT;
}

int Curso::getCantidadEj(){
    map<int, Leccion*>::iterator it;
    int cantEjer = 0;
    for(it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it)
        cantEjer = cantEjer + it->second->cantEjercicios();
    return cantEjer;
}

int Curso::getCantidadLec(){
    return this->colLecciones.size();
}

bool Curso::estaHabilitado(){return this->habilitado;}//seria igual a getHabilitado

Ejercicio* Curso::buscarEjercicioEnLec(int indiceEj,int indiceLec){
    return this->colLecciones[indiceLec]->buscarEjercicio(indiceEj);
}

map<int, Ejercicio*> Curso::darEjerciciosLec(int indiceLec){
    return this->colLecciones[indiceLec]->getEjercicios();
}

void Curso::eliminarInscripciones(){
    vector<Inscripcion*>::iterator itInsCurso;
    for(itInsCurso = this->colInscripciones.begin(); itInsCurso != this->colInscripciones.end(); ++itInsCurso){
        vector<Inscripcion*> colInsEstudiante = (*itInsCurso)->getEstudiante()->getInscripciones();
        vector<Inscripcion*>::iterator itInsEst;
        vector<Inscripcion*> colInsEstudianteNueva;
        for(itInsEst = colInsEstudiante.begin(); itInsEst != colInsEstudiante.end(); ++itInsEst){
            if((*itInsCurso)!=(*itInsEst))
                colInsEstudianteNueva.push_back(*itInsEst);
        }
        (*itInsCurso)->getEstudiante()->setInscripciones(colInsEstudianteNueva);
        colInsEstudiante.clear();
    }
}

void Curso::eliminarPrevia(Curso* prev) {
    vector<Curso*>::iterator it = find(previas.begin(), previas.end(), prev);
    if (it != previas.end()) {
        previas.erase(it);
    }
}

bool Curso::esPrevia(Curso* curso) {
    vector<Curso*>::iterator it = find(previas.begin(), previas.end(), curso);
    return (it != previas.end());
}

//DESTRUCTOR
Curso::~Curso(){

    if(!(this->colLecciones.empty())){
        this->colLecciones.clear();
    }

    //quito el curso de la coleccion de cursos del profe

    //Profesor* profe = this->profesor;
    //profe->quitarCurso(this->nombre);
    

    this->colLecciones.clear();
}

