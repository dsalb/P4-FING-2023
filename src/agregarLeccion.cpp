#include "../include/agregarLeccion.h"
#include "../include/DTEjercicio.h"
#include "../include/DTTraduccion.h"
#include "../include/DTCompletarPalabras.h"
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>

void agregarLeccion(){

    Fabrica* fabl = Fabrica::getInstancia();
    IControladorCurso* cc = fabl->getInstanciaCurso();
    string end;

    vector<string> ListCur = cc->listarCursosNoDisponibles();
    cout << "-- Cursos no habilitados en el sistema --" << endl << endl;
    vector<string>::iterator it;
    string selec;
    for (it = ListCur.begin(); it != ListCur.end(); it++) {
        cout << *it << endl;
    }
    cout << "Porfavor ingrese el curso al cual quiere ingresar una leccion: ";
    getline(cin >> ws, selec);

    string tema;
    cout << "Por favor, ingrese el tema de la leccion: ";
    getline(cin >> ws, tema);

    string objetivo;
    cout << "Por favor, ingrese el objetivo de la leccion: ";
    getline(cin >> ws, objetivo);

    int seleccion;
    cout << endl << "¿Desea agregar ejercicios a la leccion?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese la opción deseada: ";
    cin >> seleccion;
    vector<DTEjercicio*> colEje;
    if (seleccion == 1) {
        
        int selejer = 1;        
        while (selejer == 1){
            int contEjerc = 1;
            int tipo;
            cout << "Por favor, ingrese el Tipo de ejercicio:" << endl;
            cout << "1. Traduccion." << endl;
            cout << "2. Completar Palabras." << endl;
            cout << "Ingrese la opción deseada: ";
            cin >> tipo;

            string desc;
            cout << "Por favor, ingrese la descripcion del ejercicio: ";
            getline(cin >> ws, desc);   

            if (tipo == 1) {
                string frase;
                cout << "Por favor, ingrese la frase a traducir: ";
                getline(cin >> ws, frase);

                string solucion;
                cout << "Por favor, ingrese la frase ya traducida: ";
                getline(cin >> ws, solucion);

               
                DTTraduccion* dtTrad = new DTTraduccion(desc,  frase,  contEjerc, solucion);
                DTEjercicio* res = dtTrad;
                colEje.push_back(res);
            }
            else {
                string frase;
                cout << "Por favor, ingrese la frase a completar (recuerde que las palabras a completar se escriben como ""---""):" << endl;
                getline(cin >> ws, frase);

                string solucion;
                cout << "Por favor, ingrese las palabras de la solucion separadas por coma: ";
                getline(cin >> ws, solucion);
                
                vector<string> conPalabras;
                stringstream ss(solucion);

                string palabra;
                
                while(getline(ss, palabra, ',')) {
                    conPalabras.push_back(palabra);
                }

                DTCompletarPalabras* dtComple = new DTCompletarPalabras(desc,  frase,  contEjerc, conPalabras);
                DTEjercicio* res = dtComple;
                colEje.push_back(res);
            }
            cout << endl << "Desea agregar mas ejercicios a la leccion?" << endl;
            cout << "1. Si." << endl;
            cout << "2. No." << endl;
            cout << "Ingrese la opción deseada: ";
            cin >> selejer;
        }
    }

    int confirm;
    cout << endl << "Confirma el alta de la leccion?" << endl;
    cout << "1. Si." << endl;
    cout << "2. No." << endl;
    cout << "Ingrese la opción deseada: ";
    cin >> confirm;

    if (confirm == 1) {
        cc->seleccionarCurso(selec);
        cc->ingresoDatosLeccion(tema, objetivo);
        bool result = true;
        int index = cc->leccionesEnCurso(selec).size();
        cc->crearLeccion(result);
        cc->seleccionarLeccion(index);
        
        if (seleccion == 1) {
            vector<DTEjercicio*>::iterator itEjer;
            for (itEjer = colEje.begin(); itEjer != colEje.end(); itEjer++) {
                DTTraduccion* dynTrad = dynamic_cast<DTTraduccion*>(*itEjer);
                DTCompletarPalabras* dynCom = dynamic_cast<DTCompletarPalabras*>(*itEjer);

                if (dynTrad!=NULL) {
                    bool aux = true;
                    cc->altaEjercicioTraduccion(aux, dynTrad->getDescripcion(), dynTrad->getFrase(), dynTrad->getSolucion());
                }
                else if (dynCom!=NULL) {
                    bool aux = true;
                    cc->altaEjercicioCompletar(aux, dynCom->getDescripcion(), dynCom->getFrase(), dynCom->getSolucion());
                }
            }
        }
    }
    cout << endl << "Lección agregada de forma exitosa" << endl;
}
