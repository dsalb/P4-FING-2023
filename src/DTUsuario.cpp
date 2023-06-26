#include "../include/DTUsuario.h"

DTUsuario::DTUsuario() {}
DTUsuario::DTUsuario(std::string nickname, std::string nombre, std::string pass, std::string desc){
    this->nickname = nickname;
    this->nombre = nombre;
    this->pass = pass;
    this->desc = desc;
}

DTUsuario::~DTUsuario() {}

//getters
std::string DTUsuario::getNickname(){
    return this->nickname;
}
std::string DTUsuario::getNombre(){
    return this->nombre;
}
std::string DTUsuario::getPass(){
    return this->pass;
}
std::string DTUsuario::getDesc(){
    return this->desc;
}