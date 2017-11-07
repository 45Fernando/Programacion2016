#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

tPtr buscarNodo(tPtr pri, long bus);
tPtr determinaAnt(tPtr pri, tPtr nod);
void privEliminarNodo(tPtr *pri, tPtr ant,tPtr eli);

tPtr cargarNodo(){	
	tPtr x;
	
	x=(tNodo *)malloc(sizeof(tNodo));
	x->reg=cargarUno();
	x->sig=NULL;
	
	return x;	
}

/*Funcion que inserta el nodo ordenadamente*/
tPtr fInsertarNodo(tPtr pri){	
	tPtr ant,aux, nod;
	
	aux = pri;
	ant = NULL;
	nod = cargarNodo();
	while (aux != NULL && retornaDNI(aux->reg) < retornaDNI(nod->reg)){
		ant = aux;
		aux = aux->sig;
	}
	if (ant == NULL){
		nod->sig = pri;
		pri = nod;
	}
	else{
		nod->sig = ant->sig;
		ant->sig = nod;
	}
	
	return pri;
}

/*Procedimiento que inserta el nodo ordenadamente*/
void insertarNodo(tPtr *pri){	
	tPtr ant,aux, nod;
	
	aux = *pri;
	ant = NULL;
	nod = cargarNodo();
	while (aux != NULL && retornaDNI(aux->reg) < retornaDNI(nod->reg)){
		ant = aux;
		aux = aux->sig;
	}
	if (ant == NULL){
		nod->sig = *pri;
		*pri = nod;
	}
	else{
		nod->sig=ant->sig;
		ant->sig=nod;
	}
}

void mostrarLista(tPtr pri){
	
	while(pri != NULL){
		mostrarUno(pri->reg);
		pri=pri->sig;
	}
}

tPtr buscarNodo(tPtr pri, long bus){
	
	while (pri != NULL && retornaDNI(pri->reg) != bus)
		pri=pri->sig;
	return pri;	
}

tPtr determinaAnt(tPtr pri, tPtr nod){	
	tPtr aux;
	
	aux = NULL;	
	while (pri != nod){
		aux = pri;
		pri=pri->sig;
	}
	return aux;
}

void privEliminarNodo(tPtr *pri, tPtr ant,tPtr eli){
	
	if (*pri == eli)
		*pri= (*pri)->sig;
	else
		ant->sig = eli->sig;
	eli->sig = NULL;
	free(eli);
}

void eliminarNodo(tPtr *pri){	
	tPtr eli = NULL, ant = NULL;
	int bus;
	
	printf("\nIngrese DNI a buscar:");
	scanf("%d", &bus);
	eli = buscarNodo(*pri, bus);
	if(eli !=  NULL){
		ant = determinaAnt(*pri, eli);
		privEliminarNodo(pri, ant, eli);
	}else
		printf("\nNo se encontro la persona.");	
}

void modificarNodo(tPtr *pri){
	tPtr modi = NULL;
	int bus;
	
	printf("\nIngrese DNI a buscar:");
	scanf("%d", &bus);
	modi = buscarNodo(*pri, bus);
	if(modi !=  NULL){
		mostrarUno(modi->reg);
		modificarDireccion(&modi->reg);
		mostrarUno(modi->reg);
	}else
		printf("\nNo se encontro la persona.");
}

