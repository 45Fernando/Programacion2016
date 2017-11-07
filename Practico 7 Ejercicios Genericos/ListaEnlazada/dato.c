#include "lectura_cadena.h"
#include "dato.h"

tContacto cargarUno(){	
	tContacto nuevo;
	
	printf("\n Ingrese DNI:");
	scanf("%d",&nuevo.dni);	
	printf("\n Ingrese nombre:");
	fflush(stdin);
	leeCad(nuevo.nombre,31);	
	printf("\n Ingrese direccion:");
	fflush(stdin);
	leeCad(nuevo.direccion,31);	
	printf("\n Ingrese telefono:");
	scanf("%d",&nuevo.telefono);
	
	return nuevo;
}

void mostrarUno(tContacto nuevo){
	
	printf("\n DNI:%d",nuevo.dni);
	printf("\n Nombre:%s",nuevo.nombre);
	printf("\n Direccion:%s",nuevo.direccion);
	printf("\n Telefono:%d",nuevo.telefono);
	printf("\n");
	printf("\n");
}

int retornaDNI(tContacto nuevo){
	
	return nuevo.dni;
}

void modificarDireccion(tContacto *nuevo){
	
	printf("\nIngrese nueva direccion:");
	leeCad(nuevo->direccion,31);	
}
