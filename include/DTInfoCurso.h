#include <string>
#include <ostream>
#include "../include/TipoDificultad.h"
using namespace std;

#ifndef DTINFOCURSO
#define DTINFOCURSO

class DTInfoCurso{
    private:
        string nombre;
        float avance;
        TipoDificultad dificultad;

    public:
        DTInfoCurso(string nombre, float av, TipoDificultad dif);
        string getNombreCurso();
        float getAvance();
        TipoDificultad getDificultad();

        ~DTInfoCurso();
};
#endif