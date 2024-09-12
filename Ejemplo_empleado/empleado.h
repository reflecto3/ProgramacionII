#ifndef EMPLEADO_H
#define EMPLEADO_H

#define MAX_NOMBRE 20
#define CAPACIDAD_INICIAL

typedef struct {
	char name[MAX_NOMBRE];
	int num_empleado;
	float salario;
} Empleado;

//ToDo: revisar
void inicializar_empleados(Empleado* empleados);
void agregar_empleado(Empleado *empleados, int *num_empleados, int *capacidad_actual);
void ver_empleados(Empleado *empleados, int num_empleados);
