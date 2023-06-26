#include "../include/CompletarPalabras.h"

CompletarPalabras::CompletarPalabras(string descripcion, string frase, int id, vector<string> solucion):Ejercicio(descripcion, frase, id) {
    this->solucion = solucion;
};

void CompletarPalabras::setSolucion(vector<string> solucion) {
    this->solucion = solucion;
};

vector<string> CompletarPalabras::getSolucion() {
    return this->solucion;
};

CompletarPalabras::~CompletarPalabras() {

};