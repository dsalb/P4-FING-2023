#include <string>

#ifndef DTEJERCICIO
#define DTEJERCICIO

using namespace std;

class DTEjercicio {

    private:
        string descripcion;
        string frase;
        int id;
        string tipoE;
    public:
        DTEjercicio();
        DTEjercicio(string descripcion, string frase, int id, string tipoE);

        string getDescripcion();
        string getFrase();
        int getId();
        string getTipoEjercicio();
        virtual ~DTEjercicio();

};

#endif