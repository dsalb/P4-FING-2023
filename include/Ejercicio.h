#include <string>
#include "DTEjercicio.h"

#ifndef EJERCICIO
#define EJERCICIO

using namespace std;

class Ejercicio {

    private:
    string descripcion;
    string frase;
    int id;

    public:
    Ejercicio(string descripcion, string frase, int id);

    void setDescripcion(string desc);
    void setFrase(string frase);
    void setId(int id);
    string getDescripcion();
    string getFrase();
    int getId();

    DTEjercicio createDT();

    virtual ~Ejercicio() = 0;

};

#endif