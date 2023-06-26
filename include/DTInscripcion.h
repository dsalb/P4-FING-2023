#include <string>
#include <ostream>
#include "../include/DTFecha.h"
using namespace std;

#ifndef DTINSCRIPCION
#define DTINSCRIPCION

class DTInscripcion{
private:
string nombreEstudiante;
DTFecha fechaIns;
bool aprobado;
string nick;
public:
DTInscripcion(string nombre, DTFecha fIns,bool ap, string nick);
string getNickEstudiante();
string getNombreEstudiante();
DTFecha getFechaIns(); 
bool getAprobadoCurso();
~DTInscripcion();
};
#endif