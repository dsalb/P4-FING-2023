#include <vector>

#include "Notificacion.h"
#include "DTNotificaciones.h"

#ifndef IOBSERVER
#define IOBSERVER

using namespace std;

class IObserver {
    public:
        virtual void notificar(Notificacion* notificacion) = 0;
        virtual vector<DTNotificaciones> consultarNotificaciones() = 0;
};

#endif