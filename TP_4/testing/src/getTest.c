#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void getTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void getTest01(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);
    list = ll_newLinkedList();
    ll_add(list,pElement2);
    pElement = ll_get(list,0);
    utest_assertNotNullMsg(pElement,"\nError en el valor de retorno de <get> si los parametros son correctos\n y la lista tiene elementos la funcion retorna el puntero al elemento\n");

}


void getTest02(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);

    list = ll_newLinkedList();
    ll_add(list,pElement2);
    pElement = ll_get(list,0);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <get> al solicitar el primer elemento\n");

}

void getTest03(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);

    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_add(list,pElement2);
    pElement = ll_get(list,1);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <getNode> al solicitar el ultimo elemento\n");
}

void getTest04(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);

    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_add(list,pElement2);
    pElement = ll_get(list,-1);
    utest_assertNullMsg(pElement, "\nError en el valor de retorno de <get> al solicitar un elemento fuera de indice (< 0),\n se deberia retornar NULL\n");
    pElement = ll_get(list,2);
    utest_assertNullMsg(pElement, "\nError en el valor de retorno de <get> al solicitar un elemento fuera de indice (>= ll_len),\n se deberia retornar NULL\n");
}

void getTest05(void)
{

    utest_assertNullMsg(ll_get(NULL,0),"\nError en el valor de retorno de <get> si la lista pasada es NULL\n el valor a retornar es NULL\n");
}


