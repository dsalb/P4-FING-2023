#include "../include/Traduccion.h"

Traduccion::Traduccion(string descripcion, string frase, int id, string solucion):Ejercicio(descripcion, frase, id) {
    this->solucion = solucion;
};

void Traduccion::setSolucion(string solucion) {
    this->solucion = solucion;
};

string Traduccion::getSolucion() {
    return this->solucion;
};

Traduccion::~Traduccion() {

};