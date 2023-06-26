#include "DTInfoCurso.h"
#include "DTInfoCursoGeneral.h"
#include "DTNotificaciones.h"
#include "TipoDificultad.h"
#include "DTFecha.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "Idioma.h"
#include "DTFecha.h"
#include "DTUsuario.h"

#include <string>
#include <map>
#include <set>
#include <vector>

#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

using namespace std;



class IControladorUsuario {
public:
    
    //Andres
    virtual bool esEstudiante(string nickname)= 0;
    // SANTIAGO
    virtual vector<DTInfoCursoGeneral> listarInfoProfesor(string nombre) = 0;
    virtual vector<string> listarIdiomasDocente() = 0; 
    virtual vector<string> listarIdiomasSuscripto(string nickname) = 0;
    virtual vector<string> listarIdiomasNoSuscripto(string nickname) = 0;
    virtual void seleccionarIdioma(string idioma) = 0;
    virtual void suscribirseNotificaciones(string nickname, vector<string> listaIdiomas) = 0;
    virtual void eliminarSuscripcion(string nickname, vector<string> listaIdiomas) = 0;

    // FACUNDO
    virtual void ingresarEstudiante(string nick, string nombre, string pass, string desc, string pais, DTFecha fechNac, vector<Inscripcion*> inscripciones) = 0;
    virtual void ingresarProfesor(string nick, string nombre, string pass, string desc, string instituto, vector<Idioma*> idioma, vector<Curso*> cursos) = 0;
    virtual vector<string> listarIdiomaDisp() = 0;
    virtual void ingresarIdiomaSelec(vector<string> idiomas) = 0;
    virtual void confirmarAltaUsuario(DTUsuario* usuario) = 0;
    virtual vector<string> listarEstudiantes() = 0;
    virtual vector<string> listarProfesores() = 0;
    virtual vector<DTInfoCurso> listarInfoEstudiantes(string nickname) = 0;
    virtual map<std::string, DTUsuario*> getcolUsuarios() = 0;
    virtual map<std::string, Idioma*> getcolIdiomas() = 0;

    // ANTONY
    virtual vector<DTNotificaciones> consultarNotificaciones(string nickname) = 0;
    virtual void idiomasSuscripcion(vector<string> idiomasS) = 0;
   
    virtual vector<DTInfoCursoGeneral> consultarEstadisticasCursoOProfesor(string tipoEstadistica,string identificador) = 0;
    virtual vector<DTInfoCurso> consultarEstadisticasEstudiante(string identificador) = 0;
    
    /*Si no existe una instancia Idioma con nombre nombreIdioma en la coleccion de Idiomas, se da de alta el idioma
    y se retorna true. En otro caso false.
    */
    virtual bool altaIdioma(string nombreIdioma) = 0;

    virtual void seleccionarProfesor(string nickname) = 0;
    virtual bool existeUsuario(string nickname) = 0;

};

#endif
