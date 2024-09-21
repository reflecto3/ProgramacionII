#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "empleados.h"

void initializeEmployees(Employee **employees) {
    *employees = (Employee*) calloc(INITIAL_CAPACITY_EMP, sizeof(Employee));

    checkMemAlloc(*employees);
}

void initializeDepartments(Employee ***departmentsPTR, int numDepartments) {
    *departmentsPTR = (Employee**) malloc(numDepartments * sizeof(Employee*));

    checkMemAllocDept(*departmentsPTR);

    for (int index = 0; index < numDepartments; ++index) {
        initializeEmployees((*departmentsPTR)+index);
    }

}

void checkMemAlloc(Employee* alloc) {
    if (alloc == NULL) {
    printf("Error al asignar memoria.");
    }
}

void checkMemAllocDept(Employee** alloc) {
    if (alloc == NULL) {
    printf("Error al asignar memoria.");
    }
}

void checkCapacity(Employee** employees, int numEmployees, int* actualCapacity) {
    if (*actualCapacity == numEmployees) {
        if (*actualCapacity*2 > MAX_EMPLOYEE) *actualCapacity = MAX_EMPLOYEE;
        else *actualCapacity *= 2;
        Employee* newArray;
        newArray = (Employee*) realloc(*employees, *actualCapacity*sizeof(Employee));
        checkMemAlloc(newArray);
        *employees = newArray;
    }

}

bool isValidEmployee(Employee* employees, Employee employee, int numEmployees, bool checkRepeated) {
    if (checkRepeated) {
        for (int i = 0; i < numEmployees; ++i) {
            if (employee.num_employee == employees[i].num_employee) {
                return false;
            }
        }
    }
    return (strlen(employee.name) > 0 && employee.num_employee > 0 && employee.salary > 0);
}

void addEmployee(Employee employee, Employee **employees, int *numEmployees, int *actualCapacity) {
    checkCapacity(employees, *numEmployees, actualCapacity);

    if ( *numEmployees > MAX_EMPLOYEE ) {
        printf("\nLa base de datos de empleados está llena.");
        return;
    }

    if (!isValidEmployee(*employees, employee, *numEmployees, true)) {
        printf("Datos invalidos para el nuevo empleado.");
        return;
    }

    (*employees)[(*numEmployees)++] = employee;

    // showEmployee((*employees)[*numEmployees]);
    // printf("\nEmpleado agregado.\n");
}

void printHeader() {
    printf("Lista de empleados: \n");
    printf("%-25s %-25s %-10s %-15s\n", "Nombre", "Numero de Empleado", "Salario", "Departamento");
    printf("%-25s %-25s %-10s %-15s\n", "--------------------", "-------------------", "----------", "---------------");
}

void viewEmployees(Employee *employees, int numEmployees) {
    if ( numEmployees > 0 ) {
        for (int index = 0; index < numEmployees && index<5; ++index) {
            showEmployee(employees[index]);
        }
    }
    else {
        printf("No hay empleados registrados.\n");
    }
}

void showAllEmployees(Employee** departments, DepartmentData* deptData, int numDepartments) {
    printHeader();
    for (int numDept = 0; numDept < numDepartments && numDept<5; ++numDept) {
        viewEmployees(departments[numDept], deptData[numDept].numEmployees);
    }
}

void viewDepartment(Employee** departments, DepartmentData* deptData, int numDept) {
    printHeader();
    viewEmployees(departments[numDept], deptData[numDept].numEmployees);
}

void showEmployee(Employee employee) {
    printf("%-25s %-25d %-10.2f %-15s\n", employee.name, employee.num_employee, employee.salary, employee.dept);
}

int indexSearchEmployee(Employee *employees, int numEmployeeSearched, int numEmployees) {
    for (int index = 0; index < numEmployees; ++index) {
        if (employees[index].num_employee == numEmployeeSearched) {
            return index;
        }
    }
    return -1;
}

void searchAndShowEmployee(Employee *employees, int numToShow, int numEmployees) {

    int position = indexSearchEmployee(employees, numToShow, numEmployees);

    if (position == -1) {
        printf("Empleado no encontrado;");
        return;
    }

    showEmployee(employees[position]);
}

void modifyEmployee(Employee modified, Employee *employees, int numEmployees) {

    int position = indexSearchEmployee(employees, modified.num_employee, numEmployees);

    if (position == -1) {
        printf("Numero de empleado no encontrado.");
        return;
    }

    if (!isValidEmployee(employees, modified, numEmployees, false)) {
        printf("Datos invalidos para la modificacion.");
        return;
    }

    employees[position] = modified;

    printf("Empleado modificado exitosamente.\n");
}

void deleteEmployee(Employee *employees, int numToDelete, int *numEmployees) {

    int position = indexSearchEmployee(employees, numToDelete, *numEmployees);

    if (position == -1) {
        printf("Empleado no encontrado;");
        return;
    }

    //hacer que cada puntero iniciando por el que apunta al empleado a eliminar apunte al siguiente
    for (int i = position; i < *numEmployees-1; ++i) {
        *(employees+i) = *(employees+i+1);
    }

    //y que el ultimo puntero de la lista apunte a un nuevo producto vacio
    Employee emptyEmployee = {.num_employee = -1, .name = "", .salary = -1};
    *(employees+*numEmployees-1) = emptyEmployee;

    --(*numEmployees);
}

void freeEmployees(Employee* employees) {
    free(employees);
}

void freeData(DepartmentData* deptData) {
    free(deptData);
}

void freeDepartments(Employee** departments, int numDepartments) {
    for (int index = 0; index < numDepartments; ++index) {
        freeEmployees(departments[index]);
    }
    
    free(departments);
}

void askForNameNumberAndOrSalaryAndOrDept(Employee *employee, bool name, bool number, bool salary, bool dept) {

    if (name) {
        printf("\nIngrese el nombre del empleado: ");
        scanf("%" xSTR(MAX_NAME) "[^\n]", (*employee).name);
    }
    if (number) {
        printf("\nIngrese el número de empleado: ");
        scanf("%d", &(*employee).num_employee);
        getchar();
    }
    if (salary) {
        printf("\nIngrese el salario del empleado: ");
        scanf("%f", &(*employee).salary);
    }
    if (dept) {
    printf("\nIngrese el departamento del empleado: ");
    scanf("%" xSTR(MAX_NAME_DEPT) "[^\n]", (*employee).dept);
    }
}

void getFromCSV(const char* filename, Employee*** departmentsPtr, DepartmentData** deptDataPtr, int* numDepartmentsPtr) {

    FILE* file = fopen(filename, "r");

    char* first_line = (char*)calloc(MAX_LINE_DEPTS, sizeof(char));

    fgets(first_line, MAX_LINE_DEPTS, file);

    *numDepartmentsPtr = 1;

    for (int index = 0; index < strlen(first_line); ++index) {
        if (first_line[index] == ',') {
            ++(*numDepartmentsPtr);
        }
    }

    *deptDataPtr = (DepartmentData*)calloc(*numDepartmentsPtr, sizeof(DepartmentData));

    char* token = strtok(first_line, ",\n");

    for (int index = 0; index < *numDepartmentsPtr; ++index) {
        if (token == NULL) printf("ERROR TOKEN");
        strcpy((*deptDataPtr)[index].name, token);
        (*deptDataPtr)[index].capacity = INITIAL_CAPACITY_EMP;
        (*deptDataPtr)[index].numEmployees = 0;
        (*deptDataPtr)[index].deptNum = index;

        token = strtok( NULL , ",\n");
    }

    free(first_line);

    initializeDepartments(departmentsPtr, *numDepartmentsPtr);

    Employee employee;

    while (fscanf(file, " %[^,],%d,%f,%[^\n]", employee.name, &employee.num_employee, &employee.salary, &employee.dept) == 4) {
        int deptNum = -1;
        for (int index = 0; index < *numDepartmentsPtr; ++index) {
            if (strcmp(employee.dept, (*deptDataPtr)[index].name) == 0) {
                deptNum = index;
                break;
            }
        }
        
        addEmployee(employee, (*departmentsPtr)+deptNum, &(*deptDataPtr)[deptNum].numEmployees, &(*deptDataPtr)[deptNum].capacity);
    }

    fclose(file);
}

void printAvgSalary(Employee* employees, int numEmployees) {
    float avg = 0;

    for (int i = 0; i < numEmployees; ++i) {
        avg += employees[i].salary/numEmployees;
    }

    printf("\nEl salario promedio de los %d empleados es de %.2f.\n", numEmployees, avg);
}

void printMaxMinSalaries(Employee* employees, int numEmployees) {
    int minpos = 0;
    int maxpos = 0;

    for (int i = 0; i < numEmployees; ++i) {
        minpos = employees[i].salary > employees[minpos].salary ? minpos : i;
        maxpos = employees[i].salary < employees[maxpos].salary ? maxpos : i;
    }

    printf("\nEl empleado con el menor salario es %s con numero %d y salario %.2f.\n", employees[minpos].name, employees[minpos].num_employee, employees[minpos].salary);
    printf("\nEl empleado con el mayor salario es %s con numero %d y salario %.2f.\n", employees[maxpos].name, employees[maxpos].num_employee, employees[maxpos].salary);

}

int numDept(DepartmentData* deptData, const char* deptName, int numDepartments) {
    for (int numDept = 0; numDept < numDepartments; ++numDept) {

    }
}

