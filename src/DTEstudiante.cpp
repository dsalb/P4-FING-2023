#include "../include/DTEstudiante.h"

DTEstudiante::DTEstudiante(){}
DTEstudiante::DTEstudiante(std::string nickname, std::string nombre, std::string pass, std::string desc , std::string pais,DTFecha fechaNacimiento):DTUsuario(nickname, nombre, pass, desc) {
        this->pais = pais;
        this->fechaNacimiento = fechaNacimiento;
}

DTEstudiante::~DTEstudiante(){}

//getters
std::string DTEstudiante::getPais() {
    return this->pais;
}

DTFecha DTEstudiante::getFechaNacimiento() {
    return this->fechaNacimiento;
}