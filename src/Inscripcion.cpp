#include "../include/Inscripcion.h"
#include "../include/Curso.h"
#include "../include/Estudiante.h"
#include <algorithm>

Inscripcion::Inscripcion(DTFecha fechaIns, bool aprobado, int indiceLecAct, vector<Ejercicio*> ejAprobados, Curso* curso, Estudiante* estudiante) {
    this->fechaIns = fechaIns;
    this->aprobado = aprobado;
    this->indiceLecAct = indiceLecAct;
    this->ejAprobados = ejAprobados;
    this->curso = curso;
    this->estudiante = estudiante;
};

void Inscripcion::setAprobado(bool aprobado) {
    this->aprobado = aprobado;
};

void Inscripcion::setIndiceLecAct(int indice) {
    this->indiceLecAct = indice;
};

void Inscripcion::setEjAprobados(vector<Ejercicio*> ejAprobados) {
    this->ejAprobados = ejAprobados;
};

DTFecha Inscripcion::getFechaIns() {
    return this->fechaIns;
};

bool Inscripcion::getAprobado() {
    return this->aprobado;
};

int Inscripcion::getIndiceLecAct() {
    return this->indiceLecAct;
};

vector<Ejercicio*> Inscripcion::getEjAprobados() {
    return this->ejAprobados;
};

Curso* Inscripcion::getCurso() {
    return this->curso;
};

Estudiante* Inscripcion::getEstudiante() {
    return this->estudiante;
};

Inscripcion::~Inscripcion() {};

//MÉTODOS CONTROLADORES
string Inscripcion::getNombreCurso() {
    return this->curso->getNombre();
};

bool Inscripcion::existeCurso(string curso) {
    if (this->curso != nullptr && this->curso->getNombre() == curso) {
        return true;
    }
    return false;

};

vector<DTEjercicio> Inscripcion::ejerciciosNoAprobados() {
    vector<DTEjercicio> resp;
    map<int, Ejercicio*> ejLecc = this->curso->darEjerciciosLec(this->indiceLecAct);
    map<int, Ejercicio*>::iterator it;
    for (it = ejLecc.begin(); it != ejLecc.end(); ++it) {
        if (find(this->ejAprobados.begin(), this->ejAprobados.end(), it->second) == this->ejAprobados.end()) {
            resp.push_back(it->second->createDT());
        }
    }
    return resp;
};

bool Inscripcion::verificarSolT(string resp, int ejerId) {
    bool ret = true;
    Ejercicio* ej = this->curso->buscarEjercicioEnLec(ejerId, this->indiceLecAct);
    Traduccion* tEj = dynamic_cast<Traduccion*>(ej);
    string sol = tEj->getSolucion();
    if (resp != sol) {
        ret = false;
    }
    if (ret == true) {
        Ejercicio* ejPtr = ej;
        vector<Ejercicio*> nuevoAprobado = this->getEjAprobados();
        nuevoAprobado.push_back(ejPtr);
        this->setEjAprobados(nuevoAprobado);
        if (this->getAvance() == 100) {
            this->setAprobado(true);
        }
        if ((this->ejerciciosNoAprobados().size() == 0) && (this->getAvance() != 100)) {
            this->indiceLecAct = this->indiceLecAct + 1;
        }
    }

    return ret;

};

bool Inscripcion::verificarSolCP(vector<string> resp, int ejerId) {
    bool ret = true;
    Ejercicio* ej = this->curso->buscarEjercicioEnLec(ejerId, this->indiceLecAct);
    CompletarPalabras* cpEj = dynamic_cast<CompletarPalabras*>(ej);
    vector<string> sol = cpEj->getSolucion();
    vector<string>::iterator it;
    vector<string>::iterator solIt = sol.begin();
    for (it = resp.begin(); it != resp.end(); ++it) {
        if (*it != *solIt) {
            ret = false;
        }
        ++solIt;
    }
    if (ret == true) {
        Ejercicio* ejPtr = ej;
        vector<Ejercicio*> nuevoAprobado = this->getEjAprobados();
        nuevoAprobado.push_back(ejPtr);
        this->setEjAprobados(nuevoAprobado);
        if (this->getAvance() == 100) {
            this->setAprobado(true);
        }
        if ((this->ejerciciosNoAprobados().size() == 0) && (this->getAvance() != 100)) {
            this->indiceLecAct = this->indiceLecAct + 1;
        }
    }

    return ret;
};

float Inscripcion::getAvance() {
    float ejTot = this->curso->getCantidadEj();
    float ejApr = this->ejAprobados.size();
    return ((ejApr/ejTot)*100);
};

DTInfoCurso Inscripcion::getDataCurso(float av) {
    return DTInfoCurso(this->curso->getNombre(), av, this->curso->getDificultad());
};
