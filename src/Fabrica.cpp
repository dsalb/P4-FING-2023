#include "../include/Fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){};

Fabrica* Fabrica::getInstancia()
{
     if (instancia == NULL)
          instancia = new Fabrica();
     return instancia;
};

IControladorUsuario* Fabrica::getInstanciaUsuario(){
     return ControladorUsuario::getInstancia();
};
IControladorCurso* Fabrica::getInstanciaCurso(){
     return ControladorCurso::getInstancia();
};
IFechaSistema* Fabrica::getInstanciaFechaSis(){
     return FechaSistema::getInstancia();
};


Fabrica::~Fabrica(){};