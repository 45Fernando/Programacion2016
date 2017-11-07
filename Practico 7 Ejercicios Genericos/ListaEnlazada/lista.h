#ifndef LISTA_H
#define LISTA_H

#include "dato.h"

typedef struct nodo{
	tContacto reg;
	struct nodo *sig;
}tNodo;

typedef tNodo* tPtr;

tPtr cargarNodo();
tPtr fInsertarNodo(tPtr pri); /*Inserta ordenadamente*/
void insertarNodo(tPtr *pri); /*Inserta ordenadamente*/
void mostrarLista(tPtr pri);
void eliminarNodo(tPtr *pri);
void modificarNodo(tPtr *pri);

#endif
