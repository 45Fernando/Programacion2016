#include "lista.h"
#include <stdio.h>


void insertarOrdInd(tVector lista, tIndice indDNI, int tam);
void generaIndiceDNI(tLista *reg);
int privBuscarPorIndDNI(tVector Lista, tIndice indLU, int tam, int bus);
void privEliminar(tVector lista, int *tam, int posi);
void privMostrarLista(tVector lista, tIndice indice, int tam);

tLista iniciar(){
	tLista nueva;
	
	nueva.tam = 0;
	
	return nueva;	
}

int listaVacia(tLista reg){
	if(reg.tam == 0){
		return 1;
	}else{
		return -1;
	}
}

int listaLlena(tLista reg){
	if(reg.tam == 50){
		return 1;
	} else {
		return -1;
	}
}

void insertarOrdInd(tVector lista, tIndice indDNI, int tam){
	int j;
	
	j = tam - 1;
	while ((j > 0) && (retornarDNI(lista[tam]) < retornarDNI(lista[indDNI[j]]))){
		indDNI[j+1] = indDNI[j];
		j--;
	}
	indDNI[j+1] = tam;	
}

void generaIndiceDNI(tLista *reg){
	int i;
	
	for(i = 1; i <= reg->tam; i++)
		insertarOrdInd(reg->lista, reg->indDni, i);
}

void insertar(tLista *reg){
	
	reg->tam = reg->tam + 1;
	reg->lista[reg->tam] = cargarUno();
	insertarOrdInd(reg->lista, reg->indDni, reg->tam);
}

void modificarAlumno(tLista *reg, int buscado){
	int posi;
	
	posi = privBuscarPorIndDNI(reg->lista, reg->indDni, reg->tam, buscado);
	if(posi != -1){
		modificarCarreraLU(&reg->lista[posi]);
		mostrarUno(reg->lista[posi]);
	}else{
		printf("\nAlumno no encontrado.");
	}
}

int privBuscarPorIndDNI(tVector Lista, tIndice indDNI, int tam, int bus){
	
	int ini,fin,med;
	
	ini = 1 ;
	fin = tam;
	med = (ini+fin)/2;
	while(ini <= fin && retornarDNI(Lista[indDNI[med]]) != bus){
		if(bus > retornarDNI(Lista[indDNI[med]])){
			ini = med + 1 ;
		}
		else{
			fin = med - 1 ;
		}
		med = (ini+fin)/2;
	}
	if (ini <= fin){
		return indDNI[med]; /*Aca tenemos que retonar el valor que contiene el indice, y no solo med*/
	}else
		return -1;
}



void privEliminar(tVector lista, int *tam, int posi){
	int i;
	
	for(i = posi; i <= *tam - 1; i++){
		lista[i] = lista[i+1];
	}
	*tam = *tam - 1;
}

void eliminarAlumno(tLista *reg, int buscado){
	int posi;
	
	posi = privBuscarPorIndDNI(reg->lista, reg->indDni, reg->tam, buscado);
	if(posi != -1){
		privEliminar(reg->lista, &reg->tam, posi);
		printf("\nAlumno elminado.");
		generaIndiceDNI(reg);
	}else{
		printf("\nAlumno no encontrado.");
	}
}

void privMostrarLista(tVector lista, tIndice indDni, int tam){
	int i;
	
	for(i = 1; i <= tam ; i++){
		printf("\n---------------");
		mostrarUno(lista[indDni[i]]);
		printf("\n---------------");
	}
}

void mostrarLista(tLista reg){	
	
	printf("\n Mostrando la lista:");
	privMostrarLista(reg.lista, reg.indDni, reg.tam);
	
}



