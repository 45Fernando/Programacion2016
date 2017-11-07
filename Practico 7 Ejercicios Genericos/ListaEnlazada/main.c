#include "lista.h"
#include <stdio.h>

int menu();

int main(){
	int op;
	tPtr pri = NULL;	
	
	do{
		op = menu();
		switch(op){
		case 1:	
			/*insertarNodo(&pri ,aux);*/
			pri = fInsertarNodo(pri);
			break;
		case 2:
			mostrarLista(pri);
			break;
		case 3:
			modificarNodo(&pri);
			break;
		case 4:
			eliminarNodo(&pri);
			break;			
		}		
	}while (op!=5);
	
	return 0;
}

int menu(){	
	int op;
	
	printf("\n 1 - Ingrese un nodo:");
	printf("\n 2 - Mostrar la Lista:");
	printf("\n 3 - Modificar un contacto:");
	printf("\n 4 - Eliminar un contacto:");
	printf("\n 0 - Salir");
	do {
		printf("\n Escoja una opcion:");
		scanf("%d", &op );
	}while (op < 0 && op > 4);	
	
	return op;	
}
