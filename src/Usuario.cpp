#include "../include/Usuario.h"
#include "../include/Notificacion.h"
#include "../include/DTNotificaciones.h"

#include <vector>

using namespace std;

Usuario::Usuario(string nickname, string nombre, string pass, string desc){
    this->nickname = nickname;
    this->nombre = nombre;
    this->pass = pass;
    this->desc = desc;
}

// Destructor
Usuario::~Usuario() {}

//Getters  
string Usuario::getNickname(){
    return this->nickname;
}
string Usuario::getNombre(){
    return this->nombre;
}
string Usuario::getPass(){
    return this->pass;
}
string Usuario::getDesc(){
    return this->desc;
}

//Setters
void Usuario::setNickname(string nickname){
    this->nickname = nickname;
}
void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}
void Usuario::setPass(string pass){
    this->pass = pass;
}
void Usuario::setDesc(string desc){
    this->desc = desc;
}

void Usuario::notificar(Notificacion* notificacion) {
    this->notificaciones.push_back(notificacion);
}

vector<DTNotificaciones> Usuario::consultarNotificaciones(){
    vector<Notificacion*>::iterator it;
    vector<DTNotificaciones> notificacionesDT;
    for (it = notificaciones.begin(); it != notificaciones.end(); ++it) {
        DTNotificaciones noti = DTNotificaciones((*it)->getIdioma(), (*it)->getCurso());
        notificacionesDT.push_back(noti);
        (*it)->modificarContador();
    }
    notificaciones.clear();
    return notificacionesDT;
}