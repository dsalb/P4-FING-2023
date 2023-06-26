#ifndef DTESTUDIANTE_HPP
#define DTESTUDIANTE_HPP

#include <string>
#include <vector>
#include "DTUsuario.h"
#include "DTFecha.h"
#include "Inscripcion.h"

class DTEstudiante : public DTUsuario{
    private:
        std::string pais;
        DTFecha fechaNacimiento;
    public:
        DTEstudiante();
        DTEstudiante(std::string nickname, std::string nombre, std::string pass, std::string desc , std::string pais,DTFecha fechaNacimiento);
        ~DTEstudiante();


        //getters
        std::string getPais();
        DTFecha getFechaNacimiento();
};

#endif
