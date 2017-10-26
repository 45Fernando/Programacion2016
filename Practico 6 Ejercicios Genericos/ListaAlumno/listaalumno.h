#ifndef LISTAALUMNO_H
#define LISTAALUMNO_H
#include "alumno.h"

typedef tAlumno listaAlumno[31];

typedef struct{
	
	listaAlumno lista;
	int tam;	
}tListaAlumno;

void cargarLista(tListaAlumno *reg);
int listaVacia(tListaAlumno reg);
int listaLlena(tListaAlumno reg);
void ordenarListaQS(tListaAlumno *reg);
void ordenarListaMS(tListaAlumno *reg);
void modificarTutor(tListaAlumno *reg);
void mostrarLista(tListaAlumno reg);

#endif
