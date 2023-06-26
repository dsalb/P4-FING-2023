#include <string>
#include "Ejercicio.h"

#ifndef TRADUCCION
#define TRADUCCION

class Traduccion: public Ejercicio {

    private:
    string solucion;

    public:
    Traduccion(string descripcion, string frase, int id, string solucion);

    void setSolucion(string solucion);

    string getSolucion();

    ~Traduccion();

};

#endif