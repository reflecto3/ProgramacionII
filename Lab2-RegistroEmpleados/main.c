#include <stdio.h>
#include "empleados.h"

void show_menu(Employee** departments, DeptData* deptData, int numDepartments, const char* filename) {
    int option = -1;

    //posible empleado a agregar, o simplemente la estructura para guardar datos
    Employee employee;
    int numDept;

    do {
        printf("\nMenu de empleados");
        printf("\n1. Agregar empleado");
        printf("\n2. Ver todos los empleados");
        printf("\n3. Ver empleados de un departamento.");
        printf("\n4. Buscar empleado");
        printf("\n5. Modificar empleado");
        printf("\n6. Borrar empleado");
        printf("\n7. Guardar y salir");
        printf("\n8. Salir sin guardar\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            askNameNumSalDept(&employee, true, true, true, true);
            numDept = getNumDept(deptData, employee.dept, numDepartments);
            if (numDept == -1) {
                printf("Departamento invalido.");
            }
            else {
                addEmployee(employee, &departments[numDept], &deptData[numDept].numEmployees, &deptData[numDept].capacity);
            }
            break;
        case 2:
            showAllEmployees(departments, deptData, numDepartments);
            break;
        case 3:
            askNameNumSalDept(&employee, false, false, false, true);
            numDept = getNumDept(deptData, employee.dept, numDepartments);
            if (numDept == -1) {
                printf("Departamento invalido.");
            }
            else {
                viewDepartment(departments, deptData, numDept);
            }
            break;
        case 4:
            askNameNumSalDept(&employee, false, true, false, false);
            searchAndShowEmployee(departments, employee.num_employee, deptData, numDepartments);
            break;
        case 5:
            askNameNumSalDept(&employee, false, true, false, false);
            askNameNumSalDept(&employee, true, false, true, true);
            modifyEmployee(employee, departments, deptData, numDepartments);
            break;
        case 6:
            askNameNumSalDept(&employee, false, true, false, false);
            deleteEmployee(departments, employee.num_employee, deptData, numDepartments);
            break;
        case 7:
            saveToCSV(filename, departments, deptData, numDepartments);
            printf("Guardando y saliendo del programa\n");
            break;
        case 8:
            printf("Saliendo sin guardar");
            break;
        default:
            printf("Opción no válida\n");
            break;
        }
    } while (option < 7);
}

int main(int argc, char* argv[]) {
    //Matriz de empleados
    if (argc < 2) {
        printf("Uso: %s archivo_con_empleados.csv\n", argv[0]);
        return 1;
    }

    Employee** departments;
    DeptData* deptData;
    int numDepartments = 0;

    getFromCSV(argv[1], &departments, &deptData, &numDepartments);


    show_menu(departments, deptData, numDepartments, argv[1]);
    freeDepartments(departments, numDepartments);
    freeData(deptData);

    return 0;
}


