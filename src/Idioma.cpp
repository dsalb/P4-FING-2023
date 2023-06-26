#include <string>
#include <set>
#include <map>
#include "../include/Idioma.h"
#include "../include/Notificacion.h"
#include "../include/IObserver.h"
#include "../include/DTNotificaciones.h"
#include "../include/Usuario.h"
#include "../include/Profesor.h"
#include "../include/Estudiante.h"

using namespace std;

Idioma::Idioma(string nombre) {
    this->nombre = nombre;
}

void Idioma::notificarSuscriptores(string curso, string idioma) {
    int contador = getCantidadSuscriptores();
    Notificacion* noti = new Notificacion(idioma, curso, contador);
    map<string, IObserver*>::iterator it;
    for(it = colSuscriptores.begin(); it != colSuscriptores.end(); ++it)
        it->second->notificar(noti);
}

void Idioma::setNombre(string nombre) {
    this->nombre = nombre;
}

string Idioma::getNombre() {
    return nombre;
}

bool Idioma::estaSuscripto(string nickname) {
    map<string, IObserver*>::iterator it;
    bool res = false;
    for(it = colSuscriptores.begin(); it != colSuscriptores.end(); ++it)
        if(it->first == nickname)
            res = true;
    return res;
}

int Idioma::getCantidadSuscriptores() {
    return colSuscriptores.size();
}

void Idioma::suscribirse(IObserver* suscriptor) {
    if (Profesor* p = dynamic_cast<Profesor*>(suscriptor))
        this->colSuscriptores.insert(make_pair(p->getNickname(), suscriptor));
    else {
        Estudiante* e = dynamic_cast<Estudiante*>(suscriptor);
        this->colSuscriptores.insert(make_pair(e->getNickname(), suscriptor));
    }
}

void Idioma::eliminarSuscripcion(IObserver* suscriptor) {
    if (Profesor* p = dynamic_cast<Profesor*>(suscriptor))
        this->colSuscriptores.erase(p->getNickname());
    else {
        Estudiante* e = dynamic_cast<Estudiante*>(suscriptor);
        this->colSuscriptores.erase(e->getNickname());
    }
}

Idioma::~Idioma(){
}