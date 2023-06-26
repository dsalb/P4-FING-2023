#include <string>
#include <vector>
#include "Ejercicio.h"
#include "Leccion.h"
//#include <Curso.h>
//#include "Estudiante.h"
#include "DTFecha.h"
#include "DTEjercicio.h"
#include "DTInfoCurso.h"
#include "DTInscripcion.h"

#ifndef INSCRIPCIÓN
#define INSCRIPCIÓN

using namespace std;

class Curso;
class Estudiante;

class Inscripcion {

    private:
    DTFecha fechaIns;
    bool aprobado;
    int indiceLecAct;
    vector<Ejercicio*> ejAprobados;
    Curso* curso;
    Estudiante* estudiante;

    public:

    Inscripcion(DTFecha fechaIns, bool aprobado, int indiceLecAct, vector<Ejercicio*> ejAprobados, Curso* curso, Estudiante* estudiante);

    void setAprobado(bool aprobado);
    void setIndiceLecAct(int indice);
    void setEjAprobados(vector<Ejercicio*> ejAprobados);
    DTFecha getFechaIns();
    bool getAprobado();
    int getIndiceLecAct();
    vector<Ejercicio*> getEjAprobados();
    Curso* getCurso();
    Estudiante* getEstudiante();
    ~Inscripcion();

    //MÉTODOS CONTROLADORES
    string getNombreCurso();
    bool existeCurso(string curso);
    vector<DTEjercicio> ejerciciosNoAprobados();
    bool verificarSolT(string resp, int ejerId);
    bool verificarSolCP(vector<string> resp, int ejerId);
    float getAvance();
    DTInfoCurso getDataCurso(float av);
    DTInscripcion getDTInscripcion();

};

#endif