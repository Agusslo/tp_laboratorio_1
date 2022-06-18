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

void addTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void addTest01(void)
{
    LinkedList* list;

    list = ll_newLinkedList();
    ll_add(list,NULL);
    utest_assertEqualsIntMsg(1,list->size,"\nError en el valor de size de la lista se debe incrementar al agregar elementos\n");
}

void addTest02(void)
{
    int i,r;
    LinkedList* list;
    Employee* pAux[LENGTH];
    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        r = ll_add(list,pAux[i]);
        utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <add> si se agrego un elemento correctamente\nel valor a retornar es (0)\n");
    }

}

void addTest03(void)
{
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];
    Node* nodoAux;
    char msg[256];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    for (i=0;i < LENGTH;i++)
    {
        nodoAux = test_getNode(list,i);
        utest_assertNotNullMsg(nodoAux,"\nExiste un error al intentar obtener el nodo.\nEl valor de retorno no puede ser NULL\n");
        sprintf(msg,"\nError en el valor de retorno de al solicitar el elemento en la  posicion %i\n",i);
        utest_assertEqualsPointerMsg(nodoAux->pElement,pAux[i],msg);
    }

}


void addTest04(void)
{
    int r;
    r = ll_add(NULL,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <add> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
