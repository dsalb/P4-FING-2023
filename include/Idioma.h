#include <string>
#include <map>

#include "Notificacion.h"
#include "IObserver.h"

using namespace std;

#ifndef IDIOMA
#define IDIOMA

using namespace std;

class Idioma {
    private:
        string nombre;
        map<string, IObserver*> colSuscriptores;
    public:
        Idioma(string nombre);

        void setNombre(string nombre);
        
        string getNombre();

        bool estaSuscripto(string nickname);
        void notificarSuscriptores(string curso, string idioma);
        int getCantidadSuscriptores();
        void suscribirse(IObserver* suscriptor);
        void eliminarSuscripcion(IObserver* suscriptor);

        ~Idioma();
};

#endif