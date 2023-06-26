#include <string>
#include <ostream>
#include "../include/TipoDificultad.h"
using namespace std;

#ifndef DTINFOCURSOEXTENDIDO
#define DTINFOCURSOEXTENDIDO

class DTInfoCursoExtendido{
    private:
        string nombre;
        TipoDificultad dif;
        int cantDeLecciones;
        int cantDeEjercicios;
    public:
        DTInfoCursoExtendido(string nombre, TipoDificultad dif, int cantLec, int cantEj);
        string getNombre();
        TipoDificultad getDificultad();
        int getCantidadLecciones();
        int getCantidadEjercicios();

        ~DTInfoCursoExtendido();
};
#endif