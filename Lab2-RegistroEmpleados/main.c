#include <stdio.h>
#include "empleados.h"

void show_menu(Employee** departments, DepartmentData* deptData, int numDepartments) {
    int option = -1;

    //posible empleado a agregar, o simplemente la estructura para guardar datos
    Employee employee;

    do {
        printf("\nMenu de empleados");
        printf("\n1. Agregar empleado");
        printf("\n2. Ver todos los empleados");
        printf("\n3. Ver empleados de un departamento.")
        printf("\n4. Buscar empleado");
        printf("\n5. Modificar empleado");
        printf("\n6. Borrar empleado");
        printf("\n7. Salir\n:");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            askForNameNumberAndOrSalaryAndOrDept(&employee, true, true, true, true);
            addEmployee(employee, employees, numEmployees, actualCapacity);
            break;
        case 2:
            showAllEmployees(departments, deptData, numDepartments);
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
    } while (option != 7);
}

int main(int argc, char* argv[]) {
    //Matriz de empleados
    if (argc < 2) {
        printf("Uso: %s archivo_con_empleados.csv\n", argv[0]);
        return 1;
    }

    Employee** departments;
    DepartmentData* deptData;
    int numDepartments = 0;

    getFromCSV(argv[1], &departments, &deptData, &numDepartments);

    // for (int i = 0; i < numDepartments; ++i) {
    //     printf("%s %d %d %d\n", deptData[i].name, deptData[i].deptNum, deptData[i].capacity, deptData[i].numEmployees);
    // }

    show_menu(departments, deptData, numDepartments);
    freeDepartments(departments, numDepartments);
    freeData(deptData);

    return 0;
}


