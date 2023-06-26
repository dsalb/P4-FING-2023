#include "IControladorCurso.h"
#include "IControladorUsuario.h"
#include "IFechaSistema.h"
#include "ControladorCurso.h"
#include "ControladorUsuario.h"
#include "FechaSistema.h"


#ifndef FABRICA
#define FABRICA

class Fabrica {
     private:
          // Constructor
          static Fabrica* instancia;
          Fabrica();
     
     
     public:
          // Funciones
          static Fabrica* getInstancia();
          IControladorUsuario* getInstanciaUsuario();
          IControladorCurso* getInstanciaCurso();
          IFechaSistema* getInstanciaFechaSis();
      
          // Destructor
		~Fabrica();
};

#endif
