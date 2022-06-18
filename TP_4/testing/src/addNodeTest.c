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

void addNodeTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void addNodeTest01(void)
{
    LinkedList* list;

    list = ll_newLinkedList();
    test_addNode(list,0,NULL);
    utest_assertEqualsIntMsg(1,list->size,"\nError en el valor de size de la lista se debe incrementar al agregar nodos\n");

}

void addNodeTest02(void)
{
    int i,r;
    LinkedList* list;
    Employee* pAux[LENGTH];
    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        r = test_addNode(list,list->size,pAux[i]);
        utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <addNode> si se agrego un nodo correctamente\n el valor a retornar es (0)\n");
    }

}

void addNodeTest03(void)
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
        test_addNode(list,list->size,pAux[i]);
    }

    for (i=0;i < LENGTH;i++)
    {
        nodoAux = test_getNode(list,i);
        utest_assertNotNullMsg(nodoAux,"\nExiste un error al intentar obtener el nodo.\n El valor de retorno no puede ser NULL\n");
        sprintf(msg,"\nError en el valor de retorno de <getNode> al solicitar el elemento en la  posicion %i\n",i);
        utest_assertEqualsPointerMsg(nodoAux->pElement,pAux[i],msg);
    }

}


void addNodeTest04(void)
{
    int r;
    r = test_addNode(NULL,0,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <addNode> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}

void addNodeTest05(void)
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
        test_addNode(list,list->size,pAux[i]);
    }

    Employee* other = newEmployee(99,"99","99",99,99);
    test_addNode(list,0,other);

    nodoAux = test_getNode(list,0);
    utest_assertNotNullMsg(nodoAux,"\nExiste un error al intentar obtener el nodo.\n El valor de retorno no puede ser NULL\n");
    utest_assertEqualsPointerMsg(nodoAux->pElement,other,"El puntero al employee agregado en la pos 0 no corresponde\n");

    for (i=0;i < LENGTH;i++)
    {
        nodoAux = test_getNode(list,i+1);
        utest_assertNotNullMsg(nodoAux,"\nExiste un error al intentar obtener el nodo.\n El valor de retorno no puede ser NULL\n");
        sprintf(msg,"\nError en el valor de retorno de <getNode> al solicitar el elemento en la  posicion %i\n",i);
        utest_assertEqualsPointerMsg(nodoAux->pElement,pAux[i],msg);
    }
}
