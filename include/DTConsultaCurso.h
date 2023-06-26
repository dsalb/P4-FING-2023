#include <string>
#include <ostream>
#include "../include/TipoDificultad.h"
//#include "../include/Curso.h"
#include "../include/DTLeccion.h"
#include  "../include/DTInscripcion.h"
using namespace std;

#ifndef DTCONSULTACURSO
#define DTCONSULTACURSO

class DTConsultaCurso{
    private:
        string nombre;
        string descripcion;
        string dificultad;
        string nombreIdioma;
        string nombreProfesor;
        bool habilitado;
         vector<DTLeccion> colLeccion;
         vector<DTInscripcion> colInscripcion;

    public:
        DTConsultaCurso();
        DTConsultaCurso(string nombre,string desc, string dif, string nomId,string nomProf,bool hab,vector< DTLeccion> colLec, vector<DTInscripcion> colIns);
        string getNombreCurso();
        string getDescripcion();
        string getDificultad();
        string getNombreIdioma();
        string getNombreProfesor();
        bool getHabilitado();
        vector<DTLeccion> getColLecciones();
        vector<DTInscripcion> getColInscripciones();
        
        

        ~DTConsultaCurso();
};
#endif