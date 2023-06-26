#include <string>
#include <vector>
#include <ostream>
#include  "../include/DTEjercicio.h"
using namespace std;
#ifndef DTLECCIONINT
#define DTLECCIONINT 

class DTLeccionInt{
    private:
        std::string tema;
        std::string objetivo;
        int indice;
        vector<DTEjercicio> colEj;
    public:
        DTLeccionInt(std::string tema, std::string obj,int indice, vector<DTEjercicio> colEj);

        std::string getTema();
        std::string getObjetivo();
        int getIndice();
        vector<DTEjercicio> getDataEjercicio();

        ~DTLeccionInt();
};

#endif