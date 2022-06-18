#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"
#define LENGTH 5

static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};

void containsTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void containsTest01(void)
{
    int r;
    LinkedList* list;

    list = ll_newLinkedList();
    r = ll_contains(list,NULL);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <contains> si los parametros son correctos\n debe retornar 0 o 1\n");
}


void containsTest02(void)
{
    int i, r;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_contains(list,NULL);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <contains> si los parametros\n son correctos y NO contiene el elemento debe retornar 0\n");
    for(i=0; i < LENGTH; i++)
    {
        r = ll_contains(list,pAux[i]);
        utest_assertEqualsIntMsg(r,1,"\nError en el valor de retorno de <contains> si los parametros\n son correctos y contiene el elemento debe retornar 1\n");
    }

}

void containsTest03(void)
{

    utest_assertEqualsIntMsg(ll_contains(NULL,NULL),-1,"\nError en el valor de retorno de <contains> si la lista pasada es NULL\n el valor a retornar es -1\n");
}


