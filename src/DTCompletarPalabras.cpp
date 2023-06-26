#include "../include/DTCompletarPalabras.h"

DTCompletarPalabras::DTCompletarPalabras(){}
DTCompletarPalabras::DTCompletarPalabras(string descripcion, string frase, int id, vector<string> solucion):DTEjercicio(descripcion, frase, id, "cPalabra"){
    this->solucion = solucion;
}
DTCompletarPalabras::~DTCompletarPalabras(){}

 vector<string> DTCompletarPalabras::getSolucion(){
    return this->solucion;
}