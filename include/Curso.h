#include <string>
#include "Leccion.h"
#include "Inscripcion.h"
#include "Idioma.h"
#include "TipoDificultad.h"
#include <iostream>
#include <algorithm>
#include "DTInfoCurso.h"
#include "DTInfoCursoGeneral.h"
#include "Estudiante.h"
#include "DTConsultaCurso.h"

#ifndef CURSO
#define CURSO

using namespace std;

class Profesor;

class Curso {
    private:
        string nombre;
        string desc;
        TipoDificultad dificultad;
        bool habilitado;
        vector<Inscripcion*> colInscripciones;
        map<int, Leccion*> colLecciones;
        vector<Curso*> previas;
        Idioma* idiomaCurso;
        Profesor* profesor;
        
    public:   
        
        Curso(string nombre,string desc, TipoDificultad dif, bool habilitado,Profesor* profe, vector<Inscripcion*> colI, map<int, Leccion*> colL, vector<Curso*> previas, Idioma* idioma);
        
        void setNombre(string nombre);
        void setDificultad(TipoDificultad nivel);

        void habilitarCurso();
        void agregarInscripcion(Inscripcion* ins);
        void agregarLeccion(string tema, string objetivo, map<int, Ejercicio*> colEj);
        void agregarPrevia(Curso* previa);
        void setIdioma(Idioma* idioma);

        string getNombre();
        string getDescripcion();
        TipoDificultad getDificultad();
        vector<Inscripcion*> getInscripciones();
        map<int, Leccion*> getLecciones();
        
        DTConsultaCurso getDTConsultaCurso();
        vector<Curso*> getPrevias();
        Idioma* getIdioma();
        Profesor* getProfesor();

        DTInfoCursoGeneral getInfoCursoGeneral();
        int getCantidadEj();
        int getCantidadLec();
        bool estaHabilitado();
        Ejercicio* buscarEjercicioEnLec(int indiceEj,int indiceLec);
        map<int, Ejercicio*> darEjerciciosLec(int idLec);
        void eliminarInscripciones();
        void eliminarPrevia(Curso* previa);
        bool esPrevia(Curso* previa);

        ~Curso();  
};

#endif


