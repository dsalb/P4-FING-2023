#include <string>
#include "Ejercicio.h"
#include <iostream>
#include <map>
#include <vector>
#include "DTLeccion.h"
#include "CompletarPalabras.h"
#include "Traduccion.h"

#ifndef LECCION
#define LECCION

using namespace std;

class Leccion {
    private:
        string tema;
        string objetivo;
        int indice;
        map<int, Ejercicio*> colEjercicios;
    public:   
        Leccion(string tema, string objetivo, int indice, map<int, Ejercicio*> colEj);

        void setTema(string tema);
        void setObjetivo(string objetivo);

        string getTema();
        string getObjetivo();
        int getIndice();
        int cantEjercicios();
        map<int, Ejercicio*> getEjercicios();
        
        DTLeccion getDataLeccion();
        Ejercicio* buscarEjercicio(int idEjer);
        
        void agregarEjerT(string descripcion, string frase, string solucion);
        void agregarEjerC(string descripcion, string frase, vector<string> solucion);
        
        ~Leccion();

};

#endif
