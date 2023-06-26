#include <string>
#include <map>
#include "Idioma.h"

using namespace std;

#ifndef DTIDIOMA
#define DTIDIOMA


class DTIdioma {
    private:
        std::string nombre;
    public:
        DTIdioma();
        DTIdioma(std::string nombre);

        std::string getNombre();
        
        ~DTIdioma();
};

#endif