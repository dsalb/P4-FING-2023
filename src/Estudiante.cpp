#include "../include/Estudiante.h"
#include "../include/Curso.h"

Estudiante::Estudiante(std::string nickname, std::string nombre, std::string pass, std::string desc ,std::string pais, DTFecha fechaNacimiento, vector<Inscripcion*> inscripciones):Usuario(nickname, nombre, pass, desc) {
    this->pais = pais;
    this->fechaNacimiento = fechaNacimiento;
    this->inscripciones = inscripciones;
}

//Getters   
std::string Estudiante::getPais() { 
    return this->pais; 
}

DTFecha Estudiante::getFecha() {
    return this->fechaNacimiento;
}

vector<Inscripcion*> Estudiante::getInscripciones() {
    return this->inscripciones;
}

//Setters
void Estudiante::setPais(std::string pais) {
    this->pais = pais;
}

void Estudiante::setFecha(DTFecha fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}

void Estudiante::setInscripciones(vector<Inscripcion*> inscripciones) {
    this->inscripciones = inscripciones;
}

void Estudiante::agregarInscripcion(Inscripcion* ins){
    this->inscripciones.push_back(ins);
}

//Metodos   
vector<string> Estudiante::getCursos(){
    vector<string> res;
    vector<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); it++) {
            Curso* curso = (*it)->getCurso();
            string nombre = curso->getNombre();
            res.push_back(nombre);
    }
    return res;
}

//devuelve el progreso general de las inscripciones del est????
vector<DTInfoCurso> Estudiante::getInfoProgreso(){
   std::vector<DTInfoCurso> res;
   vector<Inscripcion*>::iterator it;
   for(it = this->inscripciones.begin(); it != this->inscripciones.end(); it++) {
        Inscripcion* actual = *it;
        float av = actual->getAvance();
        res.push_back((*it)->getDataCurso(av));
    }  
    return res;
}
//supongo que devuelve los ejercicios noj aprobados para cada inscripcion separados por curso?
vector<DTEjercicio> Estudiante::darEjerciciosNoAprobados(std::string curso){
    std::vector<DTEjercicio> res;
    vector<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); it++) {
            if((*it)->getCurso()->getNombre() == curso){
                res = ((*it)->ejerciciosNoAprobados());
            }
    }  
    return res;
}

bool Estudiante::VerificarSolT(string res, string curso, int ejer){
    bool resEjer = false;
    vector<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); it++) {
          if((*it)->getCurso()->getNombre() == curso){
                resEjer = (*it)->verificarSolT(res, ejer);
                break;
            }
    }
    return resEjer;
}
bool Estudiante::VerificarSolCP(vector<string> res, string curso, int ejer){
    bool resEjer = false;
    vector<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); it++) {
          if((*it)->getCurso()->getNombre() == curso){
                resEjer = (*it)->verificarSolCP(res, ejer);
                break;
            }
    }
    return resEjer;
}
Estudiante::~Estudiante(){}