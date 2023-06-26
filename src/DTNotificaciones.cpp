#include <string>
#include<iostream>
#include "../include/DTNotificaciones.h"

using namespace std;

DTNotificaciones::DTNotificaciones(string nombreIdioma,string nombreCurso ){
    this->idioma = nombreIdioma; 
    this->curso = nombreCurso;
};
    string DTNotificaciones::getNombreCurso() {
        return this->curso;
}
    string DTNotificaciones::getNombreIdioma() {
        return this->idioma;
        }    
   
DTNotificaciones::~DTNotificaciones(){
 
};