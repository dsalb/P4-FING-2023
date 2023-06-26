#include <string>
#include<ostream>
using namespace std;

#ifndef DTNOTIFICACIONES
#define DTNOTIFICACIONES

class DTNotificaciones {
    private:
        string idioma;
        string curso;
    public:
        DTNotificaciones(string idioma, string curso);
        string getNombreIdioma();
        string getNombreCurso();    
        ~DTNotificaciones();
};
#endif