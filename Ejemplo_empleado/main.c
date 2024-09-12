#include <stdio.h>
#
#include "empleado.h"

void mostrar_menu(Empleado* empleados; int* num_empleados, int* capacidad_actual) {
    int opcion = 0;

    do {

        printf("1. Agregar Empleado\n2. Ver Empleado\n3. Buscar Empleado\n4. Salir")
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregar_empleado(empleados, num_empleados, capacidad_actual)
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                break;
        }
    
    } while (opcion != 4);

}


int main() {
    Empleado* empleados;

    inicializar_empleados(empleados);

    mostrar_menu()




}
