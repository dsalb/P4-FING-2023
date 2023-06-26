#include "../include/Ejercicio.h"

Ejercicio::Ejercicio(string descripcion, string frase, int id) {
    this->descripcion = descripcion;
    this->frase = frase;
    this->id = id;
};

void Ejercicio::setDescripcion(string desc) {
    this->descripcion = desc;
};

void Ejercicio::setFrase(string frase) {
    this->frase = frase;
};

void Ejercicio::setId(int id) {
    this->id = id;
};

string Ejercicio::getDescripcion() {
    return this->descripcion;
};

string Ejercicio::getFrase() {
    return this->frase ;
};

int Ejercicio::getId() {
    return this->id ;
}

DTEjercicio Ejercicio::createDT() {
    string tipoEjercicio;
    return DTEjercicio(this->descripcion, this->frase, this->id, tipoEjercicio);
};

Ejercicio::~Ejercicio() {

};