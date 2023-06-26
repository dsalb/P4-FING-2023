#include <string>
#include<iostream>
#include "../include/DTLeccion.h"
#include "../include/DTEjercicio.h"
using namespace std;

DTLeccion::DTLeccion(string tema, string obj,vector<DTEjercicio> colEje){
    this->tema = tema;
    this->objetivo = obj;
    this->colEj=colEje;
}

string DTLeccion::getTema(){
    return this->tema;
}

string DTLeccion::getObjetivo(){
    return this->objetivo;
}
vector<DTEjercicio> DTLeccion::getDataEjercicio(){
    return this->colEj;
}

DTLeccion::~DTLeccion(){}
