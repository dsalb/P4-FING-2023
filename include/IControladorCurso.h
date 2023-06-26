#include "DTInfoCurso.h"
#include "DTInfoCursoGeneral.h"
#include "DTNotificaciones.h"
#include "TipoDificultad.h"
#include "Curso.h"
#include "DTFecha.h"
#include "DTLeccionInt.h"
#include "DTEjercicio.h"
#include "DTInfoCursoExtendido.h"
#include "DTInscripcion.h"
#include "DTConsultaCurso.h"
#include <string>
#include <map>
#include <set>
#include <vector>

#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO

using namespace std;



class IControladorCurso
{
public:

    // Diego
    virtual vector<string> listarCursosInscriptoEstudiante(string nick)=0;
    virtual void ingresoDatosCurso(string nombre, string desc, TipoDificultad nivel)=0;
    virtual void seleccionarCursoPrevia(vector<string> colCurso)=0;
    virtual void ingresoDatosLeccion(string tema, string objetivo)=0;
    virtual void crearLeccion(bool cursoExistente)=0;
    virtual void altaEjercicioTraduccion(bool cursoExistente, string descripcion, string frase, string solucion)=0;
    virtual void altaEjercicioCompletar(bool cursoExistente, string descripcion, string frase, vector<string> solucion)=0;
    virtual void seleccionarCurso(string curso)=0;
    virtual void seleccionarLeccion(int leccion)=0;

 //Antony
    virtual vector<string> listarCursos() = 0;
    virtual vector<string> listarCursosHabilitados() = 0;
    virtual vector<DTEjercicio> listarEjerciciosNoAprobadosCursos(string curso, string nickname)=0;
    virtual DTInfoCursoGeneral listarInfoCurso(string nombre)=0;
    virtual vector<string> listarCursosDisponiblesParaHabilitar()=0;
    virtual vector<string> listarCursosNoDisponibles()=0;
    virtual void habilitarCurso(string nombreCurso)=0;
    virtual vector<DTInfoCursoExtendido> listarCursosParaInscripcionEstudiante(string nombreEst)=0;
    virtual void inscribirseACurso(string nicknameEstudiante, string curso)=0;
   //andres
    virtual void ingresarNick(string nick) = 0;
    virtual DTEjercicio realizarEj(int id, string curso, string nickname)=0;
    virtual bool cursoAprobado(string nombre,string nombreEstudiante)=0;
    virtual string dificultad(TipoDificultad dif)=0;
    virtual vector<DTLeccion> leccionesEnCurso(string nombre)=0;
    virtual vector<DTLeccionInt> leccionesIntEnCurso(string nombre)=0;
    virtual vector<DTInscripcion> incriptosEnCurso(string nombre)=0;
    virtual bool existeCurso(string nombre) = 0;
    virtual DTConsultaCurso buscarConsultaCurso(string nombre)=0;
    virtual void seleccionarEjercicio(int) = 0;
    virtual bool verificarSolucionTraduccion(string respuesta, string curso, int id) = 0;
    virtual bool verificarSolucionCompletarPalabra(vector<string> res, string curso, int id) = 0; 
    virtual void eliminarCurso(string nombre) = 0;
    virtual void eliminarLeccion() = 0;
    virtual void eliminarInscripcion() = 0;
    virtual void desasociarPrevias() = 0;
    virtual void altaCurso() = 0; 
    virtual void vaciarMemoriaLeccion() = 0;
    virtual void cargaColInicial(map<string, Curso*> colCursoDatos) = 0;
};

#endif
