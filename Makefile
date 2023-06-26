# ----- Makefile Grupo 51 -----

OBJETOS = obj/CompletarPalabras.o obj/Curso.o obj/DTEjercicio.o obj/DTFecha.o obj/DTInscripcion.o obj/DTInfoCurso.o obj/DTInfoCursoGeneral.o obj/DTLeccion.o obj/DTNotificaciones.o obj/Ejercicio.o obj/Estudiante.o obj/Idioma.o obj/Inscripcion.o obj/Leccion.o obj/Notificacion.o obj/Profesor.o obj/Traduccion.o obj/Usuario.o obj/altaIdioma.o obj/altaCurso.o obj/cargaDatos.o obj/consultaCurso.o obj/consultaNotificaciones.o obj/consultarEstadisticas.o obj/consultarIdiomas.o  obj/DTConsultaCurso.o obj/DTEstudiante.o obj/DTInfoCursoExtendido.o obj/DTProfesor.o obj/DTUsuario.o obj/eliminarCurso.o obj/eliminarSuscripciones.o obj/Fabrica.o obj/FechaSistema.o obj/habilitarCurso.o obj/inscribirseCurso.o obj/realizarEjercicio.o obj/suscribirseANotificaciones.o obj/ControladorCurso.o obj/ControladorUsuario.o obj/agregarLeccion.o obj/AltaUsuario.o obj/ConsultarUsuario.o obj/DTCompletarPalabras.o obj/DTTraduccion.o obj/DTLeccionInt.o obj/DTIdioma.o obj/agregarEjercicio.o

FUENTES = src/DTEjercicio.cpp include/DTEjercicio.h \
src/DTFecha.cpp include/DTFecha.h \
src/DTInfoCurso.cpp include/DTInfoCurso.h \
src/DTInfoCursoGeneral.cpp include/DTInfoCursoGeneral.h \
src/DTLeccion.cpp include/DTLeccion.h \
src/DTNotificaciones.cpp include/DTNotificaciones.h \
src/DTInscripcion.cpp include/DTInscripcion.h \
src/Idioma.cpp include/Idioma.h \
src/Notificacion.cpp include/Notificacion.h \
src/Profesor.cpp include/Profesor.h \
src/Estudiante.cpp include/Estudiante.h \
src/Usuario.cpp include/Usuario.h \
src/Inscripcion.cpp include/Inscripcion.h \
src/CompletarPalabras.cpp include/CompletarPalabras.h \
src/Traduccion.cpp include/Traduccion.h \
src/Ejercicio.cpp include/Ejercicio.h \
src/Leccion.cpp include/Leccion.h \
src/Curso.cpp include/Curso.h \
src/Fabrica.cpp include/Fabrica.h \
src/cargaDatos.cpp include/cargaDatos.h \
src/altaIdioma.cpp include/altaIdioma.h \
src/altaCurso.cpp include/altaCurso.h \
src/consultaCurso.cpp include/consultaCurso.h \
src/consultaNotificaciones.cpp include/consultaNotificaciones.h \
src/consultarEstadisticas.cpp include/consultarEstadisticas.h \
src/consultarIdiomas.cpp include/consultarIdiomas.h \
src/ControladorCurso.cpp include/ControladorCurso.h \
src/ControladorUsuario.cpp include/ControladorUsuario.h \
src/DTConsultaCurso.cpp include/DTConsultaCurso.h \
src/DTEstudiante.cpp include/DTEstudiante.h \
src/DTInfoCursoExtendido.cpp include/DTInfoCursoExtendido.h \
src/DTProfesor.cpp include/DTProfesor.h \
src/DTUsuario.cpp include/DTUsuario.h \
src/eliminarCurso.cpp include/eliminarCurso.h \
src/eliminarSuscripciones.cpp include/eliminarSuscripciones.h \
src/FechaSistema.cpp include/FechaSistema.h \
src/habilitarCurso.cpp include/habilitarCurso.h \
src/inscribirseCurso.cpp include/inscribirseCurso.h \
src/realizarEjercicio.cpp include/realizarEjercicio.h \
src/agregarLeccion.cpp include/agregarLeccion.h \
src/AltaUsuario.cpp include/AltaUsuario.h \
src/ConsultarUsuario.cpp include/ConsultarUsuario.h \
src/DTCompletarPalabras.cpp include/DTCompletarPalabras.h \
src/DTTraduccion.cpp include/DTTraduccion.h \
src/suscribirseANotificaciones.cpp include/suscribirseANotificaciones.h \
src/DTLeccionInt.cpp include/DTLeccionInt.h \
src/DTIdioma.cpp include/DTIdioma.h \
src/agregarEjercicio.cpp include/agregarEjercicio.h \
main.cpp

CC = g++
OPCIONES = -g -Wall
SINUSO =

main: $(OBJETOS) main.cpp
	$(CC) $(OPCIONES) $(OBJETOS) $(SINUSO) main.cpp -o main

obj/Curso.o: include/Curso.h src/Curso.cpp
	$(CC) $(OPCIONES) -c src/Curso.cpp -o obj/Curso.o

obj/Leccion.o: include/Leccion.h src/Leccion.cpp
	$(CC) $(OPCIONES) -c src/Leccion.cpp -o obj/Leccion.o

obj/Ejercicio.o: include/Ejercicio.h src/Ejercicio.cpp
	$(CC) $(OPCIONES) -c src/Ejercicio.cpp -o obj/Ejercicio.o

obj/Traduccion.o: include/Traduccion.h src/Traduccion.cpp
	$(CC) $(OPCIONES) -c src/Traduccion.cpp -o obj/Traduccion.o

obj/CompletarPalabras.o: include/CompletarPalabras.h src/CompletarPalabras.cpp
	$(CC) $(OPCIONES) -c src/CompletarPalabras.cpp -o obj/CompletarPalabras.o

obj/Inscripcion.o: include/Inscripcion.h src/Inscripcion.cpp
	$(CC) $(OPCIONES) -c src/Inscripcion.cpp -o obj/Inscripcion.o

obj/Usuario.o: include/Usuario.h src/Usuario.cpp
	$(CC) $(OPCIONES) -c src/Usuario.cpp -o obj/Usuario.o

obj/Estudiante.o: include/Estudiante.h src/Estudiante.cpp
	$(CC) $(OPCIONES) -c src/Estudiante.cpp -o obj/Estudiante.o

obj/Profesor.o: include/Profesor.h src/Profesor.cpp
	$(CC) $(OPCIONES) -c src/Profesor.cpp -o obj/Profesor.o

obj/Notificacion.o: include/Notificacion.h src/Notificacion.cpp
	$(CC) $(OPCIONES) -c src/Notificacion.cpp -o obj/Notificacion.o

obj/Idioma.o: include/Idioma.h src/Idioma.cpp
	$(CC) $(OPCIONES) -c src/Idioma.cpp -o obj/Idioma.o

obj/DTNotificaciones.o: include/DTNotificaciones.h src/DTNotificaciones.cpp
	$(CC) $(OPCIONES) -c src/DTNotificaciones.cpp -o obj/DTNotificaciones.o

obj/DTLeccion.o: include/DTLeccion.h src/DTLeccion.cpp
	$(CC) $(OPCIONES) -c src/DTLeccion.cpp -o obj/DTLeccion.o

obj/DTInfoCursoGeneral.o: include/DTInfoCursoGeneral.h src/DTInfoCursoGeneral.cpp
	$(CC) $(OPCIONES) -c src/DTInfoCursoGeneral.cpp -o obj/DTInfoCursoGeneral.o

obj/DTInfoCurso.o: include/DTInfoCurso.h src/DTInfoCurso.cpp
	$(CC) $(OPCIONES) -c src/DTInfoCurso.cpp -o obj/DTInfoCurso.o

obj/DTFecha.o: include/DTFecha.h src/DTFecha.cpp
	$(CC) $(OPCIONES) -c src/DTFecha.cpp -o obj/DTFecha.o

obj/DTEjercicio.o: include/DTEjercicio.h src/DTEjercicio.cpp
	$(CC) $(OPCIONES) -c src/DTEjercicio.cpp -o obj/DTEjercicio.o

obj/DTInscripcion.o: include/DTInscripcion.h src/DTInscripcion.cpp
	$(CC) $(OPCIONES) -c src/DTInscripcion.cpp -o obj/DTInscripcion.o

obj/Fabrica.o: include/Fabrica.h src/Fabrica.cpp
	$(CC) $(OPCIONES) -c src/Fabrica.cpp -o obj/Fabrica.o

obj/cargaDatos.o: include/cargaDatos.h src/cargaDatos.cpp
	$(CC) $(OPCIONES) -c src/cargaDatos.cpp -o obj/cargaDatos.o

obj/altaIdioma.o: include/altaIdioma.h src/altaIdioma.cpp
	$(CC) $(OPCIONES) -c src/altaIdioma.cpp -o obj/altaIdioma.o

obj/altaCurso.o: include/altaCurso.h src/altaCurso.cpp
	$(CC) $(OPCIONES) -c src/altaCurso.cpp -o obj/altaCurso.o

obj/consultaCurso.o: include/consultaCurso.h src/consultaCurso.cpp
	$(CC) $(OPCIONES) -c src/consultaCurso.cpp -o obj/consultaCurso.o

obj/consultaNotificaciones.o: include/consultaNotificaciones.h src/consultaNotificaciones.cpp
	$(CC) $(OPCIONES) -c src/consultaNotificaciones.cpp -o obj/consultaNotificaciones.o

obj/consultarEstadisticas.o: include/consultarEstadisticas.h src/consultarEstadisticas.cpp
	$(CC) $(OPCIONES) -c src/consultarEstadisticas.cpp -o obj/consultarEstadisticas.o

obj/consultarIdiomas.o: include/consultarIdiomas.h src/consultarIdiomas.cpp
	$(CC) $(OPCIONES) -c src/consultarIdiomas.cpp -o obj/consultarIdiomas.o

obj/ControladorCurso.o: include/ControladorCurso.h src/ControladorCurso.cpp
	$(CC) $(OPCIONES) -c src/ControladorCurso.cpp -o obj/ControladorCurso.o

obj/ControladorUsuario.o: include/ControladorUsuario.h src/ControladorUsuario.cpp
	$(CC) $(OPCIONES) -c src/ControladorUsuario.cpp -o obj/ControladorUsuario.o

obj/DTConsultaCurso.o: include/DTConsultaCurso.h src/DTConsultaCurso.cpp
	$(CC) $(OPCIONES) -c src/DTConsultaCurso.cpp -o obj/DTConsultaCurso.o

obj/DTEstudiante.o: include/DTEstudiante.h src/DTEstudiante.cpp
	$(CC) $(OPCIONES) -c src/DTEstudiante.cpp -o obj/DTEstudiante.o

obj/DTInfoCursoExtendido.o: include/DTInfoCursoExtendido.h src/DTInfoCursoExtendido.cpp
	$(CC) $(OPCIONES) -c src/DTInfoCursoExtendido.cpp -o obj/DTInfoCursoExtendido.o

obj/DTProfesor.o: include/DTProfesor.h src/DTProfesor.cpp
	$(CC) $(OPCIONES) -c src/DTProfesor.cpp -o obj/DTProfesor.o

obj/DTUsuario.o: include/DTUsuario.h src/DTUsuario.cpp
	$(CC) $(OPCIONES) -c src/DTUsuario.cpp -o obj/DTUsuario.o

obj/eliminarCurso.o: include/eliminarCurso.h src/eliminarCurso.cpp
	$(CC) $(OPCIONES) -c src/eliminarCurso.cpp -o obj/eliminarCurso.o

obj/eliminarSuscripciones.o: include/eliminarSuscripciones.h src/eliminarSuscripciones.cpp
	$(CC) $(OPCIONES) -c src/eliminarSuscripciones.cpp -o obj/eliminarSuscripciones.o

obj/FechaSistema.o: include/FechaSistema.h src/FechaSistema.cpp
	$(CC) $(OPCIONES) -c src/FechaSistema.cpp -o obj/FechaSistema.o

obj/habilitarCurso.o: include/habilitarCurso.h src/habilitarCurso.cpp
	$(CC) $(OPCIONES) -c src/habilitarCurso.cpp -o obj/habilitarCurso.o

obj/inscribirseCurso.o: include/inscribirseCurso.h src/inscribirseCurso.cpp
	$(CC) $(OPCIONES) -c src/inscribirseCurso.cpp -o obj/inscribirseCurso.o

obj/realizarEjercicio.o: include/realizarEjercicio.h src/realizarEjercicio.cpp
	$(CC) $(OPCIONES) -c src/realizarEjercicio.cpp -o obj/realizarEjercicio.o

obj/suscribirseANotificaciones.o: include/suscribirseANotificaciones.h src/suscribirseANotificaciones.cpp
	$(CC) $(OPCIONES) -c src/suscribirseANotificaciones.cpp -o obj/suscribirseANotificaciones.o

obj/agregarLeccion.o: include/agregarLeccion.h src/agregarLeccion.cpp
	$(CC) $(OPCIONES) -c src/agregarLeccion.cpp -o obj/agregarLeccion.o

obj/AltaUsuario.o: include/AltaUsuario.h src/AltaUsuario.cpp
	$(CC) $(OPCIONES) -c src/AltaUsuario.cpp -o obj/AltaUsuario.o

obj/ConsultarUsuario.o: include/ConsultarUsuario.h src/ConsultarUsuario.cpp
	$(CC) $(OPCIONES) -c src/ConsultarUsuario.cpp -o obj/ConsultarUsuario.o

obj/DTCompletarPalabras.o: include/DTCompletarPalabras.h src/DTCompletarPalabras.cpp
	$(CC) $(OPCIONES) -c src/DTCompletarPalabras.cpp -o obj/DTCompletarPalabras.o

obj/DTTraduccion.o: include/DTTraduccion.h src/DTTraduccion.cpp
	$(CC) $(OPCIONES) -c src/DTTraduccion.cpp -o obj/DTTraduccion.o

obj/DTLeccionInt.o: include/DTLeccionInt.h src/DTLeccionInt.cpp
	$(CC) $(OPCIONES) -c src/DTLeccionInt.cpp -o obj/DTLeccionInt.o

obj/DTIdioma.o: include/DTIdioma.h src/DTIdioma.cpp
	$(CC) $(OPCIONES) -c src/DTIdioma.cpp -o obj/DTIdioma.o

obj/agregarEjercicio.o: include/agregarEjercicio.h src/agregarEjercicio.cpp
	$(CC) $(OPCIONES) -c src/agregarEjercicio.cpp -o obj/agregarEjercicio.o

.PHONY: clean rebuild

clean:
	rm -f $(OBJETOS) main

rebuild:
	make clean
	make