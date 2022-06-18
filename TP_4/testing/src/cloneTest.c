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


void cloneTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void cloneTest01(void)
{
    LinkedList* list;

    list = ll_newLinkedList();
    ll_add(list,NULL);

    utest_assertNotNullMsg(ll_clone(list),"\nError en el valor de retorno de <clone> si los parametros son correctos\nno debe retornar NULL\n");

}

void cloneTest02(void)
{
    int i;
    LinkedList* list;
    LinkedList* pSubList;
    Employee* pAux[LENGTH];
    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    pSubList = ll_clone(list);

    for(i=0; i < LENGTH; i++)
    {
        utest_assertEqualsPointerMsg(ll_get(pSubList,i),ll_get(list,i),"Error: la lista clonada difiere de la original");
    }
}


void cloneTest03(void)
{
    int i;
    LinkedList* list;
    LinkedList* pSubList;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    pSubList = ll_clone(NULL);
    utest_assertNullMsg(pSubList,"\nError en el valor de retorno de <clone> si la lista pasada es NULL\n el valor a retornar es (NULL)\n");
}
