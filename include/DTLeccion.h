#include <string>
#include <vector>
#include <ostream>
#include  "../include/DTEjercicio.h"
using namespace std;
#ifndef DTLECCION
#define DTLECCION






class DTLeccion{
    private:
        string tema;
        string objetivo;
        vector<DTEjercicio> colEj;
    public:
        DTLeccion(string tema, string obj,vector<DTEjercicio> colEj);

        string getTema();
        string getObjetivo();
        vector<DTEjercicio> getDataEjercicio();

        ~DTLeccion();
};

#endif