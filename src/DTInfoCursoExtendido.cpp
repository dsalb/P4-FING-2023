#include "../include/DTInfoCursoExtendido.h"

DTInfoCursoExtendido::DTInfoCursoExtendido(string nombre, TipoDificultad dif, int cantLec, int cantEj){
    this->nombre = nombre;
    this->dif = dif;
    this->cantDeLecciones = cantLec;
    this->cantDeEjercicios = cantEj;
}

string DTInfoCursoExtendido::getNombre(){
    return this->nombre;
}

TipoDificultad DTInfoCursoExtendido::getDificultad(){
    return this->dif;
}

int DTInfoCursoExtendido::getCantidadLecciones()
{
    return this->cantDeLecciones;
}

int DTInfoCursoExtendido::getCantidadEjercicios()
{
    return this->cantDeEjercicios;
}

DTInfoCursoExtendido::~DTInfoCursoExtendido(){}