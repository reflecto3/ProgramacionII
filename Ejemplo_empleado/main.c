#include <stdio.h>
#include "empleados.h"

void show_menu(Employee **employees, int *numEmployees, int *actualCapacity) {
    int option = -1;

    do {
        printf("\nMenu de empleados");
        printf("\n1. Agregar empleado");
        printf("\n2. Ver empleados");
        printf("\n3. Buscar empleado");
        printf("\n4. Modificar empleado");
        printf("\n5. Borrar empleado");
        printf("\n6. Salir\n:");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            /* code */
            addEmployee(employees, numEmployees, actualCapacity);
            break;
        case 2:
            /* code */
            viewEmployees(employees, *numEmployees);
            break;
        case 3:
            /* code */
            searchAndShowEmployee(employees, *numEmployees);
            break;
        case 4:
            modifyEmployee(employees, *numEmployees);
            break;
        case 5:
            deleteEmployee(employees, numEmployees);
            break;
        case 6:
            /* code */
            printf("Saliendo del programa\n");
            break;
        
        default:
            printf("Opción no válida\n");
            break;
        }
    } while (option != 6);
}

// ToDo: revisar
int main() {
    Employee *employees;

    initializeEmployees(&employees);
    int actualCapacity = INITIAL_CAPACITY;
    int numEmployees = 0;

    show_menu(&employees, &numEmployees, &actualCapacity);
    freeEmployees(&employees);


    return 0;
}


