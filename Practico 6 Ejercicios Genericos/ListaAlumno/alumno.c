#include "lectura_cadena.h"
#include "alumno.h"
#include <stdio.h>

tAlumno cargarUno(){
	
	tAlumno nuevo;
	
	printf("\n Ingrese DNI del alumno:");
	scanf("%ld",&nuevo.dni);	
	printf("\n Ingrese Apellido del alumno:");	
	leeCad(nuevo.apellido,30);	
	printf("\n Ingrese Nombre del alumno:");
	leeCad(nuevo.nombre,30);	
	printf("\n Ingrese Tutor del alumno:");	
	leeCad(nuevo.nombreTutor,30);
	
	return nuevo;	
}

void mostrarUno(tAlumno reg){
	
	printf("\n DNI:%ld",reg.dni);
	printf("\n Apellido:%s",reg.apellido);
	printf("\n Nombre:%s",reg.nombre);
	printf("\n Tutor:%s",reg.nombreTutor);
	printf("\n");
	printf("\n");
}

void modificaTutor(tAlumno *reg){
	
	printf("\n Ingrese Tutor del alumno:");	
	leeCad(reg->nombreTutor,30);
}

long retornaDNI(tAlumno reg){
	
	return reg.dni;
}
