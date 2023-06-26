#include <string>
#include "../include/DTIdioma.h"

using namespace std;

DTIdioma::DTIdioma(){}
DTIdioma::DTIdioma(std::string nombre) {
    this->nombre = nombre;
}

DTIdioma::~DTIdioma(){}

std::string DTIdioma::getNombre() {
    return this->nombre;
}