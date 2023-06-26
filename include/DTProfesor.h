#ifndef DTPROFESOR_HPP
#define DTPROFESOR_HPP

#include "DTUsuario.h"
#include "Idioma.h"
#include "Curso.h"
#include "DTIdioma.h"

#include <string>
#include <vector>
#include <iostream>

class DTProfesor : public DTUsuario {
    private:
        std::string instituto;
        vector<DTIdioma*> idiomas;
    public:
        DTProfesor();
        DTProfesor(std::string nickname, std::string nombre,std::string pass, std::string desc,  std::string instituto,vector<DTIdioma*> idiomas);
        ~DTProfesor();

        //Getters 
        std::string getInstituto();
        vector<DTIdioma*> getIdiomas();
};

#endif