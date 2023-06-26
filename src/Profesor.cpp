#include "../include/Profesor.h"

Profesor::Profesor(std::string nickname, std::string nombre, std::string pass, std::string desc, std::string instituto, vector<Idioma*> idiomas,vector<Curso*> cursos):Usuario(nickname, nombre, pass, desc) {
    this->instituto = instituto;
    this->idiomas = idiomas;
    this->cursos = cursos;
}

Profesor::~Profesor() {}

//getters    
std::string Profesor::getInstituto(){
    return this->instituto;
}
vector<Idioma*> Profesor::getIdiomas(){
    return this->idiomas;
}

vector<DTIdioma*> Profesor::getDTIdiomas(){
    vector<Idioma*>::iterator it;
    vector<DTIdioma*> res;
    for(it=this->idiomas.begin(); it!=this->idiomas.end(); it++) {
        DTIdioma* idnew = new DTIdioma((*it)->getNombre());
        res.push_back(idnew);
    }
    return res;
}




vector<Curso*> Profesor::getCursos(){
    return this->cursos;
}

//setters
void Profesor::setInstituto(std::string instituto){
    this->instituto = instituto;
}

void Profesor::setIdiomas(vector<Idioma*> idiomas){
    this->idiomas = idiomas;
}

/*void Profesor::setCursos(vector<Curso*> cursos){
    this->cursos = cursos;
}*/


void Profesor::agregarCurso(Curso* c){
    this->cursos.push_back(c);
}


//metodos
vector<DTInfoCursoGeneral> Profesor::getInfoProgreso(){
    vector<DTInfoCursoGeneral> res;
    for(auto it = this->cursos.begin(); it != this->cursos.end(); it++){
        res.push_back((*it)->getInfoCursoGeneral());
    }

    return res;        
}


void Profesor::quitarCurso(Curso* curso){
    vector<Curso*>::iterator it = find(cursos.begin(), cursos.end(), curso);
    if (it != cursos.end()) {
        cursos.erase(it);
    }
}

void Profesor::AgregarIdioma(vector<Idioma*> idiomas) {
    vector<Idioma*>::iterator iterIdioma;

    for(iterIdioma = idiomas.begin(); iterIdioma != idiomas.end(); iterIdioma++) {
        this->idiomas.push_back(*iterIdioma);
    }
}