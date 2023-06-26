#include <string>
#include<iostream>
#include  "../include/DTInfoCursoGeneral.h"
#include "../include/TipoDificultad.h"
using namespace std;

DTInfoCursoGeneral::DTInfoCursoGeneral(string nombreCurso,float avPromedio,TipoDificultad dif ){
    this->nombre = nombreCurso; 
    this->avanceProm= avPromedio;
    this->dificultad= dif;
};
    string DTInfoCursoGeneral::getNombreCurso() {
        return this->nombre;
}
    
    float DTInfoCursoGeneral::getAvanceProm() {
        return this->avanceProm;
        }    
    TipoDificultad DTInfoCursoGeneral::getDificultad() {
        return this->dificultad;
        }        
   
DTInfoCursoGeneral::~DTInfoCursoGeneral(){
 
};