#include <string>
#include<iostream>
#include  "../include/DTInfoCurso.h"
#include "../include/TipoDificultad.h"
using namespace std;

DTInfoCurso::DTInfoCurso(string nombreCurso,float avanceCurso,TipoDificultad dif ){
    this->nombre = nombreCurso; 
    this->avance= avanceCurso;
    this->dificultad= dif;
};
    string DTInfoCurso::getNombreCurso() {
        return this->nombre;
}
    float DTInfoCurso::getAvance() {
        return this->avance;
        }    
    TipoDificultad DTInfoCurso::getDificultad() {
        return this->dificultad;
        }   
             
   
DTInfoCurso::~DTInfoCurso(){
 
};
