#include "../include/ControladorCurso.h"
#include "../include/ControladorUsuario.h"
#include "../include/IControladorCurso.h"
#include "../include/Profesor.h"
#include "../include/DTInfoCursoGeneral.h"
#include  "../include/DTConsultaCurso.h"
#include "../include/FechaSistema.h"
#include "../include/DTFecha.h"
#include "../include/DTEjercicio.h"
#include "../include/DTInscripcion.h"
#include "../include/DTLeccion.h"
#include "../include/DTLeccionInt.h"

// CONSTRUCTOR
ControladorCurso *ControladorCurso::instancia = NULL;

ControladorCurso::ControladorCurso(){};

ControladorCurso *ControladorCurso::getInstancia()
{
     if (instancia == NULL)
          instancia = new ControladorCurso();
     return instancia;
};

// FUNCIONES DE CADA UNO

// ANDRES
DTEjercicio ControladorCurso::realizarEj(int id, string curso, string nickname){
     DTEjercicio ejDT ;
     map<string, Curso *>::iterator it;
     it = colCurso.find(curso);
     map<int , Leccion*> colL= it->second->getLecciones(); 
     
     ControladorUsuario* cU = ControladorUsuario::getInstancia();
     Usuario* usuario = cU->darUsuario(nickname);
     Estudiante* est = dynamic_cast<Estudiante*>(usuario);
     vector<Inscripcion*> colIns = est->getInscripciones();
     vector<Inscripcion*>::iterator ITins;
     int lecAct ;
     bool encontrada = false;
     for(ITins = colIns.begin(); (ITins != colIns.end())&&(!encontrada); ++ITins)
          if((*ITins)->getNombreCurso() == curso){
               encontrada = true;
               lecAct = (*ITins)->getIndiceLecAct();
          }
     map<int, Ejercicio *> colEj = it->second->darEjerciciosLec(lecAct);
     map<int ,Ejercicio*> :: iterator ejle;
     for (ejle = colEj.begin(); ejle != colEj.end(); ++ejle){
          if(ejle->second->getId()==id){
               string tipoEj;
               string cPalabra;
               Traduccion* tEj = dynamic_cast<Traduccion*>(ejle->second);
               if( tEj!=nullptr){
                    tipoEj = "traduccion"; 
               }else 
                    {tipoEj = "cPalabra"; }
               DTEjercicio ejDT = DTEjercicio(ejle->second->getDescripcion(),ejle->second->getFrase() ,ejle->second->getId(),tipoEj );
               return ejDT;
          }
     } 
     return ejDT; 
};
bool ControladorCurso::cursoAprobado(string nombreCurso,string nickEstudiante ){
     vector<DTInscripcion> in =incriptosEnCurso(nombreCurso);
     vector<DTInscripcion>::iterator i;
     bool res = false;
     if(!in.empty()){
          for (i=in.begin();i!=in.end();++i){
               if(i->getNickEstudiante()==nickEstudiante){
                   res = i->getAprobadoCurso();
               }
          } 
     }
     return res; 
     
}
string ControladorCurso::dificultad(TipoDificultad dif){
     switch (dif) {
          case Principiante:
          return "Principiante";
     break;
          case Medio:
          return "Medio";
     break;
          case Avanzado:
          return "Avanzado";
     break;
          default:
          return "0";
     break;
     }
} 
vector<DTLeccion> ControladorCurso::leccionesEnCurso(string nombre){
     vector<DTLeccion> leDT;
     map<string, Curso *>::iterator it;
     it = colCurso.find(nombre); 
     map<int , Leccion*> colL= it->second->getLecciones();
     map<int ,Leccion*> :: iterator le;
     for (le = colL.begin(); le != colL.end(); ++le){
          map<int, Ejercicio *> colEj= le->second->getEjercicios();
          map<int ,Ejercicio*> :: iterator ejle;
          vector<DTEjercicio> colEje;
          for (ejle = colEj.begin(); ejle != colEj.end(); ++ejle){
               string tipoEjercicio;
               DTEjercicio veEj = DTEjercicio(ejle->second->getDescripcion(),ejle->second->getFrase() ,ejle->second->getId(),tipoEjercicio);
               colEje.push_back(veEj);
          }    
          DTLeccion aux = DTLeccion( le->second->getTema(),le->second->getObjetivo(),colEje);
          leDT.push_back(aux);
     } 
     return leDT;
};

vector<DTLeccionInt> ControladorCurso::leccionesIntEnCurso(string nombre){
     vector<DTLeccionInt> leDT;
     map<string, Curso *>::iterator it;
     it = colCurso.find(nombre);   
     map<int , Leccion*> colL= it->second->getLecciones();
     map<int ,Leccion*> :: iterator le;
      for (le = colL.begin(); le != colL.end(); ++le){
          map<int, Ejercicio *> colEj= le->second->getEjercicios();
          map<int ,Ejercicio*> :: iterator ejle;
          vector<DTEjercicio> colEje;
          for (ejle = colEj.begin(); ejle != colEj.end(); ++ejle){
               string tipoEjercicio;
               DTEjercicio veEj = DTEjercicio(ejle->second->getDescripcion(),ejle->second->getFrase() ,ejle->second->getId(),tipoEjercicio);
               colEje.push_back(veEj);
          }
          DTLeccionInt aux = DTLeccionInt( le->second->getTema(),le->second->getObjetivo(), le->second->getIndice(),colEje);
          leDT.push_back(aux);
                  
     } 
        
return leDT;
};




vector<DTInscripcion> ControladorCurso::incriptosEnCurso(string nombre){
     vector<DTInscripcion> insDT;
     map<string, Curso *>::iterator it;
     it = colCurso.find(nombre); 
     vector<Inscripcion*> colI= it->second->getInscripciones();
     vector<Inscripcion*> :: iterator ins;
     for (ins = colI.begin(); ins != colI.end(); ++ins)
     {
          DTInscripcion aux =DTInscripcion((*ins)->getEstudiante()->getNombre(),(*ins)->getFechaIns(),(*ins)->getAprobado(),(*ins)->getEstudiante()->getNickname());
          insDT.push_back(aux);
     } 
     return insDT;
     };


bool ControladorCurso::existeCurso(string nombre){
     if(!this->colCurso.empty()){
          if(this->colCurso.find(nombre) != this->colCurso.end()){
               return true; 
          } else return false; 
     } else return false;
} 

DTConsultaCurso ControladorCurso::buscarConsultaCurso(string nombre){
     map<string, Curso *>::iterator it;
     it = colCurso.find(nombre); 
     DTConsultaCurso cDT = DTConsultaCurso(it->second->getNombre(),it->second->getDescripcion(), dificultad(it->second->getDificultad()) , it->second->getIdioma()->getNombre(),it->second->getProfesor()->getNombre(),it->second->estaHabilitado(),leccionesEnCurso( nombre), incriptosEnCurso(nombre)); 
     return cDT;
};
void ControladorCurso::seleccionarEjercicio(int ejercicio)
{
     ejSelec = ejercicio;
       cout <<ejSelec<< endl;
};

void ControladorCurso::ingresarNick(string nick) {
     this->nick = nick;
};

bool ControladorCurso::verificarSolucionTraduccion(string respuesta, string curso, int id)
{
     ControladorUsuario *ctu = ControladorUsuario::getInstancia();
     Estudiante *e = dynamic_cast<Estudiante *>(ctu->darUsuario(nick));
     return e->VerificarSolT(respuesta, curso, id);
};
bool ControladorCurso::verificarSolucionCompletarPalabra(vector<string> res, string curso, int id)
{
     ControladorUsuario *ctu = ControladorUsuario::getInstancia();
     Estudiante *e = dynamic_cast<Estudiante *>(ctu->darUsuario(nick));
     return e->VerificarSolCP(res, curso, id);
};
map<int, Ejercicio *> ControladorCurso::darEjercicioLec(int id)
{
     map<int, Leccion *> colLec;
     map<int, Leccion *>::iterator it;
     it = colLec.find(id);
     return it->second->getEjercicios();
};
void ControladorCurso::eliminarCurso(string nombre) {
     map<string, Curso *>::iterator it;
     it = this->colCurso.find(nombre);
     eliCurso = it->second;
     // eliminar inscripcion
     eliminarInscripcion();
     eliCurso->getProfesor()->quitarCurso(eliCurso);
     // eliminar leccion
     desasociarPrevias();
     map<int, Leccion *> colLec = it->second->getLecciones();
     map<int, Leccion *>::iterator itLec;
     for (itLec = colLec.begin(); itLec != colLec.end(); ++itLec) {
          eliLeccion = itLec->second;
          eliminarLeccion();
     }
     this->colCurso.erase(nombre);
     eliCurso->~Curso();
};
void ControladorCurso::eliminarLeccion()
{
     eliLeccion->~Leccion();
};
void ControladorCurso::eliminarInscripcion() {
     eliCurso->eliminarInscripciones();
};

void ControladorCurso::desasociarPrevias() {
     map<string, Curso*>::iterator it;
     for (it = colCurso.begin(); it != colCurso.end(); ++it) {
          if (it->second->esPrevia(eliCurso)){
               it->second->eliminarPrevia(eliCurso);
          }
     }
}

void ControladorCurso::altaCurso()
{
     // crear c con los parametros dados
     ControladorUsuario *ctu = ControladorUsuario::getInstancia();
     Profesor *p = ctu->obtenerProfesor();
     Idioma *i = ctu->obtenerIdioma();
     // agregar c a la coleccion de cursos
     vector<Inscripcion*> colI;
     Curso *c=  new Curso(this->ingresoDatoCursoNom,this->ingresoDatoCursoDesc,this->ingresoDatosCursoDif,false,p, colI, creaLeccion,this->seleccionarCursoPreviaCol,i);
     colCurso[this->ingresoDatoCursoNom] = c;
     p->agregarCurso(c); 
     i->notificarSuscriptores(c->getNombre(),i->getNombre());
    
};

// DIEGO

vector<string> ControladorCurso::listarCursosInscriptoEstudiante(string nick) {
      vector<string> resp;
      ControladorUsuario *ctu = ControladorUsuario::getInstancia();
      Estudiante* est = dynamic_cast<Estudiante*>(ctu->darUsuario(nick)); 
     // Estudiante* est = ControladorUsuario::darUsuario(nick);
      vector<Inscripcion*> inscripciones = est->getInscripciones();
      vector<Inscripcion*>::iterator it;
      for (it = inscripciones.begin(); it != inscripciones.end(); ++it) {
            Inscripcion* actual = *it;
            resp.push_back(actual->getNombreCurso());
      }
      return resp;
}

void ControladorCurso::ingresoDatosCurso(string nombre, string desc, TipoDificultad nivel) {
      this->ingresoDatoCursoNom = nombre;
      this->ingresoDatoCursoDesc = desc;
      this->ingresoDatosCursoDif = nivel;
};

void ControladorCurso::seleccionarCursoPrevia(vector<string> colCursoPrev) {
      vector<string>::iterator it;
      seleccionarCursoPreviaCol.clear();
      for (it = colCursoPrev.begin(); it != colCursoPrev.end(); ++it) {
        if (this->colCurso.find(*it) != this->colCurso.end()) {
            seleccionarCursoPreviaCol.push_back(this->colCurso.find(*it)->second);
        }
    }      
};

void ControladorCurso::ingresoDatosLeccion(string tema, string objetivo) {
      this->ingresoDatosLeccionTema = tema;
      this->ingresoDatosLeccionObjetivo= objetivo;
};

void ControladorCurso::vaciarMemoriaLeccion() {
     this->creaLeccion.clear();
};

void  ControladorCurso::cargaColInicial(map<string, Curso*> colCursoDatos) {
     this->colCurso = colCursoDatos;
}

// true para lección en curso nuevo, false para curso existente para lo cual antes de debió llamar a seleccioarCurso()
void ControladorCurso::crearLeccion(bool cursoExistente) {
      if (!cursoExistente) {
          int id = this->creaLeccion.size();
          map<int, Ejercicio*> ejLeccion;
          Leccion* leccPtr = new Leccion(this->ingresoDatosLeccionTema, this->ingresoDatosLeccionObjetivo, id, ejLeccion);
          this->creaLeccion[id] = leccPtr;
      } else {
          map<string, Curso*>::iterator it = colCurso.find(this->seleccCurso);
          Curso* curso = it->second;
          map<int, Ejercicio *> colEj;
          curso->agregarLeccion(this->ingresoDatosLeccionTema, this->ingresoDatosLeccionObjetivo, colEj);
      }
};

// true para ejercicio en curso nuevo, false para curso existente para lo cual antes de debió llamar a seleccioarCurso() y seleccionarLeccion()
void ControladorCurso::altaEjercicioTraduccion(bool cursoExistente, string descripcion, string frase, string solucion) {
      if (!cursoExistente) {
          int id = this->creaLeccion.size() - 1;
          this->creaLeccion[id]->agregarEjerT(descripcion, frase, solucion);
      } else {
          map<string, Curso*>::iterator it = colCurso.find(this->seleccCurso);
          Curso* curso = it->second;
          map<int, Leccion*>::iterator j = curso->getLecciones().find(this->seleccLeccion);
          Leccion* leccion = j->second;
          leccion->agregarEjerT(descripcion, frase, solucion);
      }
};

// true para ejercicio en curso nuevo, false para curso existente para lo cual antes de debió llamar a seleccioarCurso() y seleccionarLeccion()
void ControladorCurso::altaEjercicioCompletar(bool cursoExistente, string descripcion, string frase, vector<string> solucion) {
      if (!cursoExistente) {
          int id = this->creaLeccion.size() - 1;
          this->creaLeccion[id]->agregarEjerC(descripcion, frase, solucion);
      } else {
          map<string, Curso*>::iterator it = colCurso.find(this->seleccCurso);
          Curso* curso = it->second;
          map<int, Leccion*>::iterator j = curso->getLecciones().find(this->seleccLeccion);
          Leccion* leccion = j->second;
          leccion->agregarEjerC(descripcion, frase, solucion);
      }
};

void ControladorCurso::seleccionarCurso(string curso) {
      this->seleccCurso = curso;
};

void ControladorCurso::seleccionarLeccion(int leccion) {
      this->seleccLeccion = leccion;
};

//Antony
vector<string> ControladorCurso::listarCursos(){
     map<string, Curso*>::iterator it;
     vector<string> res;
     for(it = this->colCurso.begin(); it != this->colCurso.end(); ++it)
          res.push_back(it->second->getNombre());

     return res; 
}

vector<string> ControladorCurso::listarCursosHabilitados(){
     map<string, Curso*>::iterator it;
     vector<string> res;
     for(it = this->colCurso.begin(); it != this->colCurso.end(); ++it)
          if(it->second->estaHabilitado())
               res.push_back(it->second->getNombre());

     return res;
}

vector<DTEjercicio> ControladorCurso::listarEjerciciosNoAprobadosCursos(string curso, string nickname){
     ControladorUsuario *ctu = ControladorUsuario::getInstancia();
     Estudiante* ptre = dynamic_cast<Estudiante*>(ctu->darUsuario(nickname)); 
     return ptre->darEjerciciosNoAprobados(curso);
}

DTInfoCursoGeneral ControladorCurso::listarInfoCurso(string nombre){
     map<string, Curso*>::iterator it;
     it = this->colCurso.find(nombre);
     return it->second->getInfoCursoGeneral();
}

vector<string> ControladorCurso::listarCursosDisponiblesParaHabilitar(){
     map<string, Curso*>::iterator it;
     vector<string> res;

     map<int, Leccion*> colLec;
     map<int, Leccion*>::iterator itLec;
     
     bool condicion;
     for(it = this->colCurso.begin(); it != this->colCurso.end(); ++it){
          if(!(it->second->estaHabilitado())){
               colLec = it->second->getLecciones();
               condicion = colLec.size() != 0;
               for(itLec = colLec.begin(); (itLec != colLec.end())&&condicion; ++itLec)
                    condicion = itLec->second->cantEjercicios() != 0;
               if(condicion)
                    res.push_back(it->second->getNombre());
          }
     }
     return res;
}

void ControladorCurso::habilitarCurso(string nombreCurso){
     map<string, Curso*>::iterator it;
     it = this->colCurso.find(nombreCurso);
     it->second->habilitarCurso();
}

vector<DTInfoCursoExtendido> ControladorCurso::listarCursosParaInscripcionEstudiante(string nickEst){
     ControladorUsuario *ctu = ControladorUsuario::getInstancia();
     vector<DTInfoCursoExtendido> res;
     if(Estudiante* est = dynamic_cast<Estudiante*>(ctu->darUsuario(nickEst))){
          vector<Inscripcion*> ins = est->getInscripciones();
          vector<Inscripcion*>::iterator itIns;
          map<string, Curso*>::iterator it;


          for(it = this->colCurso.begin(); it != this->colCurso.end(); ++it ){
               if(it->second->estaHabilitado()){
                    bool condNoInscripto = true;
                    string nombreCursoActual = it->second->getNombre();

                    //condicion de que no esta inscripto a ese curso
                    for(itIns = ins.begin(); (itIns != ins.end())&&(condNoInscripto); ++itIns)
                         condNoInscripto = (*itIns)->getNombreCurso() != nombreCursoActual;
                    

                    if(condNoInscripto){
                         
                         //condicion de que tiene las previas aprobadas
                         bool condPreviasAprob = true;
                         
                         vector<Curso*>::iterator itPreviaDelCurso;
                         vector<Curso*> colPreviasDelCurso = it->second->getPrevias();
                         
                         //recorro las previas del curso para verificar que el estudiante las tenga aprobadas
                          
                         for(itPreviaDelCurso = colPreviasDelCurso.begin(); (itPreviaDelCurso != colPreviasDelCurso.end())&&(condPreviasAprob); ++itPreviaDelCurso){
                              bool noEncontrePrevia = true;
                              bool aprobada = false;
                              for(itIns = ins.begin(); (itIns != ins.end())&&(noEncontrePrevia); ++itIns){
                                   noEncontrePrevia = (*itPreviaDelCurso)->getNombre() != (*itIns)->getNombreCurso();
                                   if(!noEncontrePrevia)
                                        aprobada = (*itIns)->getAprobado();
                              }
                              condPreviasAprob = aprobada;
                         }
                         if(condPreviasAprob)
                              res.push_back(DTInfoCursoExtendido(it->second->getNombre(), it->second->getDificultad(), it->second->getCantidadLec(), it->second->getCantidadEj()));
                    }
               }
          }    
     }    
     return res;
}

void ControladorCurso::inscribirseACurso(string nickEst, string curso){
     ControladorUsuario *ctu = ControladorUsuario::getInstancia();
     Estudiante* ptrEst = dynamic_cast<Estudiante*>(ctu->darUsuario(nickEst));
     Curso* ptrCurso = this->colCurso.find(curso)->second;
     vector<Ejercicio*> ejAprobados;

     FechaSistema* fs = FechaSistema::getInstancia();

     Inscripcion* ins = new Inscripcion(fs->getFechaSistema(), false, 0, ejAprobados, ptrCurso, ptrEst);

     ptrCurso->agregarInscripcion(ins);
     ptrEst->agregarInscripcion(ins);
}

vector<string> ControladorCurso::listarCursosNoDisponibles() {
     map<string, Curso*>::iterator it;
     vector<string> res;
     for(it = this->colCurso.begin(); it != this->colCurso.end(); ++it){
          if(!(it->second->estaHabilitado())){
               res.push_back(it->second->getNombre());
          }
     }
     return res;
}

// DESTRUCTOR
ControladorCurso::~ControladorCurso(){};
