#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void deleteLinkedListTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void deleteLinkedListTest01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_deleteLinkedList(list);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <deleteLinkedList> si los parametros son correctos es 0\n");
}


void deleteLinkedListTest02(void)
{
    int r;
    r = ll_deleteLinkedList(NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <deleteLinkedList> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}




