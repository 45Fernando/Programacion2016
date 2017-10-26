#include "listaalumno.h"
#include <stdio.h>

void privCargarLista(listaAlumno lista, int tam);
int privBuscarDNI(listaAlumno lista, int ini, int fin , long bus);
void quickSort(listaAlumno lista, int ini, int fin);
void mezcla(listaAlumno lista, int ini, int m, int fin);
void mergeSort(listaAlumno lista,int ini, int fin);
void privMostrarLista(listaAlumno lista, int tam);

void privCargarLista(listaAlumno lista, int tam){
	if(tam > 0){
		privCargarLista(lista, tam - 1);
		lista[tam] = cargarUno();
	}
}

void cargarLista(tListaAlumno *reg){	
	
	printf("Ingrese tamanio de la lista:");
	scanf("%d", &reg->tam);
	privCargarLista(reg->lista, reg->tam);
}

int listaVacia(tListaAlumno reg){
	
	if (reg.tam>0)
		return 1;
	else
		return 0;		
}

int listaLlena(tListaAlumno reg){
	
	if (reg.tam==31)
		return 0;
	else
		return 1;
}

int privBuscarDNI(listaAlumno lista, int ini, int fin , long bus){
	
	int med;
	med=(ini+fin)/2;
	if (ini<=fin){
		if (bus == retornaDNI(lista[med])) 
			return med;
		else
			if (bus < retornaDNI(lista[med]))
				return privBuscarDNI(lista, ini, med - 1, bus);
			else
				return privBuscarDNI(lista, ini + 1, fin, bus); 
	}else
		return -1;	
}

void quickSort(listaAlumno lista, int ini, int fin){
	tAlumno pivote;
	int izq, der, med;
	
	if(ini < fin){
		pivote = lista[ini];
		izq = ini;
		der = fin;
		while (izq < der){
			while(der > izq && retornaDNI(lista[der])> retornaDNI(pivote))
				der--;
			if (der > izq){
				lista[izq] = lista[der];
				izq++;
			}
			while(izq < der && retornaDNI(lista[izq]) < retornaDNI(pivote))
				izq++;
			if(izq < der){
				lista[der] = lista[izq];
				der--;				
			}
		}
		lista[der] = pivote;
		med = der;
		quickSort(lista, ini, med-1);
		quickSort(lista, ini + 1, fin);
	}
}

void ordenarListaQS(tListaAlumno *reg){
	quickSort(reg->lista, 1, reg->tam);
}

void mezcla(listaAlumno lista, int ini, int m, int fin){
	listaAlumno aux;	
	int i, j, k, t;
	
	k = 0;
	i = ini;
	j = m + 1;
	while (i <= m && j <= fin){
		k++;
		if(retornaDNI(lista[i]) < retornaDNI(lista[j])){
			aux[k] = lista[i];
			i++;
		}
		else{
			aux[k] = lista[j];
			j++;
		}			
	}
	for(t = i; t <= m; t++){
		k++;
		aux[k] = lista[t];
	}
	for(t = j; t <= fin; t++){
		k++;
		aux[k] = lista[t];
	}
	for(t = 1; t <= k; t++)
		lista[ini + t - 1] = aux[t];
}

void mergeSort(listaAlumno lista,int ini, int fin){
	int m;
	
	m=(ini+fin)/2;
	if (ini<fin){
		mergeSort(lista, ini, m);
		mergeSort(lista, m + 1, fin);
		mezcla(lista, ini, m, fin);
	}
}

void ordenarListaMS(tListaAlumno *reg){
	mergeSort(reg->lista, 1, reg->tam);
}

void modificarTutor(tListaAlumno *reg){
	long buscado;
	int posi;
	
	printf("\nIngrese DNI a buscar:");
	scanf("%ld", &buscado);
	posi = privBuscarDNI(reg->lista, 1, reg->tam, buscado);
	if(posi != -1){
		mostrarUno(reg->lista[posi]);
		modificaTutor(&reg->lista[posi]);
		mostrarUno(reg->lista[posi]);
	}else
		printf("\nAlumno no encontrado");
}

void privMostrarLista(listaAlumno lista, int tam){
	
	if (tam > 0){
		privMostrarLista(lista, tam - 1);
		mostrarUno(lista[tam]);
	}
}

void mostrarLista(tListaAlumno reg){
	
	privMostrarLista(reg.lista, reg.tam);	
}
