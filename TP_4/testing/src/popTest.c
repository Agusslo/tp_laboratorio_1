#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void popTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void popTest01(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);
    list = ll_newLinkedList();
    ll_add(list,pElement2);
    pElement = ll_pop(list,0);
    utest_assertNotNullMsg(pElement,"\nError en el valor de retorno de <pop> si los parametros son correctos\n y la lista tiene el elemento solitado la funcion retorna el puntero al elemento\n");

}


void popTest02(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);

    list = ll_newLinkedList();
    ll_add(list,pElement2);
    pElement = ll_pop(list,0);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <pop> al solicitar el primer elemento\n");
    utest_assertEqualsIntMsg(ll_len(list),0,"\nError en el len() de la lista luego de quitar un elemento");
}

void popTest03(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);

    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_add(list,pElement2);
    pElement = ll_pop(list,1);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <pop> al solicitar el ultimo elemento\n");
    utest_assertEqualsIntMsg(ll_len(list),1,"\nError en el len() de la lista luego de quitar un elemento");
}

void popTest04(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);

    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_add(list,pElement2);
    pElement = ll_pop(list,-1);
    utest_assertNullMsg(pElement, "\nError en el valor de retorno de <pop> al solicitar un elemento fuera de indice (< 0),\n se deberia retornar NULL\n");
    pElement = ll_pop(list,2);
    utest_assertNullMsg(pElement, "\nError en el valor de retorno de <pop> al solicitar un elemento fuera de indice (>= ll_len),\n se deberia retornar NULL\n");
}

void popTest05(void)
{

    utest_assertNullMsg(ll_get(NULL,0),"\nError en el valor de retorno de <get> si la lista pasada es NULL\n el valor a retornar es NULL\n");
}

