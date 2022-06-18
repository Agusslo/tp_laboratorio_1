#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"
#define LENGTH 6

static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1001,2000,1002,3000,4000,8000};
static float salarySortedUp[] = {8000,4000,3000,2000,1002,1001};
static int id[] = {11,20,3,4,9,99};


void sortTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void sortTest01(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_sort(list, compareEmployee,1);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <sort> si los parametros son correctos\n la funcion retorna 0\n");

}


void sortTest02(void)
{
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxGet[LENGTH];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    ll_sort(list, compareEmployee,0);

    for(i=0; i < LENGTH; i++)
    {
        pAuxGet[i] = ll_get(list,i);
        utest_assertNotNullMsg(pAuxGet[i],"Error al intentar obtener un elemento luego de ordenar");
        utest_assertEqualsFloatMsg(((Employee*)pAuxGet[i])->salary,salarySortedUp[i],"El orden de la lista es incorrecto");
    }

}
void sortTest03(void)
{
    int r;
    r = ll_sort(NULL, compareEmployee,1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <sort> si el puntero a la lista es NULL\n la funcion retorna -1\n");

}


void sortTest04(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_sort(list, NULL,1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <sort> si el puntero a la funcion criterio es NULL\n la funcion sort retorna -1\n");

}

void sortTest05(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_sort(list, compareEmployee,-1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <sort> si el orden es distinto de 1 o 0\n la funcion sort retorna -1\n");

}
