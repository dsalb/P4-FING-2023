#ifndef PROFESOR_HPP
#define PROFESOR_HPP

#include "Usuario.h"
#include "DTIdioma.h"

#include <string>
#include <vector>
#include <iostream>

#include "DTInfoCursoGeneral.h"
#include "Curso.h"
using namespace std;

class Profesor : public Usuario {
    private:
        string instituto;
        vector<Idioma*> idiomas;
        vector<Curso*> cursos;
    public:
        Profesor(std::string nickname, std::string nombre,std::string pass, std::string desc,  std::string instituto,vector<Idioma*> idiomas,vector<Curso*> cursos);
        ~Profesor();

        //Getters
        string getInstituto();
        vector<Idioma*> getIdiomas();
        vector<DTIdioma*> getDTIdiomas();
        vector<DTInfoCursoGeneral> getInfoProgreso();
        vector<Curso*> getCursos();

        //Setters
        void setInstituto(std::string instituto);
        void setIdiomas(vector<Idioma*> idiomas);
        void quitarCurso(Curso* curso);
        void agregarCurso(Curso* c);
        void AgregarIdioma(vector<Idioma*> idiomas);
};

#endif