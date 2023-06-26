#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP
#include "Inscripcion.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "Ejercicio.h"
#include "DTEjercicio.h"
#include "DTInfoCurso.h"
#include <string>
#include <vector>

using namespace std;

class Estudiante : public Usuario {
private:
    string pais;
    DTFecha fechaNacimiento;
    vector<Inscripcion*> inscripciones;
public:
    Estudiante(string nickname, string nombre, string pass, string desc , string pais,DTFecha fechaNacimiento, vector<Inscripcion*> inscripciones);

    //Getters & setters
    void setPais(string pais);
    void setFecha(DTFecha fecha);
    void setInscripciones(vector<Inscripcion*> inscripciones);

    string getPais();
    DTFecha getFecha();
    vector<Inscripcion*> getInscripciones();
    void agregarInscripcion(Inscripcion* ins);

    //Metodos
    vector<string> getCursos();
    vector<DTInfoCurso> getInfoProgreso();
    vector<DTEjercicio> darEjerciciosNoAprobados(string curso); 
    bool VerificarSolT(string res, string curso, int ejer);
    bool VerificarSolCP(vector<string> res, string curso, int ejer);


   ~Estudiante();


};

#endif
