#include <stdio.h>
#include "empleado.h"

void inicializar_empleados(Empleado* empleados, int* num_empleados) {

    empleados = (Empleado*)calloc(CAPACIDAD_INICIAL, sizeof(Empleado));
}

void agregar_empleado(Empleado* empleados, int *num_empleados, int *capacidad_actual) {
    if (*num_empleados == *capacidad_actual) {
        empleados = (Empleado*)realloc(empleados, (*capacidad_actual*2)*sizeof(Empleado));
        *capacidad_actual *= 2;

        if (empleados==NULL) {
            printf("Error al asignar memoria.")
            return;
        }
    }

    Empleado empleado;

    printf("Ingrese el nombre del empleado: ");
    scanf(" %[^\n]", empleado.name);
    printf("Ingrese el numero de empleado: ");
    scanf("%d", &empleado.num_empleado);
    printf("Ingrese el salario: ");
    scanf("%f", &empleado.salario);

    empleados[(*num_empleados)++] = empleado;
    printf("Empleado agregado correctamente.")

}

void ver_empleados(Empleado* empleados, int num_empleados) {

    for (int i = 0; i < num_empleados; ++i) {
        printf("nombre: %s", empleados[i].name);
        printf("numero: %d", empleados[i].num_empleado);
        printf("salario: %f", empleados[i].salario);
    }
}