#ifndef DTTRADUCCION_HPP
#define DTTRADUCCION_HPP

#include <string>
#include <vector>
#include "DTEjercicio.h"
using namespace std;

class DTTraduccion : public DTEjercicio {
    private: 
        std::string solucion;
    public:
    DTTraduccion();
    DTTraduccion(string descripcion, string frase, int id, string solucion);
    ~DTTraduccion();
    
    string getSolucion();


};
#endif