#include "./include/IControladorCurso.h"
#include "./include/IControladorUsuario.h"
#include "./include/Fabrica.h"
#include "./include/cargaDatos.h"
#include "./include/AltaUsuario.h"
#include "./include/ConsultarUsuario.h"
#include "./include/altaIdioma.h"
#include "./include/consultarIdiomas.h"
#include "./include/altaCurso.h"
#include "./include/agregarLeccion.h"
#include "./include/agregarEjercicio.h"
#include "./include/habilitarCurso.h"
#include "./include/eliminarCurso.h"
#include "./include/consultaCurso.h"
#include "./include/inscribirseCurso.h"
#include "./include/realizarEjercicio.h"
#include "./include/consultarEstadisticas.h"
#include "./include/suscribirseANotificaciones.h"
#include "./include/consultaNotificaciones.h"
#include "./include/eliminarSuscripciones.h"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include "include/ControladorUsuario.h"
#include "include/ControladorCurso.h"

using namespace std;

bool datosCargados = false;

Fabrica* fab = Fabrica::getInstancia();
IControladorUsuario* iU = fab->getInstanciaUsuario();
IControladorCurso* iC = fab->getInstanciaCurso();
IFechaSistema* fechaSis = fab->getInstanciaFechaSis();

void fechaActual() {
        try {
        int d,m,a;
        cout << "-- ACTUALIZANDO FECHA DE SISTEMA --" << endl;
        cout << "Dia actual: ";
        cin >> d;
        cout << "Mes actual: ";
        cin >> m;
        cout << "Año actual: ";
        cin >> a;
        DTFecha fecha=DTFecha(d,m,a,0,0);
        fechaSis->ActualizarFechaSistema(fecha);
    }
     catch(const exception& e) {
          cout << e.what() << '\n';
     }
     

};

void limpiarConsola() {
    system("clear");
};


void menu () {
    
    cout << endl << "-- MENÚ PRINCIPAL --" << endl << endl;  

    cout << "0 - Cargar datos iniciales" << endl;
    cout << "1 - Alta de usuario" << endl; 
    cout << "2 - Consulta de usuario" << endl; 
    cout << "3 - Alta de idioma" << endl; 
    cout << "4 - Consultar idiomas" << endl; 
    cout << "5 - Alta de curso" << endl; 
    cout << "6 - Agregar lección" << endl; 
    cout << "7 - Agregar ejercicio" << endl; 
    cout << "8 - Habilitar curso" << endl; 
    cout << "9 - Eliminar curso" << endl; 
    cout << "10 - Consultar curso" << endl; 
    cout << "11 - Inscribirse a curso" << endl; 
    cout << "12 - Realizar ejercicio" << endl; 
    cout << "13 - Consultar estadísticas" << endl; 
    cout << "14 - Suscribirse a notificaciones" << endl; 
    cout << "15 - Consulta de notificaciones" << endl; 
    cout << "16 - Eliminar suscripciones" << endl; 
    cout << "17 - Salir" << endl << endl;

    cout << "Ingrese la opción deseada: ";

}

int main () {
    cout << "-- BIENVENIDO --" << endl << endl;
    cout << "Antes de comenzar por favor ingrese la fecha actual:" << endl;
    fechaActual();
    int usrCase;
    
    do {
        menu();
        cin >> usrCase;
        switch (usrCase) {
            case 0:
                if (!datosCargados) {
                  cargaDatos();  
                  datosCargados = true;
                } else {
                    cout << "ATENCION. Los datos ya se encuentran cargados en el sistema" << endl;
                }
                break;
            case 1:
                altaUsuario();
                break;
            case 2:
                consultarUsuario();
                break;
            case 3:
                altaIdioma();
                break;
            case 4:
                consultarIdiomas();
                break;
            case 5:
                altaCurso();
                break;
            case 6:
                agregarLeccion();
                break;
            case 7:
                agregarEjercicio();
                break;
            case 8:
                habilitarCurso();
                break;
            case 9:
                eliminarCurso();
                break;
            case 10:
                consultaCurso();
                break;
            case 11:
                inscribirseCurso();
                break;
            case 12:
                realizarEjercicio();
                break;
            case 13:
                consultarEstadisticas();
                break;
            case 14:
                suscribirseANotificaciones();
                break;
            case 15:
                consultaNotificaciones();
                break;
            case 16:
                eliminarSuscripciones();
                break;
            case 17:
                break;            
            default:
                cout << "No es una opción válida, seleccione nuevamente." << endl;
                break;
        }

    } while (usrCase != 17);

    return 0;
};