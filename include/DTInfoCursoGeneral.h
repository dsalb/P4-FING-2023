#include <string>
#include <ostream>
#include "../include/TipoDificultad.h"
using namespace std;

#ifndef DTINFOCURSOGENERAL
#define DTINFOCURSOGENERAL

class DTInfoCursoGeneral{
    private:
        string nombre;
        float avanceProm;
        TipoDificultad dificultad;

    public:
        DTInfoCursoGeneral(string nombre, float av, TipoDificultad dif);
        string getNombreCurso();
        float getAvanceProm();
        TipoDificultad getDificultad();

        ~DTInfoCursoGeneral();
};
#endif