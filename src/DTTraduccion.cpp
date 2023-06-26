#include "../include/DTTraduccion.h"

DTTraduccion::DTTraduccion(){}
DTTraduccion::DTTraduccion(string descripcion, string frase, int id, string solucion):DTEjercicio(descripcion, frase, id, "traduccion"){ 
    this->solucion = solucion;
}

DTTraduccion::~DTTraduccion(){}

std::string DTTraduccion::getSolucion(){
    return this->solucion;
}