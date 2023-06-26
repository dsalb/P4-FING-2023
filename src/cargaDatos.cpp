#include "../include/IControladorUsuario.h"
#include "../include/IControladorCurso.h"
#include "../include/Fabrica.h"
#include "../include/DTFecha.h"
#include "../include/cargaDatos.h"

#include <iostream>
#include <unistd.h> 

using namespace std;

void cargaDatos() {

    try {

        ControladorCurso* ICur = ControladorCurso::getInstancia();
        ControladorUsuario* IUsu = ControladorUsuario::getInstancia();

        // FECHAS
        DTFecha fechNacU1 =  DTFecha(15,7,1995,0,0);
        DTFecha fechNacU2 =  DTFecha(28,2,1998,0,0);
        DTFecha fechNacU3 =  DTFecha(10,11,1994,0,0);
        DTFecha fechNacU4 =  DTFecha(22,4,1997,0,0);
        DTFecha fechNacU5 =  DTFecha(3,9,1996,0,0);
        DTFecha fechNacU6 =  DTFecha(12,1,1999,0,0);
        DTFecha fechNacU7 =  DTFecha(25,6,1993,0,0);
        DTFecha fechNacU8 =  DTFecha(8,12,1997,0,0);
        DTFecha fechNacU9 =  DTFecha(17,3,1995,0,0);
        DTFecha fechNacU10 =  DTFecha(2,8,1998,0,0);

        DTFecha fechIns1 =  DTFecha(1,1,2022,0,0);
        DTFecha fechIns2 =  DTFecha(12,6,2022,0,0);
        DTFecha fechIns3 =  DTFecha(2,3,2023,0,0);
        DTFecha fechIns4 =  DTFecha(2,1,2022,0,0);
        DTFecha fechIns5 =  DTFecha(2,1,2022,0,0);
        DTFecha fechIns6 =  DTFecha(3,1,2023,0,0);
        DTFecha fechIns7 =  DTFecha(3,1,2023,0,0);
        DTFecha fechIns8 =  DTFecha(5,1,2023,0,0);

        // IDIOMAS

        IUsu->altaIdioma("Ingles"); // I1
        IUsu->altaIdioma("Aleman"); // I2
        IUsu->altaIdioma("Portugues"); // I3

        IUsu->seleccionarIdioma("Ingles");
        Idioma* I1 = IUsu->obtenerIdioma();

        IUsu->seleccionarIdioma("Aleman");
        Idioma* I2 = IUsu->obtenerIdioma();

        IUsu->seleccionarIdioma("Portugues");
        Idioma* I3 = IUsu->obtenerIdioma();

        
        // PROFESORES
        vector<Curso*> curU11;
        vector<Curso*> curU12;
        vector<Curso*> curU13;
        vector<Curso*> curU14;
        vector<Curso*> curU15;

        vector<Idioma*> idU11;
        vector<Idioma*> idU12;
        vector<Idioma*> idU13;
        vector<Idioma*> idU14;
        vector<Idioma*> idU15;


        idU11.push_back(I1);
        idU12.push_back(I1);
        idU15.push_back(I1);

        idU12.push_back(I2);
        idU13.push_back(I2);

        idU11.push_back(I3);
        idU12.push_back(I3);
        idU14.push_back(I3);


        IUsu->ingresarProfesor("langMaster", "Marta Grecia", "P4s512", "Soy una profesora apasionada por los idiomas.", "Instituto de Idiomas Moderno", idU11, curU11); // U11
        IUsu->ingresarProfesor("linguaPro", "Carlos Petro", "Pess23", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", "Centro Global", idU12, curU12); // U12
        IUsu->ingresarProfesor("talkExpert", "Laura Perez","Secret1", "Soy una profesora entusiasta del aprendizaje de idiomas","Instituto de Idiomas Vanguardia", idU13, curU13); // U13
        IUsu->ingresarProfesor("lingoSensei", "Franco Lopez", "Secure2", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", "Centro de Idiomas", idU14, curU14); // U14
        IUsu->ingresarProfesor("wordMaestro", "Ana Morales", "Passw0", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas", "Instituto de Idiomas Progreso", idU15, curU15); // U15

        IUsu->seleccionarProfesor("langMaster");
        Profesor* U11 = IUsu->obtenerProfesor();
        
        IUsu->seleccionarProfesor("linguaPro");
        Profesor* U12 = IUsu->obtenerProfesor();

        IUsu->seleccionarProfesor("lingoSensei");
        Profesor* U14 = IUsu->obtenerProfesor();


        // EJERCICIOS
        vector<string> ejCP2;
        ejCP2.push_back("allow");
        ejCP2.push_back("myself");
        vector<string> ejCP4;
        ejCP4.push_back("some");
        vector<string> ejCP5;
        ejCP5.push_back("up");
        vector<string> ejCP6;
        ejCP6.push_back("have");
        ejCP6.push_back("past");

        Ejercicio* ej1 = new Traduccion("Presentaciones", "Mucho gusto en conocerte", 0, "Nice to meet you"); // E1
        Ejercicio* ej2 = new CompletarPalabras("Presentaciones formales", "Please — me to introduce —", 1, ejCP2); // E2
        Ejercicio* ej3 = new Traduccion("Plurales regulares", "I have two brothers and three sisters", 0, "Tengo dos hermanos y tres hermanas"); // E3
        Ejercicio* ej4 = new CompletarPalabras("Sustantivos contables en plural", "Can I have --- water, please?", 1, ejCP4); // E4
        Ejercicio* ej5 = new CompletarPalabras("Actividades diarias", "Wake ---", 0, ejCP5); // E5
        Ejercicio* ej6 = new CompletarPalabras("Consultas de la hora", "Q: Do you --- the time?, A: Yes, it is half --- 4", 0, ejCP6); // E6
        Ejercicio *ej7 = new Traduccion("Dar consejos o expresar obligacion", "You should visit that museum", 0, "Deberias visitar ese museo"); // E7
        Ejercicio* ej8 = new Traduccion("Imperativo", "Fale comigo", 0, "Habla conmigo"); // E8


        // LECCIONES
        map<int, Ejercicio*> ejLecc1;
        ejLecc1[0] = ej1;
        ejLecc1[1] = ej2;
        map<int, Ejercicio*> ejLecc2;
        ejLecc2[0] = ej3;
        ejLecc2[1] = ej4;
        map<int, Ejercicio*> ejLecc3;
        ejLecc3[0] = ej5;
        map<int, Ejercicio*> ejLecc4;
        map<int, Ejercicio*> ejLecc5;
        ejLecc5[0] = ej6;
        map<int, Ejercicio*> ejLecc6;
        ejLecc6[0] = ej7;
        map<int, Ejercicio*> ejLecc7;
        ejLecc7[0] = ej8;

        Leccion* lecc1 = new Leccion("Saludos y Presentaciones", "Aprender a saludar y despedirse", 0, ejLecc1); // L1
        Leccion* lecc2 = new Leccion("Artículos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", 1, ejLecc2); // L2
        Leccion* lecc3 = new Leccion("Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", 0, ejLecc3); // L3
        Leccion* lecc4 = new Leccion("Presente Simple", "Aprender el uso del presente simple", 1, ejLecc4); // L4
        Leccion* lecc5 = new Leccion("Conversaciones cotidianas", "Aprender a hacer preguntas yrespuestas en situaciones comunes", 0, ejLecc5); // L5
        Leccion* lecc6 = new Leccion("Uso de modales avanzados", "Explorar el uso de los modales complejos", 0, ejLecc6); // L6
        Leccion* lecc7 = new Leccion("Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas", 0, ejLecc7); // L7

        // CURSOS y PREVIAS

        map<int, Leccion*> leccC1;
        leccC1[0] = lecc1;
        leccC1[1] = lecc2;
        map<int, Leccion*> leccC2;
        leccC2[0] = lecc3;
        leccC2[1] = lecc4;
        map<int, Leccion*> leccC3;
        leccC3[0] = lecc5;
        map<int, Leccion*> leccC4;
        leccC4[0] = lecc6;
        map<int, Leccion*> leccC5;
        leccC5[0] = lecc7;
        map<int, Leccion*> leccC6;

        vector<Inscripcion*> inscrC1;
        vector<Inscripcion*> inscrC2;
        vector<Inscripcion*> inscrC3;
        vector<Inscripcion*> inscrC4;
        vector<Inscripcion*> inscrC5;
        vector<Inscripcion*> inscrC6;

        vector<Curso*> prevC1;
        Curso* curso1 = new Curso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion", Principiante, true, U11, inscrC1, leccC1, prevC1, I1);
        U11->agregarCurso(curso1);

        vector<Curso*> prevC2;
        Curso* curso2 = new Curso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral", Principiante, false, U11, inscrC2, leccC2, prevC2, I1);
        U11->agregarCurso(curso2);

        vector<Curso*> prevC3;
        prevC3.push_back(curso1);
        Curso* curso3 = new Curso("Ingles intermedio:mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura", Medio, true, U12, inscrC3, leccC3, prevC3, I1);
        U12->agregarCurso(curso3);

        vector<Curso*> prevC4;
        prevC4.push_back(curso1);
        prevC4.push_back(curso3);
        Curso* curso4 = new Curso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva", Avanzado, true, U12, inscrC4, leccC4, prevC4, I1);
        U12->agregarCurso(curso4);

        vector<Curso*> prevC5;
        Curso* curso5 = new Curso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva", Medio, true, U12, inscrC5, leccC5, prevC5, I3);
        U12->agregarCurso(curso5);

        vector<Curso*> prevC6;
        prevC4.push_back(curso5);
        Curso* curso6 = new Curso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral", Avanzado, false, U14, inscrC6, leccC6, prevC6, I3);
        U14->agregarCurso(curso6);

         map<string, Curso*> colCursoDatos;
         colCursoDatos["Ingles para principiantes"] = curso1;
         colCursoDatos["Curso de ingles basico"] = curso2;
         colCursoDatos["Ingles intermedio:mejora tu nivel"] = curso3;
         colCursoDatos["Curso avanzado de ingles"] = curso4;
         colCursoDatos["Portugues intermedio"] = curso5;
         colCursoDatos["Portugues avanzado"] = curso6;
         ICur->cargaColInicial(colCursoDatos);
         




        // ESTUDIANTES
        vector<Inscripcion*> insU1;
        vector<Inscripcion*> insU2;
        vector<Inscripcion*> insU3;
        vector<Inscripcion*> insU4;
        vector<Inscripcion*> insU5;
        vector<Inscripcion*> insU6;
        vector<Inscripcion*> insU7;
        vector<Inscripcion*> insU8;
        vector<Inscripcion*> insU9;
        vector<Inscripcion*> insU10;

        IUsu->ingresarEstudiante("jpidiom", "Juan Perez", "asdfg123", "Soy un apasionado del aprendizaje de idiomas.", "Argentina", fechNacU1, insU1); // U1
        IUsu->ingresarEstudiante("marsilva", "Maria Silva", "qwer456", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", "Ecuador", fechNacU2, insU2); // U2
        IUsu->ingresarEstudiante("pero12", "Pedro Rodriguez", "789werty", "Soy un entusiasta del aprendizaje de idiomas", "Peru", fechNacU3, insU3); // U3
        IUsu->ingresarEstudiante("laugu", "Laura Gutierrez", "c1v2b3m4", "Estoy fascinada por la forma en que las palabras pueden unir a las personas", "Chile", fechNacU4, insU4); // U4
        IUsu->ingresarEstudiante("carlo22", "Carlos Lopez", "tyuipz147", "Emocionado por adquirir fluidez en diferentes lenguas.", "Uruguay", fechNacU5, insU5); // U5
        IUsu->ingresarEstudiante("anator", "Ana Torres", "1qsxc36", "Disfruto de la belleza de las diferentes estructuras y sonidos.", "Argentina", fechNacU6, insU6); // U6
        IUsu->ingresarEstudiante("luher24", "Lucia Hernandez", "t7h8y5u6", "Emocionada en la riqueza cultural que cada idioma ofrece.", "Colombia", fechNacU7, insU7);// U7
        IUsu->ingresarEstudiante("dagon", "David Gonzalez", "1w2e3r4t5", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", "Uruguay", fechNacU8, insU8); // U8
        IUsu->ingresarEstudiante("carmor", "Carmen Morales", "6yu7i8m9", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", "Chile", fechNacU9, insU9); // U9
        IUsu->ingresarEstudiante("jose24", "Jose Fernandez", "qwj789p", "Disfruto del proceso de descubrir nuevas formas de comunicarme", "Bolivia", fechNacU10, insU10); // U10

        IUsu->seleccionarEstudiante("jpidiom");
        Estudiante* U1 = IUsu->obtenerEstudiante();
        IUsu->seleccionarEstudiante("marsilva");
        Estudiante* U2 = IUsu->obtenerEstudiante();
        IUsu->seleccionarEstudiante("pero12");
        Estudiante* U3 = IUsu->obtenerEstudiante();
        IUsu->seleccionarEstudiante("laugu");
        Estudiante* U4 = IUsu->obtenerEstudiante();
        IUsu->seleccionarEstudiante("carlo22");
        Estudiante* U5 = IUsu->obtenerEstudiante();
        IUsu->seleccionarEstudiante("anator");
                
        
        // INSCRPCIONES
        vector<Ejercicio*> ejInsc1;
        ejInsc1.push_back(ej1);
        ejInsc1.push_back(ej2);
        ejInsc1.push_back(ej3);
        ejInsc1.push_back(ej4);
        vector<Ejercicio*> ejInsc2;
        ejInsc2.push_back(ej6);
        vector<Ejercicio*> ejInsc3;
        vector<Ejercicio*> ejInsc4;
        ejInsc4.push_back(ej1);
        ejInsc4.push_back(ej2);
        vector<Ejercicio*> ejInsc5;
        ejInsc5.push_back(ej1);
        ejInsc5.push_back(ej2);
        ejInsc5.push_back(ej4);
        vector<Ejercicio*> ejInsc6;
        vector<Ejercicio*> ejInsc7;
        vector<Ejercicio*> ejInsc8;

        Inscripcion* insc1 = new Inscripcion(fechIns1, true, 1, ejInsc1, curso1, U1);
        U1->agregarInscripcion(insc1);
        curso1->agregarInscripcion(insc1);
        Inscripcion* insc2 = new Inscripcion(fechIns2, true, 0, ejInsc2, curso3, U1);
        U1->agregarInscripcion(insc2);
        curso3->agregarInscripcion(insc2);
        Inscripcion* insc3 = new Inscripcion(fechIns3, false, 0, ejInsc3, curso4, U1);
        U1->agregarInscripcion(insc3);
        curso4->agregarInscripcion(insc3);
        Inscripcion* insc4 = new Inscripcion(fechIns4, false, 1, ejInsc4, curso1, U2);
        U2->agregarInscripcion(insc4);
        curso1->agregarInscripcion(insc4);
        Inscripcion* insc5 = new Inscripcion(fechIns5, false, 1, ejInsc5, curso1, U3);
        U3->agregarInscripcion(insc5);
        curso1->agregarInscripcion(insc5);
        Inscripcion* insc6 = new Inscripcion(fechIns6, false, 0, ejInsc6, curso1, U4);
        U4->agregarInscripcion(insc6);
        curso1->agregarInscripcion(insc6);
        Inscripcion* insc7 = new Inscripcion(fechIns7, false, 0, ejInsc7, curso5, U4);
        U4->agregarInscripcion(insc7);
        curso5->agregarInscripcion(insc7);
        Inscripcion* insc8 = new Inscripcion(fechIns8, false, 0, ejInsc8, curso5, U5);
        U5->agregarInscripcion(insc8);
        curso5->agregarInscripcion(insc8);

        cout << endl << "Datos iniciales cargados correctamente" << endl << endl;  

    }
    catch(const exception& e) {
        throw invalid_argument(e.what());
    }


};
