#include <string>
#include <vector>
#include "Ejercicio.h"

#ifndef COMPLETARPALABRAS
#define COMPLETARPALABRAS

class CompletarPalabras: public Ejercicio {

    private:
    vector<string> solucion;

    public:
    CompletarPalabras(string descripcion, string frase, int id, vector<string> solucion);

    void setSolucion(vector<string> solucion);

    vector<string> getSolucion();

    ~CompletarPalabras();

};

#endif