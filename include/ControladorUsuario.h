#include "IControladorUsuario.h"
#include "Usuario.h"
#include "DTNotificaciones.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Idioma.h"
#include "DTUsuario.h"
#include "DTProfesor.h"
#include "DTEstudiante.h"

#include <vector>
#include <map>
#include <string>

using namespace std;

#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

class ControladorUsuario : public IControladorUsuario {
        private:
        static ControladorUsuario* instancia;
        map<string, Usuario*> colUsuarios;
        map<string, Idioma*> colIdiomas;
        //memoria

        ControladorUsuario();

        //Antony datos en memoria
        // dato ingresado en la operacion ...(nombre de la Operacion)
        vector<string> datoIngresadoEnIdiomasSuscripcion;
        string datoIngresadoEnSeleccionarProfesor;
        string datoIngresadoEnSeleccionarIdioma;
        string datoIngresadoEnSeleccionarEstudiante;


        public:
        static ControladorUsuario* getInstancia();

        //andres
        bool esEstudiante(string nickname);
        // SANTIAGO
        vector<DTInfoCursoGeneral> listarInfoProfesor(string nombre);
        Usuario* darUsuario(string nick);
        vector<string> listarIdiomasDocente(); 
        vector<string> listarIdiomasSuscripto(string nickname);
        vector<string> listarIdiomasNoSuscripto(string nickname);
        bool existeUsuario(string nickname);
        void seleccionarIdioma(string idioma);
        void suscribirseNotificaciones(string nickname, vector<string> listaIdiomas);
        void eliminarSuscripcion(string nickname, vector<string> listaIdiomas);

        // FACUNDO
        void ingresarEstudiante(string nick, string nombre, string pass, string desc, string pais, DTFecha fechNac, vector<Inscripcion*> inscripciones);
        void ingresarProfesor(string nick, string nombre, string pass, string desc, string instituto, vector<Idioma*> idioma, vector<Curso*> cursos);
        vector<string> listarIdiomaDisp();
        void ingresarIdiomaSelec(vector<string> idiomas);
        void confirmarAltaUsuario(DTUsuario* usuario);
        vector<string> listarEstudiantes();
        vector<string> listarProfesores();
        vector<DTInfoCurso> listarInfoEstudiantes(string nickname);
        map<std::string, DTUsuario*> getcolUsuarios();
        map<std::string, Idioma*> getcolIdiomas();
        // ANTONY
        
        vector<DTNotificaciones> consultarNotificaciones(string nickname);
        void idiomasSuscripcion(vector<string> idiomasS);
        Profesor* obtenerProfesor();
        Idioma* obtenerIdioma();
        vector<DTInfoCursoGeneral> consultarEstadisticasCursoOProfesor(string tipoEstadistica,string identificador);
        vector<DTInfoCurso> consultarEstadisticasEstudiante(string identificador);
        
        /*Si no existe una instancia Idioma con nombre nombreIdioma en la coleccion de Idiomas, se da de alta el idioma
        y se retorna true. En otro caso false.
        */
        bool altaIdioma(string nombreIdioma);

        // DIEGO
        void seleccionarProfesor(string nickname);
        void seleccionarEstudiante(string nickname);
        Estudiante* obtenerEstudiante();



        // Destructor
        ~ControladorUsuario();

};

#endif