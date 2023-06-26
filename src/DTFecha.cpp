#include "../include/DTFecha.h"

DTFecha::DTFecha() {}
DTFecha::DTFecha(int dia, int mes, int anio, int hora, int minuto){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}
DTFecha::~DTFecha() {}


//Getters

int DTFecha::getDia() {
    return dia;
}
int DTFecha::getMes() {
    return mes;
}
int DTFecha::getAnio() {
    return anio;
}
int DTFecha::getHora() {
    return hora;
}
int DTFecha::getMinuto() {
    return minuto;
}

int DTFecha::comparacion(DTFecha f) {
    if (this->anio > f.anio) {
        return 1;
    } else if (this->anio < f.anio) {
        return -1;
    } else if (this->mes > f.mes) {
        return 1;
    } else if (this->mes < f.mes) {
        return -1;
    } else if (this->dia > f.dia) {
        return 1;
    } else if (this->dia < f.dia) {
        return -1;
    } else if (this->hora > f.hora) {
        return 1;
    } else if (this->hora < f.hora) {
        return -1;
    } else {
        return 0;
    }
}

// Operadores
bool DTFecha::operator==(DTFecha f) {
    return this->comparacion(f) == 0;
}
bool DTFecha::operator!=(DTFecha f) {
    return this->comparacion(f) != 0;
}
bool DTFecha::operator<(DTFecha f) {
    return this->comparacion(f) == -1;
}
bool DTFecha::operator>(DTFecha f) {
    return this->comparacion(f) == 1;
}
bool DTFecha::operator<=(DTFecha f) {
    return this->comparacion(f) <= 0;
}
bool DTFecha::operator>=(DTFecha f) {
    return this->comparacion(f) >= 0;
}