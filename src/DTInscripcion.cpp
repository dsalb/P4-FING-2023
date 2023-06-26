#include "../include/DTInscripcion.h"

DTInscripcion::DTInscripcion(string nombreEst, DTFecha fIns,bool ap, string nick){
this->nombreEstudiante = nombreEst;
this->fechaIns = fIns;
this->aprobado=ap;
this->nick = nick;
}


string DTInscripcion::getNickEstudiante(){
return this->nick;
}

string DTInscripcion::getNombreEstudiante(){
return this->nombreEstudiante;
}

DTFecha DTInscripcion::getFechaIns(){
return this->fechaIns;
}
bool DTInscripcion::getAprobadoCurso(){
return this->aprobado;
}


DTInscripcion::~DTInscripcion(){};