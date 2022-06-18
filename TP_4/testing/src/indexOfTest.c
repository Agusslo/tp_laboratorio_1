#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void indexOfTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void indexOfTest01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_indexOf(list,NULL);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <indexOf> si los parametros son correctos y \nel elemento esta contenido se debe retornar la posicion del elemento\n");
    r = ll_indexOf(list,(void*)1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <indexOf> si los parametros son correctos y \nel elemento NO esta contenido se debe retornar -1\n");
}

void indexOfTest02(void)
{
    int r;
    r = ll_indexOf(NULL,0);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <indexOf> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
