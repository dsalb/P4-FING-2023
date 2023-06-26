#include <string>
#include "DTNotificaciones.h"

#ifndef NOTIFICACION
#define NOTIFICACION

using namespace std;

class Notificacion {

    private:
        string idioma;
        string curso;
        int contador;

    public:
        Notificacion(string idioma, string curso, int contador);
        
        void setContador(int contador);

        string getIdioma();
        string getCurso();
        int getContador();

        void modificarContador();
        DTNotificaciones crearDT();

        ~Notificacion();
};

#endif