#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Autor: Fernando Orquera
A�o: 2017
*/

const int tam_max=20;

typedef char Tcadena[20];
typedef int tVector[50];

typedef struct{
	long int dni;
	Tcadena nombre;
	int edad;
}tCliente;

typedef tCliente tLista[100];

int menu();
int leeCad(Tcadena, int);
tCliente cargarUno();
void mostrarUno(tCliente reg);
void cargarLista(tLista lista,int *tam);
void mostrarLista(tLista lista,int tam);
void mostrarPersonasEdad(tLista lista, int tam);
int cantidadPersonasRangoEdad(tLista lista, int tam, int A, int B);
void edadesDepuradas(tLista lista, int tam, tVector vectorEdades, tVector vectorFrecuencia, int *tama);
void mostrarEdades(tVector edades, tVector frecuencia, int tam);
int busquedaEdad(tVector vectorEdades, int tam, int buscado);
int buscarCliente(tLista lista, int tam, int dniBuscado);
void eliminarCliente(tLista lista, int *tam, int posicion);

int main(){
	
	tLista lista;
	tVector edades, frecuencia;
	int tam, posicion, opcion, tama;
	long int dni;	
	tCliente aux;
	
	tam = 0;
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				if(tam == 0){
					cargarLista(lista, &tam);
				}else{
					printf("Las personas ya fueron cargados.\n");
				}
				break;
			case 2:
				if(tam > 0){
					mostrarPersonasEdad(lista, tam);
				}else{
					printf("Las personas no fueron cargadas.\n");
				}
				break;
			case 3:
				if(tam > 0){
					edadesDepuradas(lista, tam, edades, frecuencia, &tama);
					mostrarEdades(edades, frecuencia, tama);
				}else{
					printf("Las personas no fueron cargadas.\n");
				}				
				break;
			case 4:
				if(tam > 0){
					printf("\n Ingrese DNI de la persona a buscar:");
					scanf("%ld",&dni);
					posicion = buscarCliente(lista, tam, dni);
					if(posicion != -1){
						eliminarCliente(lista, &tam, posicion);
						mostrarLista(lista, tam);
					}else{
						printf("\n La persona no existe.");
					}
				}else{
					printf("Las personas no fueron cargadas.\n");
				}
				break;
			case 5:
				aux = cargarUno();
				if (buscarCliente(lista, tam, aux.dni) != 1){
					tam = tam + 1;
					lista[tam] = cargarUno();
				}else{
					printf("La persona ya se encuentra registrada.");
				}							
				break;
			case 6:
				if(tam > 0){
					printf("\n Ingrese DNI de la persona a buscar:");
					scanf("%ld",&dni);
					posicion = buscarCliente(lista, tam, dni);
					if(posicion != -1){
						mostrarUno(lista[posicion]);
					}else{
						printf("\n La persona no existe.");
					}
				}else{
					printf("Las personas no fueron cargadas.\n");
				}
				break;
			case 7:
				mostrarLista(lista, tam);
			break;
		}
	}while(opcion != 0);	
	
	return 0;
}

int menu(){
	int op;
	
	do{
		printf("\n1 - Cargar Personas.\n");
		printf("2 - Mostrar Cantidad de personas en cierto rango de edad.\n");
		printf("3 - Mostrar edades y su frecuencias de aparicion.\n");
		printf("4 - Elminar una persona\n");
		printf("5 - Insertar una nueva persona.\n");
		printf("6 - Buscar una persona.\n");
		printf("7 - Mostrar las personas\n");
		printf("0 - Salir.\n");
		printf("\nOpcion: ");
		scanf("%d", &op);
	}while(op < 0 && op > 7);
	
	return op;
}

int leeCad(Tcadena cadena, int tam){
	int j, ret;
	char c;
	j=0;
	c=getchar();
	ret=0;
	while (c!=EOF && c!='\n' && j<tam-1)
	{
		cadena[j]=c;
		j++;
		c=getchar();
		ret=1;
	}
	cadena[j]='\0';
	
	while(c!=EOF && c!='\n')
		c=getchar();
	return ret;
}

/*
	Retorna una persona cargada.
*/
tCliente cargarUno(){
	tCliente nuevo;
	
	printf("\n Ingrese DNI de la persona:");
	scanf("%ld", &nuevo.dni);
	fflush(stdin);
	printf("\n Ingrese nombre de la persona:");
	leeCad(nuevo.nombre,tam_max);
	printf("\n Ingrese edad de la persona:");
	scanf("%d", &nuevo.edad);	
	
	return nuevo;
}

/*
	Carga la lista de personas.
*/
void cargarLista(tLista lista,int *tam){
	int i;
	
	printf("\n Ingrese cantidad de personas:");
	scanf("%d",tam);
	for(i=1;i<=*tam;i++){
		printf("Ingrese la %d %c persona:\n", i, 167);
		lista[i] = cargarUno(i);
	}
}

/*
	Muestra una sola persona.
*/
void mostrarUno(tCliente reg){
	
	printf("\n DNI de la persona: %ld", reg.dni);
	printf("\n Nombre de la persona: %s", reg.nombre);
	printf("\n Edad de la persona: %d", reg.edad);	
	printf("\n---------------- \n");
}

/*
	Muestra la lista de personas.
*/
void mostrarLista(tLista lista,int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		mostrarUno(lista[i]);
	}
}

void mostrarPersonasEdad(tLista lista, int tam){
	int A, B;
	
	printf("Ingrese un rango de edad.\n");
	printf("\nIngrese un valor para limite inferior :");
	scanf("%d", &A);
	printf("\nIngrese un valor para limite superior :");
	scanf("%d", &B);
	printf("\nCantidad de personas fuera del rango [%d, %d] de edad: %d", A, B, cantidadPersonasRangoEdad(lista, tam, A, B));
}

/*
	Retorna la cantidad de personas con edad fuera del rango [A,B].
*/
int cantidadPersonasRangoEdad(tLista lista, int tam, int A, int B){
	int cantidad, i;
	
	cantidad = 0;
	for(i = 1; i <= tam; i++){
		if(lista[i].edad < A || lista[i].edad > B){
			cantidad++;
		}
	}
	
	return cantidad;
}

/*
	Retorna dos vectores asociados, uno conteniendo las edades sin repetir,
	y el otro conteniendo la frecuencia.
*/
void edadesDepuradas(tLista lista, int tam, tVector vectorEdades, tVector vectorFrecuencia, int *tama){
	int i, posicion;
	
	*tama = 0;
	for(i = 1; i <= tam; i++){
		posicion = busquedaEdad(vectorEdades, *tama, lista[i].edad);
		if(posicion == -1){
			*tama = *tama + 1;
			vectorEdades[*tama] = lista[i].edad;
			vectorFrecuencia[*tama] = 1;
		}else{
			vectorFrecuencia[posicion] = vectorFrecuencia[*tama] + 1;
		}
	}
}

void mostrarEdades(tVector edades, tVector frecuencia, int tam){
	int i;
	
	for(i = 1; i <= tam; i++){
		printf("\nEdad: %d ", edades[i]);
		printf("Frecuencia: %d ", frecuencia[i]);
	}
}

/*
	Retorna la posicion, si encontro el buscado.
	Retorna -1 caso contrario.
*/
int busquedaEdad(tVector vectorEdades, int tam, int buscado){
	int i;
	
	i = 1;
	while(i <= tam && vectorEdades[i] != buscado){
		i++;
	}
	if(i <= tam){
		return 1;
	}else{
		return -1;
	}
}

/*
	Busqueda secuencial.
*/
int buscarCliente(tLista lista, int tam, int dniBuscado){
	int i;
	
	i = 1;
	while(i <= tam && lista[i].dni != dniBuscado){
		i++;
	}
	if(i <= tam){
		return i;
	}else
		return -1;
}

/*
	Elimina un cliente, dada una posicion.
*/
void eliminarCliente(tLista lista, int *tam, int posicion){
	int i;
	
	for(i = posicion; i <= *tam - 1; i++){
		lista[i] = lista[i + 1];
	}
	*tam = *tam - 1;
}



