#include "../include/ControladorCurso.h"
#include "../include/Fabrica.h"
#include <iostream>
#include <sstream>

using namespace std;
Fabrica* fabr = Fabrica::getInstancia();
IControladorCurso* iCurso = fabr->getInstanciaCurso();
IControladorUsuario* iUsuario = fabr->getInstanciaUsuario();
void realizarEjercicio() { 
//Ingresar Nickname
    cout << "Por favor, ingrese su nickname: ";
    string nickname;
    getline(cin >> ws, nickname);
    iCurso->ingresarNick(nickname);
    //realizar elif de control y op control nickname
    if(iUsuario->esEstudiante(nickname)) {
        vector<string> lCurso=iCurso->listarCursosInscriptoEstudiante(nickname);
        vector<string>::iterator it;
        cout << "-- Cursos inscripto --" << endl;
        bool flagPendientes = false;
        for (it=lCurso.begin();it!=lCurso.end();++it){
        if(!(iCurso->cursoAprobado((*it),nickname) )){
                cout << "  * " << (*it) << endl;
                flagPendientes = true;
        }
        }
        if (!flagPendientes) {
            cout << "El estudiante no tiene ejercicios pendientes" << endl;
            return;
        }
        bool res=false;
        //Elegir Curso
        cout << "Seleccione un curso: ";
        string selecCurso;
        getline(cin >> ws, selecCurso);
        iCurso->seleccionarCurso(selecCurso);
        //Buscar curso
        if(iCurso->existeCurso(selecCurso)){
            vector<DTEjercicio> colEj =iCurso->listarEjerciciosNoAprobadosCursos(selecCurso, nickname);
            vector<DTEjercicio>::iterator e;
            for (e=colEj.begin();e!=colEj.end();++e){
                    cout << "-- Ejercicios sin realizar --" << endl;
                    if(!colEj.empty()){
                        cout << "  * " << e->getId()<<":"<<e->getDescripcion() << "\n";
                    }
                }
            //Elejir ejercicio
            cout << "Selecione un ejercicio: " <<endl;
            int selecEjercicio;
            cin >>selecEjercicio;
            // buscar ejercicio
            DTEjercicio ej = iCurso->realizarEj(selecEjercicio,selecCurso, nickname);
            cout << "-- Ejercicio a realizar --" << endl;
            cout << "Frase del ejercicio: " <<ej.getFrase() <<endl;
            // solucion del ejercicio      
            
            if(ej.getTipoEjercicio() == "traduccion"){
                cout << "-- Ingrese  su respuesta --" << endl;
                //ejercicio Taduccion
                string solEj;
                getline(cin >> ws, solEj);
                res =iCurso->verificarSolucionTraduccion(solEj, selecCurso, selecEjercicio);
            }else{
                cout << "-- Ingrese separada por una coma cada palabra de su respuesta --" << endl;
                //ejercicio completar palabra
                //cargar vector de entrada
                string solEj;
                getline(cin >> ws, solEj);
                vector<string> solEje;
                stringstream ss(solEj);
                while (ss.good()) {
                        string k;
                        getline(ss,k,',');
                        solEje.push_back(k);
                } 
            
                res= iCurso->verificarSolucionCompletarPalabra(solEje, selecCurso, selecEjercicio);
            }
            if (res) {
                cout <<"Ejercicio Aprobado "<< endl;
            } else {
                cout <<"Ejercicio No Aprobado " << endl;
            }


        } else {cout <<"No existe el curso "<<selecCurso << endl; }

    } else {
        cout << "No existe registro en el sistema del nickname " << nickname << endl;
    }
        
}