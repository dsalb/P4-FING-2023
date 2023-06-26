#include <string>
#include<iostream>
#include  "../include/DTConsultaCurso.h"

#include "../include/TipoDificultad.h"
using namespace std;
DTConsultaCurso::DTConsultaCurso(){}
DTConsultaCurso::DTConsultaCurso(string nombre,string desc, string dif, string nomId,string nomProf,bool hab,vector<DTLeccion> colLec, vector<DTInscripcion> colIns){
    this->nombre = nombre; 
    this->descripcion= desc;
    this->dificultad= dif;
    this->nombreIdioma= nomId;
    this->nombreProfesor= nomProf;
    this->habilitado= hab;
    this->colLeccion= colLec;
    this->colInscripcion= colIns;
}
    string DTConsultaCurso::getNombreCurso() {
        return this->nombre;
}
    string DTConsultaCurso::getDescripcion() {
        return this->descripcion;
        }    
    string DTConsultaCurso::getDificultad() {
        return this->dificultad;
        }
    string DTConsultaCurso::getNombreIdioma() {
        return this->nombreIdioma;
        }    
    string DTConsultaCurso::getNombreProfesor() {
        return this->nombreProfesor;
        } 
    bool DTConsultaCurso::getHabilitado() {
        return this->habilitado;
        }              
    vector<DTLeccion> DTConsultaCurso::getColLecciones(){
        return this->colLeccion;
    }
    vector<DTInscripcion> DTConsultaCurso::getColInscripciones(){
        return this->colInscripcion;
    }
                 
   
DTConsultaCurso::~DTConsultaCurso(){
 
};