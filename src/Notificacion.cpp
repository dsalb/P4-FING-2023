#include <string>
#include "../include/Idioma.h"
#include "../include/Notificacion.h"
#include "../include/DTNotificaciones.h"
#include "../include/IObserver.h"

using namespace std;

class DTNotificaciones;

Notificacion::Notificacion(string idioma, string curso, int contador) {
    this->idioma = idioma;
    this->curso = curso;
    this->contador = contador;
}

void Notificacion::setContador(int contador) {
    this->contador = contador;
}

string Notificacion::getIdioma() {
    return this->idioma;
}

string Notificacion::getCurso() {
    return this->curso;
}

int Notificacion::getContador() {
    return contador;
}

DTNotificaciones Notificacion::crearDT() {
    return DTNotificaciones(this->idioma, this->curso);
}

void Notificacion::modificarContador() {
    contador--;
    if (contador == 0)
        delete this;
}

Notificacion::~Notificacion() {
}