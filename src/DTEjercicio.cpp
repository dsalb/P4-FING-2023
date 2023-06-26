#include "../include/DTEjercicio.h"

DTEjercicio::DTEjercicio(){}
DTEjercicio::DTEjercicio(string descripcion, string frase, int id, string tipoEjercicio) {

    this->descripcion = descripcion;
    this->frase = frase;
    this->id = id;
    this->tipoE=tipoEjercicio;
};

string DTEjercicio::getDescripcion() {
    return this->descripcion;
};

string DTEjercicio::getFrase() {
    return this->frase;
};

int DTEjercicio::getId() {
    return this->id;
};
string DTEjercicio::getTipoEjercicio() {
    return this->tipoE;
};

DTEjercicio::~DTEjercicio() {

};