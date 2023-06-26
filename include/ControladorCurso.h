#include "IControladorCurso.h"
#include "Curso.h"
#include "DTInfoCurso.h"
#include "DTInfoCursoExtendido.h"
#include  "DTConsultaCurso.h"
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO

class ControladorCurso : public IControladorCurso {
    private:
        static ControladorCurso * instancia;
        map<string, Curso*> colCurso;

            // Memoria local temporal
        int seleccLeccion;
        


        //Antony datos en memoria
        // dato ingresado en la operacion ...(nombre de la Operacion)
        string datoIngresadoEnListarCursosInscriptoEstudiante;
    

        ControladorCurso();
        // Memoria local temporal
        string ingresoDatoCursoNom;
        string ingresoDatoCursoDesc;
        TipoDificultad ingresoDatosCursoDif;
        vector<Curso*> seleccionarCursoPreviaCol;
        string ingresoDatosLeccionTema;
        string ingresoDatosLeccionObjetivo;
        map<int, Leccion*> creaLeccion;
        string seleccCurso;
        int ejSelec;         // para seleccionar ejercicio
        int ejST;            // para verificar solucion
        int ejSCP;           // para verificar solucion
        string nick;         // para verificar el usuario "Esrtudiante" en la realizacion de ejercicio
        string solCurso;     // curso para verificar la solucion de ejercicios
        Curso *eliCurso;     // para eliminar curso
        Leccion *eliLeccion; // para eliminar leccion




    public:

        static ControladorCurso* getInstancia();
        // Destructor     
        ~ControladorCurso();
        //Funciones
        //andres
         DTEjercicio realizarEj(int id, string curso, string nickname);
         void ingresarNick(string nick);
         bool cursoAprobado(string nombre,string nombreEstudiante);
         string dificultad(TipoDificultad dif);
         vector<DTLeccion> leccionesEnCurso(string nombre);
         vector<DTLeccionInt> leccionesIntEnCurso(string nombre);
         vector<DTInscripcion> incriptosEnCurso(string nombre);
         bool existeCurso(string nombre);
         DTConsultaCurso buscarConsultaCurso(string nombre);
         void seleccionarEjercicio(int) ;
         bool verificarSolucionTraduccion(string respuesta, string curso, int id);
         bool verificarSolucionCompletarPalabra(vector<string> res, string curso, int id); 
         map<int, Ejercicio*> darEjercicioLec(int id);
         void eliminarCurso(string nombre) ;
         void eliminarLeccion();
         void eliminarInscripcion();
         void desasociarPrevias();
         void altaCurso(); 

        // Diego
        vector<string> listarCursosInscriptoEstudiante(string nick);
        void ingresoDatosCurso(string nombre, string desc, TipoDificultad nivel);
        void seleccionarCursoPrevia(vector<string> colCurso);
        void ingresoDatosLeccion(string tema, string objetivo);
        void crearLeccion(bool cursoExistente);
        void altaEjercicioTraduccion(bool cursoExistente, string descripcion, string frase, string solucion);
        void altaEjercicioCompletar(bool cursoExistente, string descripcion, string frase, vector<string> solucion);
        void seleccionarCurso(string curso);
        void seleccionarLeccion(int leccion);
        void vaciarMemoriaLeccion();
        void cargaColInicial(map<string, Curso*> colCursoDatos);

        //Antony
        vector<string> listarCursos();
        vector<string> listarCursosHabilitados();
        vector<DTEjercicio> listarEjerciciosNoAprobadosCursos(string curso, string nickname);
        DTInfoCursoGeneral listarInfoCurso(string nombre);

        /*Se listan los nombres de cursos que pueden habilitarse, esto es,
        Un curso se puede habilitar solo si tiene al
        menos una lección y un ejercicio, y no tiene lecciones sin ejercicios.*/
        vector<string> listarCursosDisponiblesParaHabilitar();
        vector<string> listarCursosNoDisponibles();
        void habilitarCurso(string nombreCurso);

        /*Esta lista incluye todos los DTInfoCursoExtendido de cursos habilitados en los que aún no
        se ha inscripto el estudiante y cuyos cursos previos han sido todos aprobados por el
        estudiante*/
        vector<DTInfoCursoExtendido> listarCursosParaInscripcionEstudiante(string nicknameEst);
        void inscribirseACurso(string nicknameEst, string curso);
};  

#endif
