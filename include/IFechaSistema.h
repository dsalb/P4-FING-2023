#include "DTFecha.h"

#ifndef IFECHASISTEMA
#define IFECHASISTEMA

using namespace std;

class IFechaSistema {
     public:

          virtual DTFecha getFechaSistema() = 0;
          virtual void ActualizarFechaSistema(DTFecha) = 0;
          
};

#endif