#include "../include/Leccion.h"
#include "../include/DTLeccion.h"
#include "../include/Ejercicio.h"

//CONSTRUCTOR
Leccion::Leccion(string tema, string objetivo, int indice, map<int, Ejercicio *> colEj){
    this->tema = tema;
    this->objetivo = objetivo;
    this->indice = indice;
    this->colEjercicios = colEj;
}

//SETTERS

void Leccion::setTema(string tema){
    this->tema = tema;
}

void Leccion::setObjetivo(string obj){
    this->objetivo = obj;
}


//GETTERS
string Leccion::getTema(){
    return this->tema;
}

string Leccion::getObjetivo(){
    return this->objetivo;
}

int Leccion::getIndice(){
    return this->indice;
}

int Leccion::cantEjercicios(){
    return this->colEjercicios.size();
}

map<int, Ejercicio*> Leccion::getEjercicios(){
    return this->colEjercicios;
}

//OP DCD
DTLeccion Leccion::getDataLeccion(){
    map<int, Ejercicio*>::iterator itE;
    vector<DTEjercicio> colDTEjercicios;
    for(itE = this->colEjercicios.begin(); itE != this->colEjercicios.end(); ++itE)
        colDTEjercicios.push_back(itE->second->createDT());

    return DTLeccion(this->tema, this->objetivo, colDTEjercicios);
}

Ejercicio* Leccion::buscarEjercicio(int idEjer){
    return this->colEjercicios[idEjer];
}

void Leccion::agregarEjerT(string descripcion, string frase, string solucion){
    int tamaño = this->colEjercicios.size();
    Traduccion* nuevoE = new Traduccion(descripcion, frase, tamaño, solucion);
    this->colEjercicios.insert({tamaño, nuevoE});
}

void Leccion::agregarEjerC(string descripcion, string frase, vector<string> solucion){
    int tamaño = this->colEjercicios.size();
    CompletarPalabras* nuevoE = new CompletarPalabras(descripcion, frase, tamaño, solucion);
    this->colEjercicios.insert({tamaño, nuevoE});
}

//DESTRUCTOR
Leccion::~Leccion(){
    if(!(this->colEjercicios.empty())){
        map<int, Ejercicio*>::iterator it;
        for(it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it) {
            if (Traduccion* pT = dynamic_cast<Traduccion*>(it->second)) {
                delete pT;
            }
            else {
                CompletarPalabras* pCP = dynamic_cast<CompletarPalabras*>(it->second);
                delete pCP;

            }
         }
    this->colEjercicios.clear();
}
}
