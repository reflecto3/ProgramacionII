#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <stdbool.h>

// uso de stringification. Ver https://gcc.gnu.org/onlinedocs/gcc-4.8.5/cpp/Stringification.html
#define xSTR(s) STR(s)
#define STR(s) #s

#define MAX_EMPLOYEE 100
#define MAX_NAME 30
#define INITIAL_CAPACITY 50

typedef struct {

    char name[MAX_NAME];
    int num_employee;
    float salary;

} Employee;


void addEmployee(Employee employee, Employee **employees, int *numEmployees, int *actualCapacity);
void viewEmployees(Employee *employees, int numEmployees);
void searchAndShowEmployee(Employee *employees, int numToShow, int numEmployees);
void initializeEmployees(Employee **employees);
void checkMemAlloc(Employee *employees);
bool isValidEmployee(Employee* employees, Employee employee, int numEmployees, bool checkRepeated);
void checkCapacity(Employee** employees, int numEmployees, int* actualCapacity);
void showEmployee(Employee employee);
void modifyEmployee(Employee modified, Employee *employees, int numEmployees);
int indexSearchEmployee(Employee *employees, int numEmployeeSearched, int numEmployees);
void deleteEmployee(Employee *employees, int numToDelete, int *numEmployees);
void freeEmployees(Employee* employees);
void askForNameNumberAndOrSalary(Employee *employee, bool name, bool number, bool salary);
void getFromFile(const char* filename, Employee** employees, int *numEmployees, int *actualCapacity);
void printAvgSalary(Employee* employees, int numEmployees);
void printMaxMinSalaries(Employee* employees, int numEmployees);

#endif