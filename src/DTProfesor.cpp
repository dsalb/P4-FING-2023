#include "../include/DTProfesor.h"

DTProfesor::DTProfesor(){}
DTProfesor::DTProfesor(std::string nickname, std::string nombre,std::string pass, std::string desc,  std::string instituto,vector<DTIdioma*> idiomas):DTUsuario(nickname, nombre, pass, desc){
    this->instituto = instituto;
    this->idiomas = idiomas;

}

DTProfesor::~DTProfesor(){}

//getters
std::string DTProfesor::getInstituto(){
    return this->instituto;
}

vector<DTIdioma*> DTProfesor::getIdiomas(){
    return this->idiomas;
}