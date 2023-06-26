#include "../include/altaIdioma.h"
#include "../include/Fabrica.h"
#include <iostream> 

using namespace std;



void altaIdioma(){
    Fabrica* faba = Fabrica::getInstancia();
    IControladorUsuario* iU = faba->getInstanciaUsuario();
    string nombreIdiomaIngresado;
    bool cond;

    //Ingreso del Idioma
    cout << "Ingrese un Idioma: ";
    getline(cin >> ws, nombreIdiomaIngresado);
    //Alta
    cond = iU->altaIdioma(nombreIdiomaIngresado);

    //Comprobacion
    if(cond)
        cout << "Se ha creado correctamente un Idioma con nombre " << nombreIdiomaIngresado <<"."<< endl;
    else{
        cout << "Ya existe un Idioma con nombre "<<nombreIdiomaIngresado<<" en el sistema." << endl;
    }

}