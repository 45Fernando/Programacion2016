#ifndef DATO_H
#define DATO_H

typedef char tCadena[31];

typedef struct{
	int dni;
	tCadena nombre;
	tCadena direccion;
	int telefono;
}tContacto;

tContacto cargarUno();
void mostrarUno(tContacto nuevo);
int retornaDNI(tContacto nuevo);
void modificarDireccion(tContacto *nuevo);

#endif
