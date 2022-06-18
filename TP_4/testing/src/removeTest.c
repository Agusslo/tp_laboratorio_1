#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void removeTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void removeTest01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_remove(list,0);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <remove> si los parametros son correctos es 0\n");
}


void removeTest02(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);
    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_add(list,NULL);
    ll_add(list,pElement2);
    ll_remove(list,1);
    pElement = ll_get(list,1);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <get> al solicitar \nun elemento luego de eliminar su antecesor\n");
    utest_assertEqualsIntMsg(ll_len(list),2,"\nError en el len() de la lista luego de quitar un elemento");
}

void removeTest03(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_remove(list,-1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <remove> al intentar eliminar un elemento fuera de indice (< 0),\n se deberia retornar -1\n");
    r = ll_remove(list,1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <remove> al intentar eliminar un elemento fuera de indice (>= ll_len),\n se deberia retornar -1\n");
}

void removeTest04(void)
{
    int r;
    r = ll_remove(NULL,0);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <remove> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}

void removeTest05(void)
{
    LinkedList* list;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_remove(list,0);

    utest_assertEqualsPointerMsg(list->pFirstNode,NULL,"\nEl valor de pFirsNode luego de quitar el ultimo elemento debe ser NULL\n");

}
