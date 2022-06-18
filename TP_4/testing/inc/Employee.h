#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;
#endif

int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(Employee* p);
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector);


