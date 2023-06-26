#include "../include/ControladorCurso.h"
#include "../include/ControladorUsuario.h"
#include "../include/Usuario.h"
#include "../include/Profesor.h"

// instance
ControladorUsuario* ControladorUsuario::instancia = NULL;

//C&D
ControladorUsuario::ControladorUsuario(){};
ControladorUsuario::~ControladorUsuario(){};

ControladorUsuario* ControladorUsuario::getInstancia(){
     if( instancia == NULL )
          instancia = new ControladorUsuario();
     return instancia;
};

//FUNCIONES DE CADA UNO

      //res es vacio si no existe el usuario con nickname igual al pasado por parametro
     vector<DTNotificaciones> ControladorUsuario::consultarNotificaciones(string nickname){
          map<string, Usuario*>::iterator it;
          vector<DTNotificaciones> res;
          it = this->colUsuarios.find(nickname);
          if (it != this->colUsuarios.end()){
               IObserver* aux = dynamic_cast<IObserver*>(it->second);
               res = aux->consultarNotificaciones();
          }
     return res;
     }

     void ControladorUsuario::idiomasSuscripcion(vector<string> idiomasS){
          this->datoIngresadoEnIdiomasSuscripcion = idiomasS;
     }


     Profesor* ControladorUsuario::obtenerProfesor(){
          Usuario* aux = this->darUsuario(this->datoIngresadoEnSeleccionarProfesor);
          Profesor* res = dynamic_cast<Profesor*>(aux);
          return res;
     }

     Estudiante* ControladorUsuario::obtenerEstudiante(){
          Usuario* aux = this->darUsuario(this->datoIngresadoEnSeleccionarEstudiante);
          Estudiante* res = dynamic_cast<Estudiante*>(aux);
          return res;
     }

     Idioma* ControladorUsuario::obtenerIdioma(){
          return this->colIdiomas[this->datoIngresadoEnSeleccionarIdioma];
     }


     vector<DTInfoCursoGeneral> ControladorUsuario::consultarEstadisticasCursoOProfesor(string tipoEstadistica,string identificador){
          ControladorCurso* cc = ControladorCurso::getInstancia();
          vector<DTInfoCursoGeneral> resultado;
          if(tipoEstadistica == "curso"){
               resultado.push_back(cc->listarInfoCurso(identificador));
          }
          else{
               Usuario* aux = this->darUsuario(identificador);
               Profesor* res = dynamic_cast<Profesor*>(aux);
               resultado = res->getInfoProgreso();
          }
          return resultado;
     }
     vector<DTInfoCurso> ControladorUsuario::consultarEstadisticasEstudiante(string identificador){
          Usuario* aux = this->darUsuario(identificador);
          Estudiante* res = dynamic_cast<Estudiante*>(aux);
          return res->getInfoProgreso();
     }

     bool ControladorUsuario::altaIdioma(string nombreIdioma){
          map<string, Idioma*>::iterator itI;
          itI = this->colIdiomas.find(nombreIdioma);
          bool cond = itI == this->colIdiomas.end();
          /*bool cond = true;
          for(itI = this->colIdiomas.begin(); (itI != this->colIdiomas.end())&&(cond); ++itI)
               cond = itI->second->getNombre() != nombreIdioma;
               */
          if(cond){
               Idioma* idioma = new Idioma(nombreIdioma);
               //this->colIdiomas.push_back(idioma);
               this->colIdiomas[nombreIdioma] = idioma;
          }
          return cond;
     }

vector<DTInfoCursoGeneral> ControladorUsuario::listarInfoProfesor(string nombre) {
    vector<DTInfoCursoGeneral> info;
    map<string, Usuario *>::iterator itU = this->colUsuarios.find(nombre);
    if (itU != this->colUsuarios.end()) {
        Profesor* profesor = dynamic_cast<Profesor*>(itU->second);
        if (profesor) {
            info = profesor->getInfoProgreso();
        }
    }
    return info;
}

Usuario* ControladorUsuario::darUsuario(string nick) {
    map<string, Usuario *>::iterator itU = this->colUsuarios.find(nick);
    if (itU != this->colUsuarios.end()) {
        return itU->second;
    } else 
        return NULL;
}

vector<string> ControladorUsuario::listarIdiomasDocente() {
    vector<string> listaIdiomasD;
    map<string, Usuario *>::iterator itU = this->colUsuarios.find(this->datoIngresadoEnSeleccionarProfesor);
    if (itU != this->colUsuarios.end()) {
        Profesor* profesor = dynamic_cast<Profesor*>(itU->second);
        if (profesor) {
            vector<Idioma*> idiomasProfesor = profesor->getIdiomas();
            vector<Idioma*>::iterator itI;
            for (itI = idiomasProfesor.begin(); itI != idiomasProfesor.end(); ++itI) {               
                listaIdiomasD.push_back((*itI)->getNombre());
            }
        }
    }
    return listaIdiomasD;
}

vector<string> ControladorUsuario::listarIdiomasSuscripto(string nickname) {
    vector<string> listaIdiomasS;
    map<string,Usuario*>::iterator itU = this->colUsuarios.find(nickname);
    if(itU != this->colUsuarios.end()){
          map<string, Idioma*>::iterator itI;
          for(itI = colIdiomas.begin(); itI != colIdiomas.end(); ++itI){
               if (itI->second->estaSuscripto(nickname))
               listaIdiomasS.push_back(itI->second->getNombre());
            }
        }
    return listaIdiomasS;
}


vector<string> ControladorUsuario::listarIdiomasNoSuscripto(string nickname) {
    vector<string> listaIdiomasS;
    map<string,Usuario*>::iterator itU = this->colUsuarios.find(nickname);
    if(itU != this->colUsuarios.end()){
          map<string,Idioma*>::iterator itI;
            for(itI = colIdiomas.begin(); itI != colIdiomas .end(); ++itI){
                if (!(itI->second->estaSuscripto(nickname)))
                    listaIdiomasS.push_back(itI->second->getNombre());
            }
        }
    return listaIdiomasS;
}

void ControladorUsuario::seleccionarIdioma(string idioma) { 
        this->datoIngresadoEnSeleccionarIdioma = idioma;
}

void ControladorUsuario::suscribirseNotificaciones(string nickname, vector<string>listaIdiomas) {
    map<string, Usuario *>::iterator itU = this->colUsuarios.find(nickname);
    map<string, Idioma *>::iterator itI;
    if (itU != this->colUsuarios.end()) {
        IObserver* observer = dynamic_cast<IObserver*>(itU->second);
        if (observer) {
            vector<string>::iterator it;
            for (it = listaIdiomas.begin(); it != listaIdiomas.end(); ++it) {
                itI = this->colIdiomas.find(*it);
                itI->second->suscribirse(observer);
            }
        }
    }
}

void ControladorUsuario::eliminarSuscripcion(string nickname, vector<string> listaIdiomas) {
    map<string, Usuario *>::iterator itU = this->colUsuarios.find(nickname);
    map<string, Idioma*>::iterator itI;
    if (itU != this->colUsuarios.end()) {
        IObserver* observer = dynamic_cast<IObserver*>(itU->second);
        if (observer) {
            vector<string>::iterator it;
            for (it = listaIdiomas.begin(); it != listaIdiomas.end(); ++it) {
                itI = this->colIdiomas.find(*it);
                itI->second->eliminarSuscripcion(observer);
            }
        }
    }
}


//MIS FUNCIONES
void ControladorUsuario::ingresarEstudiante(std::string nick, std::string nombre, std::string pass, std::string desc, std::string pais, DTFecha fechNac, vector<Inscripcion*> inscripciones){
     Usuario* estudiante = new Estudiante(nick, nombre, pass, desc, pais, fechNac, inscripciones);
     this->colUsuarios[nick] = estudiante;
}
void ControladorUsuario::ingresarProfesor(std::string nick, std::string nombre, std::string pass, std::string desc, std::string instituto, std::vector<Idioma*> idioma, vector<Curso*> cursos){
     Usuario* profesor = new Profesor(nick, nombre, pass, desc, instituto, idioma, cursos);
      this->colUsuarios[nick] = profesor;
}
void ControladorUsuario::confirmarAltaUsuario(DTUsuario * usuario){
     DTEstudiante* dynEst = dynamic_cast<DTEstudiante*>(usuario);
     DTProfesor* dynProf = dynamic_cast<DTProfesor*>(usuario);

     if (dynEst != NULL) {
          vector<Inscripcion*> inscripcionesList;
          this->ingresarEstudiante(dynEst->getNickname(), dynEst->getNombre(),dynEst->getPass(), dynEst->getDesc() ,dynEst->getPais(), dynEst->getFechaNacimiento(), inscripcionesList);
     }else if (dynProf != NULL) {
          std::vector<Idioma*> idiomaList;
          vector<Curso*> cursosList;
          vector<DTIdioma*> DTIdiList = dynProf->getIdiomas();
          vector<DTIdioma*>::iterator tidioma;
          for(tidioma = DTIdiList.begin(); tidioma != DTIdiList.end(); tidioma++) {
               idiomaList.push_back(this->colIdiomas[(*tidioma)->getNombre()]);
          }
          this->ingresarProfesor(dynProf->getNickname(), dynProf->getNombre(), dynProf->getPass(), dynProf->getDesc(), dynProf->getInstituto(),idiomaList, cursosList);
     }
     else
          throw std::invalid_argument("ERROR:: El tipo de usuario no existe");
     
     delete dynEst;
     delete dynProf;
}


std::vector<string> ControladorUsuario::listarIdiomaDisp(){
     map<std::string, Idioma*>::iterator itermap;
     vector<string> res;  
     for(itermap = this->colIdiomas.begin(); itermap != this->colIdiomas.end(); itermap++) {
          res.push_back(itermap->first);
     }
     return res;
}
void ControladorUsuario::ingresarIdiomaSelec(std::vector<string> idiomas){ 
     vector<string>::iterator iterIdioma;
     vector<Idioma*> res;

     Idioma* idioma;
     for (iterIdioma = idiomas.begin(); iterIdioma != idiomas.end(); iterIdioma++) {
          idioma = this->colIdiomas[*iterIdioma];
          res.push_back(idioma);
     }
     string nombreProf = this->datoIngresadoEnSeleccionarProfesor;   
     Profesor* prof = dynamic_cast<Profesor*>(this->colUsuarios[nombreProf]);
     prof->AgregarIdioma(res);
     
}



std::vector<string> ControladorUsuario::listarEstudiantes(){
     std::map<string, Usuario*>::iterator iter;
     std::vector<string> res;

     for(iter = this->colUsuarios.begin(); iter != this->colUsuarios.end(); ++iter) {
          Estudiante* dynEst = dynamic_cast<Estudiante*>((iter)->second); //posible error en dynamic cast 
          if (dynEst != NULL) {
               res.push_back(dynEst->getNickname());
          }
     }
     return res;
}

std::vector<string> ControladorUsuario::listarProfesores(){
     std::map<string, Usuario*>::iterator iter;
     std::vector<string> res;

     for(iter = this->colUsuarios.begin(); iter != this->colUsuarios.end(); ++iter) {
          Profesor* dynProf = dynamic_cast<Profesor*>((iter)->second); //posible error en dynamic cast 
          if (dynProf != NULL) {
               res.push_back(dynProf->getNickname());
          }
     }
     return res;
}
std::vector<DTInfoCurso> ControladorUsuario::listarInfoEstudiantes(std::string nickname){
     std::map<string, Usuario*>::iterator iter;
     std::vector<DTInfoCurso> res;

     for(iter = this->colUsuarios.begin(); iter != this->colUsuarios.end(); ++iter) {
          Estudiante* dynEst = dynamic_cast<Estudiante*>((iter)->second); 
          if (dynEst != NULL) {
               if (dynEst->getNickname() == nickname) {
                    std::vector<Inscripcion*> inscripciones = dynEst->getInscripciones();
                    std::vector<Inscripcion*>::iterator iter2;
                    for (iter2 = inscripciones.begin(); iter2 != inscripciones.end(); ++iter2) {
                         float av = ((*iter2)->getAvance());
                         res.push_back((*iter2)->getDataCurso(av));
                    }

               }    
          }
     }
     return res;
}



void ControladorUsuario::seleccionarProfesor(string nickname) {
     this->datoIngresadoEnSeleccionarProfesor = nickname;
};

void ControladorUsuario::seleccionarEstudiante(string nickname) {
     this->datoIngresadoEnSeleccionarEstudiante = nickname;
};

map<std::string, Idioma*> ControladorUsuario::getcolIdiomas(){
     return this->colIdiomas;
}

map<std::string, DTUsuario *> ControladorUsuario::getcolUsuarios() {
  map<std::string, DTUsuario *> res;
  DTUsuario *DTusu;
  std::map<string, Usuario *>::iterator iter;
  for (iter = this->colUsuarios.begin(); iter != this->colUsuarios.end();++iter) {
    Estudiante *dynEst = dynamic_cast<Estudiante *>((iter)->second);
    Profesor *dynProf = dynamic_cast<Profesor *>((iter)->second);
    if (dynEst != NULL) {
      DTEstudiante *dynDTEst = new DTEstudiante(dynEst->getNickname(), dynEst->getNombre(), dynEst->getPass(),dynEst->getDesc(), dynEst->getPais(), dynEst->getFecha());
      DTusu = dynDTEst;
      res[dynEst->getNickname()] = DTusu;
    } 
    else{
          vector<DTIdioma*> listIdiomas;
          vector<Idioma*> idiomas = dynProf->getIdiomas();
          vector<Idioma*>::iterator it;
          for (it = idiomas.begin(); it != idiomas.end(); it++) {
               DTIdioma *DTI = new DTIdioma((*it)->getNombre());
               listIdiomas.push_back(DTI);
          }
          DTProfesor* dynDTProf = new DTProfesor(dynProf->getNickname(), dynProf->getNombre(), dynProf->getPass(),dynProf->getDesc(), dynProf->getInstituto(), listIdiomas);
          DTusu = dynDTProf;
          res[dynDTProf->getNickname()] = DTusu;
     }
  }

  return res;
}


bool ControladorUsuario::existeUsuario(string nickname) {
     bool res = false;
     if(this->colUsuarios.find(nickname) != this->colUsuarios.end())
          res = true;
     return res;
}


//andres
bool ControladorUsuario::esEstudiante(string nickname) {
     bool res = false;
     if(this->colUsuarios.find(nickname) != this->colUsuarios.end()){
          Estudiante* es = dynamic_cast<Estudiante*>(this->colUsuarios.find(nickname)->second); 
          if(es!=nullptr){
               res = true;
               }
     }    
     return res;
}
