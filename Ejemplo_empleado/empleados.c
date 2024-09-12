#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "empleados.h"

void initializeEmployees(Employee **employees) {
    *employees = (Employee*) calloc(INITIAL_CAPACITY, sizeof(Employee));

    checkMemAlloc(employees);
}

void checkMemAlloc(Employee** employees) {
    if (*employees == NULL) {
    printf("Error al asignar memoria.");
    }
}

void checkCapacity(Employee** employees, int numEmployees, int* actualCapacity) {
    if (*actualCapacity == numEmployees) {
        if (*actualCapacity*2 > MAX_EMPLOYEE) *actualCapacity = MAX_EMPLOYEE;
        else *actualCapacity *= 2;
        Employee* newArray;
        newArray = (Employee*) realloc(*employees, *actualCapacity*sizeof(Employee));
        checkMemAlloc(&newArray);
        *employees = newArray;
    }

}

bool isValidEmployee(Employee** employees, Employee employee, int numEmployees, bool checkRepeated) {
    if (checkRepeated) {
        for (int i = 0; i < numEmployees; ++i) {
            if (employee.num_employee == (*employees)[i].num_employee) {
                return false;
            }
        }
    }
    return (strlen(employee.name) > 0 && employee.num_employee > 0 && employee.salary > 0);
}

void addEmployee(Employee **employees, int *numEmployees, int *actualCapacity) {
    checkCapacity(employees, *numEmployees, actualCapacity);

    if ( *numEmployees > MAX_EMPLOYEE ) {
        printf("\nLa base de datos de empleados está llena.");
        return;
    }
    Employee newEmployee;
    printf("\nIngrese el nombre del empleado: ");
    scanf("%" xSTR(MAX_NAME) "[^\n]", newEmployee.name);
    printf("\nIngrese el número del empleado: ");
    scanf("%d", &newEmployee.num_employee);
    printf("\nIngrese el salario del empleado: ");
    scanf("%f", &newEmployee.salary);

    if (!isValidEmployee(employees, newEmployee, *numEmployees, true)) {
        printf("Datos invalidos");
        return;
    }

    (*employees)[(*numEmployees)++] = newEmployee;

    printf("\nEmpleado agregado\n");
}

void viewEmployees(Employee **employees, int numEmployees) {
    if ( numEmployees > 0 ) {
        printf("Lista de empleados: \n");

        for (int index = 0; index < numEmployees; ++index) {
            showEmployee((*employees)[index]);
        }
    }
    else
        printf("No hay empleados registrados");
}

void showEmployee(Employee employee) {
    printf("\nNombre: %s", employee.name);
    printf("\nNúmero de empleado: %d", employee.num_employee);
    printf("\nSalario: %.2f\n", employee.salary);
}

int indexSearchEmployee(Employee **employees, int numEmployeeSearched, int numEmployees) {
    for (int index = 0; index < numEmployees; ++index) {
        if ((*employees)[index].num_employee == numEmployeeSearched) {
            return index;
        }
    }
    return -1;
}

void searchAndShowEmployee(Employee **employees, int numEmployees) {
    int number = -1;
    printf("Ingrese el número de empleado: ");
    scanf("%d", &number);
    getchar();

    int position = indexSearchEmployee(employees, number, numEmployees);

    if (position == -1) {
        printf("Empleado no encontrado;");
        return;
    }

    showEmployee((*employees)[position]);
}

void modifyEmployee(Employee **employees, int numEmployees) {
    int number = -1;
    printf("Ingrese el número de empleado: ");
    scanf("%d", &number);
    getchar();

    int position = indexSearchEmployee(employees, number, numEmployees);

    if (position == -1) {
        printf("Empleado no encontrado;");
        return;
    }

    Employee modifiedEmployee;
    modifiedEmployee.num_employee = number;

    printf("\nIngrese el nombre del empleado: ");
    scanf("%" xSTR(MAX_NAME) "[^\n]", modifiedEmployee.name);
    printf("\nIngrese el salario del empleado: ");
    scanf("%f", &modifiedEmployee.salary);

    if (!isValidEmployee(employees, modifiedEmployee, numEmployees, false)) {
        printf("Datos invalidos");
        return;
    }

    (*employees)[position] = modifiedEmployee;

    printf("Empleado modificado exitosamente.\n");
}

void deleteEmployee(Employee **employees, int *numEmployees) {
    int number = -1;
    printf("Ingrese el número de empleado: ");
    scanf("%d", &number);
    getchar();

    int position = indexSearchEmployee(employees, number, *numEmployees);

    if (position == -1) {
        printf("Empleado no encontrado;");
        return;
    }

    //hacer que cada puntero iniciando por el que apunta al empleado a eliminar apunte al siguiente
    for (int i = position; i < *numEmployees-1; ++i) {
        *(*employees+i) = *(*employees+i+1);
    }

    //y que el ultimo puntero de la lista apunte a un nuevo producto vacio
    Employee emptyEmployee = {.num_employee = -1, .name = "", .salary = -1};
    *(*employees+*numEmployees-1) = emptyEmployee;

    --(*numEmployees);
}

void freeEmployees(Employee** employees) {
    free(*employees);
}