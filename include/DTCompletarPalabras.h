#ifndef DTCOMPLETARPALABRAS_HPP
#define DTCOMPLETARPALABRAS_HPP

#include <string>
#include <vector>
#include "DTEjercicio.h"
using namespace std;

class DTCompletarPalabras : public DTEjercicio {
    private: 
        vector<string> solucion;
    public:
    DTCompletarPalabras();
    DTCompletarPalabras(string descripcion, string frase, int id, vector<string> solucion);
    ~DTCompletarPalabras();
    
    vector<string> getSolucion();


};
#endif