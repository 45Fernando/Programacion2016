#ifndef ALUMNO_H
#define ALUMNO_H

/*Estructuras*/
typedef char tCadena[30];

typedef struct{
	long dni;
	tCadena apellido;
	tCadena nombre;	
	tCadena nombreTutor;
}tAlumno;

/*Operaciones*/
tAlumno cargarUno();
void mostrarUno(tAlumno reg);
void modificaTutor(tAlumno *reg);
long retornaDNI(tAlumno reg);
#endif
