#ifndef LECTURA_CADENA_H
#define LECTURA_CADENA_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void leeCad(char cadena[], int tam){
	int j, m;
	
	j=0;
	fflush(stdin);
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	if(m != EOF && m != '\n') /*limpia el buffer*/
		while((m=getchar())!=EOF && m!='\n');
}
#endif
