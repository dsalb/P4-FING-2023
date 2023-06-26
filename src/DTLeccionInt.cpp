#include <string>
#include<iostream>
#include "../include/DTLeccionInt.h"
#include "../include/DTEjercicio.h"
using namespace std;

DTLeccionInt::DTLeccionInt(std::string tema, std::string obj,int indice, vector<DTEjercicio> colEje){
    this->tema = tema;
    this->objetivo = obj;
    this->indice = indice;
    this->colEj=colEje;
}

std::string DTLeccionInt::getTema(){
    return this->tema;
}

int DTLeccionInt::getIndice(){
    return this->indice;
}

std::string DTLeccionInt::getObjetivo(){
    return this->objetivo;
}
vector<DTEjercicio> DTLeccionInt::getDataEjercicio(){
    return this->colEj;
}

DTLeccionInt::~DTLeccionInt(){}
