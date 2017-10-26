#include "listaalumno.h"
#include <stdio.h>

int menu();

int main(){
	int op;
	tListaAlumno reg;
	
	do{
		op = menu();
		switch(op){
		case 1:
			cargarLista(&reg);
			break;
		case 2:
			printf("\nLa lista esta vacia.");
			break;
		case 3:
			ordenarListaQS(&reg);			
			break;
		case 4:
			ordenarListaMS(&reg);			
			break;
		case 5:
			mostrarLista(reg);
			break;		
		}
	}while(op != 0);	
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n");
		printf("\n1 - Cargar lista de alumnos.");
		printf("\n2 - Modificar un alumno.");
		printf("\n3 - Ordenar por QuickSort");
		printf("\n4 - Ordenar por MergeSort");
		printf("\n5 - Mostrar alumnos.");		
		printf("\n0 - Salir.");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 || op > 5);
	
	return op;
}
