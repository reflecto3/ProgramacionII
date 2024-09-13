#include <stdio.h>
#include "empleados.h"

void show_menu(Employee **employees, int *numEmployees, int *actualCapacity) {
    int option = -1;

    //posible empleado a agregar, o simplemente la estructura para guardar datos
    Employee employee;

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
            askForNameNumberAndOrSalary(&employee, true, true, true);
            addEmployee(employee, employees, numEmployees, actualCapacity);
            break;
        case 2:
            viewEmployees(*employees, *numEmployees);
            break;
        case 3:
            askForNameNumberAndOrSalary(&employee, false, true, false);
            searchAndShowEmployee(*employees, employee.num_employee, *numEmployees);
            break;
        case 4:
            askForNameNumberAndOrSalary(&employee, false, true, false);
            askForNameNumberAndOrSalary(&employee, true, false, true);
            modifyEmployee(employee, *employees, *numEmployees);
            break;
        case 5:
            askForNameNumberAndOrSalary(&employee, false, true, false);
            deleteEmployee(*employees, employee.num_employee, numEmployees);
            break;
        case 6:
            printf("Saliendo del programa\n");
            break;
        
        default:
            printf("Opción no válida\n");
            break;
        }
    } while (option != 6);
}

int main() {
    Employee *employees;

    initializeEmployees(&employees);
    int actualCapacity = INITIAL_CAPACITY;
    int numEmployees = 0;

    getFromFile("empleados.csv", &employees, &numEmployees, &actualCapacity);

    viewEmployees(employees, numEmployees);
    printAvgSalary(employees, numEmployees);
    printMaxMinSalaries(employees, numEmployees);


    // show_menu(&employees, &numEmployees, &actualCapacity);
    freeEmployees(employees);

    return 0;
}


